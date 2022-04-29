project "WebcamStream"
	kind "ConsoleApp"
	language "C++"
	cppdialect "C++17"
	staticruntime "off"

	targetdir ("%{wks.location}/bin/" .. outputdir .. "/%{prj.name}")
	objdir ("%{wks.location}/bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"src/**.h",
		"src/**.cpp",
	}

	includedirs
	{
		"vendor/include"
	}
	
	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		-- filter "configurations:Debug"
		-- 	defines "HZ_DEBUG"
		-- 	runtime "Debug"
		-- 	symbols "on"

		-- 	libdirs 
		-- 	{ 
		-- 		"vendor/lib/opencv/debug_cv"
		-- 	}

		-- 	links 
		-- 	{ 
		-- 		"opencv_world455d"
		-- 	}

		-- 	postbuildcommands
		-- 	{
		-- 		-- ("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/UiApp")
		-- 		("{COPY} %{prj.location}/vendor/dll/opencv_world455d.dll %{cfg.targetdir}")
		-- 	}


		filter "configurations:Release"
			defines "HZ_RELEASE"
			runtime "Release"
			optimize "on"

			libdirs 
			{ 
				"vendor/lib/opencv/release_cv"
			}

			links 
			{ 
				"opencv_world455"
			}

			postbuildcommands
			{
				-- ("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/UiApp")
				("{COPY} %{prj.location}/vendor/dll/opencv_world455.dll %{cfg.targetdir}")
			}