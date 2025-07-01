workspace "OasisFramework"
	location "Projects"
	architecture "x64"

	configurations {
		"Debug",
		"Release",
		"Distribution"
	}

	startproject "Game1"

outputdir = "%{cfg.system}/%{cfg.buildcfg}"
build_dir = "bin/builds/" ..outputdir.. "/%{prj.name}"
intermediates_dir = "bin/intermediates/" ..outputdir.. "/%{prj.name}"
distributions_dir= "bin/distribution/"

IncludeDirectories = {}
IncludeDirectories["glfw"] = "Projects/OasisFramework/vendor/glfw/include"
IncludeDirectories["spdlog"] = "Projects/OasisFramework/vendor/spdlog/include"
IncludeDirectories["glm"] = "Projects/OasisFramework/vendor/glm"

include "Projects/OasisFramework/vendor/glfw"

-- ApplicationCoreDLL
project "OasisFramework"
	location "Projects/%{prj.name}" -- Create project inside this folder
	kind "SharedLib" -- DLL
	language "C++"
	staticruntime "Off"

	targetdir(build_dir) -- builds dir
	objdir(intermediates_dir) -- obj dir

	pchheader "oapch.h"
	pchsource "Projects/OasisFramework/src/oapch.cpp"

	files {
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.hpp",
		"%{prj.name}/src/**.cpp",
		"%{prj.name}/src/**.c",
	}

	includedirs {
		"Projects/%{prj.name}/src",
		"%{IncludeDirectories.glfw}",
		"%{IncludeDirectories.spdlog}",
		"%{IncludeDirectories.glm}"
	}

	links {
		"GLFW"
	}

	filter "system:windows" 
		cppdialect "C++20" -- C++ Version
		systemversion "latest" -- OS Version	
		buildoptions {
			"/utf-8"
		}

		defines {
			"OASIS_PLATFORM_WINDOWS",
			"OASIS_BUILD_DLL"
		}	
		
		filter "configurations:Debug" 
			defines "SBX_DEBUG"
			runtime "Debug"
			symbols "On"	

		filter "configurations:Release" 
			defines "SBX_RELEASE"
			runtime "Release"
			optimize "On"

		filter "configurations:Distribution" 
			defines "SBX_DISTRIBUTION"
			runtime "Release"
			optimize "On"

-- Game1
project "Game1"
	location "Projects/Games/Game1" -- Create project inside this folder
	kind "ConsoleApp" -- Executable
	language "C++"
	staticruntime "Off"

	targetdir(build_dir) -- builds dir
	objdir(intermediates_dir) -- obj dir

	files {
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.hpp",
		"%{prj.name}/src/**.cpp",
		"%{prj.name}/src/**.c",
	}

	includedirs {
		"Projects/OasisFramework/src",
		"%{IncludeDirectories.glfw}",
		"%{IncludeDirectories.spdlog}",
		"%{IncludeDirectories.glm}"
	}

	links {
		"OasisFramework",
		"GLFW"
	}

	filter "system:windows" 
		cppdialect "C++20" -- C++ Version
		systemversion "latest" -- OS Version	
		buildoptions {
			"/utf-8"
		}

		defines {
			"OASIS_PLATFORM_WINDOWS"
		}	
	
	filter "configurations:Debug" 
		defines "SBX_DEBUG"
		runtime "Debug"
		symbols "On"	

	filter "configurations:Release" 
		defines "SBX_RELEASE"
		runtime "Release"
		optimize "On"

	filter "configurations:Distribution" 
		defines "SBX_DISTRIBUTION"
		runtime "Release"
		optimize "On"