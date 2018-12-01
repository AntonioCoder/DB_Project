workspace "DB_Project"
    architecture "x64"

    configurations {
        "Debug",
        "Release",
        "Dist"
    }

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "Handler"
    location "Handler"
    kind "SharedLib"
    language "C++"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}") 
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}") 

    files {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp"
    }

    pchheader "WNDpch.h"
    pchsource "WNDpch.cpp"

    includedirs {
        "%{prj.name}/vendor/spdlog/include",
        "."
    }

    filter "system:windows"
        cppdialect "C++17"
        staticruntime "On"
        systemversion "10.0.17763.0"

        defines {
            "_PLATFORM_WINDOWS",
            "_BUILD_DLL"
        }

    filter "configurations:Debug"
        defines "H_DEBUG"
        symbols "On"

    filter "configurations:Release"
        defines "H_RELEASE"
        optimize "On"
        
    filter "configurations:Dist"
        defines "H_DIST"
        optimize "On"

project "View"
        location "View"
        kind "ConsoleApp"
        language "C++"

        targetdir ("bin/" .. outputdir .. "/%{prj.name}") 
        objdir ("bin-int/" .. outputdir .. "/%{prj.name}") 
    
        files {
            "%{prj.name}/src/**.h",
            "%{prj.name}/src/**.cpp"
        }
    
        includedirs {
            "Handler/vendor/spdlog/include",
            "Handler/src"
        }

        links {
            "Handler"
        }

    filter "system:windows"
        cppdialect "C++17"
        staticruntime "On"
        systemversion "latest"

        defines {
            "_PLATFORM_WINDOWS"
        }

    filter "configurations:Debug"
        defines "H_DEBUG"
        symbols "On"

    filter "configurations:Release"
        defines "H_RELEASE"
        optimize "On"
        
    filter "configurations:Dist"
        defines "H_DIST"
        optimize "On"