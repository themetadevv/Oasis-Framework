
#include <Framework/Data.h>
#include <Framework/Interfaces/IContextManager.h>
#include <Framework/Logger.h>

#include "Platform/Windows/Context.h"

int main() {
	OASFramework::Logger::Initialize();
	
	//std::unique_ptr<AppCore::IContextManager> m_ApplicationWindow = std::unique_ptr<AppCore::IContextManager>(AppCore::IContextManager::CreateContext());

	OASFramework::Data::ContextData m_data = OASFramework::Data::ContextData();

	Platform::Windows::Context* m_ApplicationWindow = new Platform::Windows::Context(m_data);

	while (true)
	{
		m_ApplicationWindow->OnUpdate();
	}

	delete m_ApplicationWindow;

	std::cin.get();
}