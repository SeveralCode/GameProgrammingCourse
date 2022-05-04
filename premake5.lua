workspace "Game Programming Course"
    architecture "x86_64"
    configurations {"Debug", "Release"}
    targetdir "%{wks.location}/bin/%{cfg.buildcfg}-%{cfg.architecture}"
    objdir "%{wks.location}/int/%{cfg.buildcfg}-%{cfg.architecture}"
    includedirs {"%{wks.location}/ThirdParty/include"}
    libdirs {"%{wks.location}/ThirdParty/libs"}
    startproject "Sandbox"

    filter "configurations:Debug"
        defines "DEBUG"
        symbols "On"

    filter "configurations:Release"
        defines "RELEASE"
        optimize "On"

    project "Sandbox"
        kind "ConsoleApp"
        language "C++"
        cppdialect "C++17"
        location "%{wks.location}/Sandbox"

        files {
            "%{prj.location}/src/**.h",
            "%{prj.location}/src/**.cpp"
        }

        links {
            "sfml-system.lib",
            "sfml-main.lib",
            "sfml-window.lib",
            "sfml-graphics.lib",
            "sfml-audio.lib"
        }

    postbuildcommands "{COPY} %{wks.location}/ThirdParty/libs/*.dll %{wks.location}/bin/%{cfg.buildcfg}-%{cfg.architecture}"