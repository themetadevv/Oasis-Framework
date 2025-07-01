
#include <Framework/Data.h>
#include <Framework/Types.h>
#include <Framework/Logger.h>
#include <Platform/Windows/Context.h>

int main() {
	auto ApplicationWindowContext = new OASFramework::Platform::Windows::Context(OASFramework::Data::ContextData());

	while (true) {
		ApplicationWindowContext->OnUpdate();
	}

	delete ApplicationWindowContext;
}