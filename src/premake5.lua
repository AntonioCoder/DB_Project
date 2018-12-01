workspace "DBProject"
    architecture "x64"

    configurations {
        "Debug",
        "Release",
        "Dist"
    }

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"



project "LogL"
    location "LogL"
    kind "SharedLib"
    language "C++"

    targetdir ("bin/" .. outputdir .. "/DBProject") 
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}") 

    files {
        "%{prj.name}/inc/**.h",
        "%{prj.name}/src/**.cpp"
    }

    pchheader "LOGpch.h"
    pchsource "LOGpch.cpp"

    includedirs {
        "%{prj.name}/vendor/spdlog/include",
        "%{prj.name}/inc",
        "."
    }

    filter "system:windows"
        cppdialect "C++17"
        staticruntime "On"
        systemversion "latest"

        defines {
            "_PLATFORM_WINDOWS",
            "_BUILD_DLL"
        }

    filter "configurations:Debug"
        defines "_DEBUG"
        symbols "On"

    filter "configurations:Release"
        defines "_RELEASE"
        optimize "On"
        
    filter "configurations:Dist"
        defines "_DIST"
        optimize "On"



project "Handler"
    location "Handler"
    kind "SharedLib"
    language "C++"

    targetdir ("bin/" .. outputdir .. "/DBProject") 
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}") 

    files {
        "%{prj.name}/inc/**.h",
        "%{prj.name}/src/**.cpp"
    }

    pchheader "WNDpch.h"
    pchsource "WNDpch.cpp"

    includedirs {
        "%{prj.name}/inc",
        "LogL/inc",
        "."
    }

    filter "system:windows"
        cppdialect "C++17"
        staticruntime "On"
        systemversion "latest"

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
        


project "SQLC"
    location "SQLC"
    kind "SharedLib"
    language "C++"

    targetdir ("bin/" .. outputdir .. "/DBProject") 
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}") 

    files {
        "%{prj.name}/inc/**.h",
        "%{prj.name}/src/**.cpp"
    }

    pchheader "SQLpch.h"
    pchsource "SQLpch.cpp"

    includedirs {
        "%{prj.name}/inc",
        "LogL/inc",
        "."
    }

    filter "system:windows"
        cppdialect "C++17"
        staticruntime "On"
        systemversion "latest"

        defines {
            "_PLATFORM_WINDOWS",
            "_BUILD_DLL"
        }

    filter "configurations:Debug"
        defines "_DEBUG"
        symbols "On"

    filter "configurations:Release"
        defines "_RELEASE"
        optimize "On"
        
    filter "configurations:Dist"
        defines "_DIST"
        optimize "On"



project "View"
        location "View"
        kind "ConsoleApp"
        language "C++"

        targetdir ("bin/" .. outputdir .. "/DBProject") 
        objdir ("bin-int/" .. outputdir .. "/%{prj.name}") 
    
        files {
            "%{prj.name}/src/**.h",
            "%{prj.name}/src/**.cpp"
        }
    
        includedirs {
            "LogL/vendor/spdlog/include/",
            "Handler/inc",
            "SQLC/inc",
            "LogL/inc"
        }

        links {
            "Handler",
            "SQLC",
            "LogL"
        }

    filter "system:windows"
        cppdialect "C++17"
        staticruntime "On"
        systemversion "latest"

        defines {
            "_PLATFORM_WINDOWS"
        }

    filter "configurations:Debug"
        defines "_DEBUG"
        symbols "On"

    filter "configurations:Release"
        defines "_RELEASE"
        optimize "On"
        
    filter "configurations:Dist"
        defines "_DIST"
        optimize "On"