
#include <Core.h>
#include <oapch.h>



#include "Context.h"

namespace OASFramework {
	namespace Platform {
		namespace Windows {
			static bool s_bGlfwIntialized = false;

			static void ErrorCallback(int error_code, const char* description) {
				OA_CLIENT_ERROR("Error : {0}, {1}", error_code, description);
			}

			Context::Context(const OASFramework::Data::ContextData& ctx_data) :
				m_Window(nullptr)
			{
				Initialize(ctx_data);
			}

			Context::~Context() {
				Shutdown();
			}

			void Context::Initialize(const OASFramework::Data::ContextData& ctx_data) {
				m_Data.Title = ctx_data.Title;
				m_Data.Width = ctx_data.Width;
				m_Data.Height = ctx_data.Height;

				//OA_CORE_INFO("Created Context (T, W, H) : {0}, {1}, {2} ", GetName(), GetWidth(), GetHeight());

				if (!s_bGlfwIntialized) {
					int success = glfwInit();
					OA_CORE_ASSERT(success, "Failed to init GLFW!");

					glfwSetErrorCallback(ErrorCallback);

					s_bGlfwIntialized = true;
				}

				m_Window = glfwCreateWindow(m_Data.Width, m_Data.Height, m_Data.Title.c_str(), nullptr, nullptr);
				glfwMakeContextCurrent(m_Window);

				this->SetVSync(1);
			}

			void Context::OnUpdate() {
				glfwSwapBuffers(m_Window);
				glfwPollEvents();
			}

			void Context::Shutdown() {
				glfwDestroyWindow(m_Window);
			}
		}
	}
}