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

    targetdir ("bin/" .. outputdir .. "/%{prj.name}") 
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}") 

    pchheader "LOGpch.h"
    pchsource "LogL/src/LOGpch.cpp"

    files {
        "%{prj.name}/inc/**.h",
        "%{prj.name}/src/**.cpp"
    }

    includedirs {
        "%{prj.name}/vendor/spdlog/include",
        "%{prj.name}/inc"
    }

    filter "system:windows"
        cppdialect "C++17"
        staticruntime "On"
        systemversion "latest"

        defines {
            "_PLATFORM_WINDOWS",
            "_BUILD_DLL"
        }

        postbuildcommands {
            ("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/View")
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

    targetdir ("bin/" .. outputdir .. "/%{prj.name}") 
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}") 
    
    pchheader "WNDpch.h"
    pchsource "Handler/src/WNDpch.cpp"

    files {
        "%{prj.name}/inc/**.h",
        "%{prj.name}/src/**.cpp"
    }


    includedirs {
        "%{prj.name}/inc",
        "LogL/inc"
    }

    links {
        "LogL"
    }

    filter "system:windows"
        cppdialect "C++17"
        staticruntime "On"
        systemversion "latest"

        defines {
            "_PLATFORM_WINDOWS",
            "_BUILD_DLL"
        }

        postbuildcommands {
            ("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/View")
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
        


project "SQLC"
    location "SQLC"
    kind "SharedLib"
    language "C++"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}") 
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}") 
    
    pchheader "SQLpch.h"
    pchsource "SQLC/src/SQLpch.cpp"

    files {
        "%{prj.name}/inc/**.h",
        "%{prj.name}/src/**.cpp"
    }

    includedirs {
        "LogL/vendor/spdlog/include",
        "%{prj.name}/inc",
        "LogL/inc"
    }

    links {
        "LogL"
    }

    filter "system:windows"
        cppdialect "C++17"
        staticruntime "On"
        systemversion "latest"

        defines {
            "_PLATFORM_WINDOWS",
            "_BUILD_DLL"
        }

        postbuildcommands {
            ("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/View")
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

        targetdir ("bin/" .. outputdir .. "/%{prj.name}") 
        objdir ("bin-int/" .. outputdir .. "/%{prj.name}") 
    
        files {
            "%{prj.name}/src/**.h",
            "%{prj.name}/src/**.cpp"
        }
    
        includedirs {
            "LogL/vendor/spdlog/include",
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