SDL2 = "C:/dev/resources/SDL2"

workspace "TicTacToe"
	architecture "x86"
	configurations {
		"Debug",
		"Release"
	}

	targetdir "build/bin/%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"
	objdir "build/obj/%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "TicTacToe"
	kind "ConsoleApp"
	language "C++"
	cppdialect "C++20"

	files {
		"src/**.h",
		"src/**.cpp"
	}

	includedirs {
		"src",
		"%{SDL2}/include"
	}

	libdirs {
		"%{SDL2}/lib/x86"
	}

	links {
		"SDL2.lib",
		"SDL2main.lib"
	}

	filter "system:windows"
		systemversion "latest"
		defines "PLATFORM_WINDOWS"

	filter "configurations:Debug"
		defines "DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "NDEBUG"
		optimize "On"
