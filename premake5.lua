workspace "ArduinoSerialDriver"
	architecture "x64"

	configurations
	{
		"Debug",
		"Release",
		"Dist" 
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "ArduinoSerialDriver"
	location "ArduinoSerialDriver"
	kind "ConsoleApp"
	language "C++"
	cppdialect "C++17"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"%{prj.name}/src",
		"%{prj.name}/vendor/SerialPort/include",
		"%{prj.name}/vendor/spdlog/include"
	}

	filter "system:windows"
		systemversion "latest"

	filter "configurations:Debug"
		defines "ASD_DEBUG"
		runtime "Debug"
		symbols "On"

	filter "configurations:Release"
		defines "ASD_RELEASE"
		runtime "Release"
		symbols "On"

	filter "configurations:Dist"
		defines "ASD_DIST"
		runtime "Release"
		symbols "On"