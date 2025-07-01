#pragma once

#include <Framework/Data.h>
#include <Framework/Types.h>
#include <Framework/Logger.h>
#include <Framework/Interfaces/IContextManager.h>

#include <GLFW/glfw3.h>
#include <GLFW/glfw3native.h>

namespace OASFramework {
	namespace Platform {
		namespace Windows {
			class OAPI Context : public IContextManager {
			public:
				Context(const Data::ContextData& ctx_data);
				virtual ~Context();

				virtual void Initialize(const Data::ContextData& ctx_data) override;
				virtual void OnUpdate() override;
				virtual void Shutdown() override;

				inline virtual std::string GetName() const override {
					return m_Data.Title;
				}

				inline virtual unsigned int GetWidth() const override {
					return m_Data.Width;
				}

				inline virtual unsigned int GetHeight() const override {
					return m_Data.Height;
				}

				virtual inline void SetVSync(bool val) override {
					if (val)
						glfwSwapInterval(1);
					else
						glfwSwapInterval(0);

					m_Data.VSync = val;
				}

				virtual inline bool IsVSync() const override {
					return m_Data.VSync;
				}

			private:
				GLFWwindow* m_Window;

				struct WindowsContextData {
					std::string Title = "";
					unsigned int Width = 0U, Height = 0U;
					bool VSync = false;
					Color ClearColor = Color(255.0f, 0.f, 0.f, 255.0f);
				};

				WindowsContextData m_Data;
			};
		}
	}
}