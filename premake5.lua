workspace "Yue"
	architecture "x64"

	-- all target configurations for x64
	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}


-- different for each target platform
outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

--[[ YUE PROJECT ]]
project "Yue"
	location "Yue" -- folder location
	kind "SharedLib" -- DLL, not exe
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}") -- target bin dir
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}") -- intermediate bin dir

	-- all files to be included in project
	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	-- all outside dependencies included
	includedirs
	{
		"%{prj.name}/vendor/spdlog/include"
	}

	-- everything below applies to windows only
	filter "system:windows"
		cppdialect "C++20"
		staticruntime "On"
		systemversion "latest"
		buildoptions "/utf-8" -- for spdlog issues - test with other platforms

		defines
		{
			"YUE_PLATFORM_WINDOWS",
			"YUE_BUILD_DLL"
		}

		postbuildcommands
		{
			("{COPYFILE} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
		}

	filter "configurations:Debug"
		defines "YUE_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "YUE_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "YUE_DIST"
		optimize "On"


--[[ SANDBOX PROJECT ]]
project "Sandbox"
	location "Sandbox" -- folder location
	kind "ConsoleApp" -- exe
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}") -- target bin dir
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}") -- intermediate bin dir

	-- all files to be included in project
	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	-- all outside dependencies included
	includedirs
	{
		"Yue/vendor/spdlog/include",
		"Yue/src"
	}

	links
	{
		"Yue"
	}

	-- everything below applies to windows only
	filter "system:windows"
		cppdialect "C++20"
		staticruntime "On"
		systemversion "latest"
		buildoptions "/utf-8" -- for spdlog issues - test with other platforms

		defines
		{
			"YUE_PLATFORM_WINDOWS"
		}

	filter "configurations:Debug"
		defines "YUE_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "YUE_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "YUE_DIST"
		optimize "On"