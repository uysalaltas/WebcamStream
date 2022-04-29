workspace "WebcamStream"
	architecture "x64"
	startproject "WebcamStream"

	configurations
	{
		"Release"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

IncludeDir = {}

include "WebcamStream"