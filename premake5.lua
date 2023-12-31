workspace "MysticMesh"
    architecture "x64"
    startproject "Sandbox"

    configurations
    {
        "Debug",
        "Release",
        "Dist"
    }

    outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

    project "MysticMesh"
        location "MysticMesh"
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
            "%{prj.name}/src",
            "%{prj.name}/vendor/spdlog/include"
        }

        filter "system:windows"
            cppdialect "C++17"
            staticruntime "On"
            systemversion "latest"

            defines
            {
                "MM_PLATFORM_WINDOWS",
                "MM_BUILD_DLL"
            }

            postbuildcommands
            {
                ("{COPYDIR} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
            }

        
        filter "configurations:Debug"
            defines "MM_DEBUG"
            symbols "On"
        
        filter "configurations:Release"
            defines "MM_RELEASE"
            optimize "On"

        filter "configurations:Dist"
            defines "MM_DIST"
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
            "MysticMesh/vendor/spdlog/include",
            "MysticMesh/src"
        }

        links
        {
            "MysticMesh"
        }

        filter "system:windows"
            cppdialect "C++17"
            staticruntime "On"
            systemversion "latest"

            defines
            {
                "MM_PLATFORM_WINDOWS"
            }
        
        filter "configurations:Debug"
            defines "MM_DEBUG"
            symbols "On"
        
        filter "configurations:Release"
            defines "MM_RELEASE"
            optimize "On"

        filter "configurations:Dist"
            defines "MM_DIST"
            optimize "On"