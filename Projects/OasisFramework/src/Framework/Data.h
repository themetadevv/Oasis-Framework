#pragma once

#include <Core.h>
#include <oapch.h>

namespace OASFramework {
	namespace Data {

		struct ContextData {
			std::string Title;
			unsigned int Width, Height;

			ContextData(std::string title = "Oasis Framework", unsigned int width = 1366, unsigned int height = 768)
				: Title(title), Width(width), Height(height) {
			}
		};



	}
}