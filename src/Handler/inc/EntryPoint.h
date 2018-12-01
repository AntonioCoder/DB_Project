#pragma once
#include "HANmacros.h"
#include "Application.h"
#include "Log.h"

#ifdef _PLATFORM_WINDOWS
extern _HANDLER Application* _HANDLER CreateApplication();

#ifndef _WNDGUI
int __cdecl wmain(int argc, wchar_t *argv[], wchar_t *envp[])
{
	_LOG Log::Init();
	LOG_CORE_WARN("INITIALISE LOG\n\t\t[WNDGUI IS NOT DEFINED]\n");
	LOG_CORE_TRACE("Starting in CONSOLE mode...");
	auto app = _HANDLER CreateApplication();
	app->Run();
	delete app;
}
#else
#include <shlwapi.h>

#include "ViewBase.h"
#define MAX_LOADSTRING 100

HINSTANCE hInst;                                // current instance
const wchar_t* windowClassName = L"HandleWindowClass";

int APIENTRY wWinMain(_In_	   HINSTANCE  hInstance,
					  _In_opt_ HINSTANCE  hPrevInstance,
					  _In_	   LPWSTR     lpCmdLine,
					  _In_	   int        nCmdShow)
{
	UNREFERENCED_PARAMETER(hPrevInstance);
	UNREFERENCED_PARAMETER(lpCmdLine);

	_HANDLER Log::Init();
	H_CORE_WARN("INITIALISE LOG:\n\t\t[WNDGUI IS DEFINED]\n");
	H_CORE_TRACE("Building Window...");

	
	int retCode = 0;

	// Set the working directory to the path of the executable.
	WCHAR path[MAX_PATH];
	HMODULE hModule = GetModuleHandleW(NULL);
	if (GetModuleFileNameW(hModule, path, MAX_PATH) > 0)
	{
		PathRemoveFileSpecW(path);
		SetCurrentDirectoryW(path);
	}

	_HANDLER Application::Create(hInstance);
	{
		std::shared_ptr<_HANDLER ViewBase> demo = std::make_shared<_HANDLER ViewBase>(L"View Window", 1280, 720);
		retCode = _HANDLER Application::Get().Run(demo);
	}
	_HANDLER Application::Destroy();

	return retCode;
}
#endif
#endif