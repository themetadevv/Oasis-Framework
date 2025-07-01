#pragma once

#include <GLFW/glfw3.h>
#include <Framework/Types.h>

namespace Platform {
	namespace Windows {
		class Context : public OASFramework::Interface::IContextManager {
		public:
			Context(const OASFramework::Data::ContextData& ctx_data);
			virtual ~Context();

			virtual void Initialize(const OASFramework::Data::ContextData& ctx_data) override;
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