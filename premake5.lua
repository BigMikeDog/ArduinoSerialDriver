workspace "ArduinoSerialDriver"
	architecture "x86_64"
	startproject "ArduinoSerialDriver"

	configurations
	{
		"Debug",
		"Release",
		"Dist" 
	}

	flags
	{
		"MultiProcessorCompile"
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
		"%{prj.name}/src/**.cpp",
		"%{prj.name}/vendor/SerialPort/include/**.hpp",
		"%{prj.name}/vendor/SerialPort/src/**.cpp"
	}

	includedirs
	{
		"%{prj.name}/src",
		"%{prj.name}/vendor/SerialPort/include",
		"%{prj.name}/vendor/spdlog/include"
	}

	filter "system:windows"
		systemversion "latest"

		postbuildcommands {
			("{COPY} %{prj.location}src/Core/InstructionSet.h ../ArduinoCode/sketch_serialReceiver/src")
		}

	filter "configurations:Debug"
		defines "ASD_DEBUG"
		runtime "Debug"
		symbols "on"

	filter "configurations:Release"
		defines "ASD_RELEASE"
		runtime "Release"
		symbols "on"

	filter "configurations:Dist"
		defines "ASD_DIST"
		runtime "Release"
		symbols "on"