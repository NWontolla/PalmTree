workspace "PalmTree"
    architecture "x64"

    configurations 
    {
        "Debug",
        "Release",
        "Dist"
    }

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "PalmTree"
    location "PalmTree"
    kind "SharedLib"
    language "C++"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

    files 
    {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp"
    }

    includedirs
    {
        "%{prj.name}/vendor/spdlog/include"
    }

    filter "system:windows"
        cppdialect "C++17"
        staticruntime "On"
        systemversion "10.0.22000.0"

        defines 
        {
            "PT_PLATFORM_WINDOWS",
            "PT_BUILD_DLL"
        }

        postbuildcommands
        {
            ("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/SandBox")
        }

    filter "configurations:Debug"
        defines "PT_DEBUG"
        symbols "On"

    filter "configurations:Release"
        defines "PT_RELEASE"
        optimize "On"

    filter "configurations:Dist"
        defines "PT_DIST"
        optimize "On"
    
project "Sandbox"
    location "Sandbox"
    kind "ConsoleApp"
    language "C++"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

    files 
    {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp"
    }

    includedirs
    {
        "PalmTree/vendor/spdlog/include",
        "PalmTree/src"
    }

    links
    {
        "PalmTree"
    }

    filter "system:windows"
        cppdialect "C++17"
        staticruntime "On"
        systemversion "10.0.22000.0"

        defines 
        {
            "PT_PLATFORM_WINDOWS"
        }

    filter "configurations:Debug"
        defines "PT_DEBUG"
        symbols "On"

    filter "configurations:Release"
        defines "PT_RELEASE"
        optimize "On"

    filter "configurations:Dist"
        defines "PT_DIST"
        optimize "On"