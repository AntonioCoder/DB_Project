#pragma once
#include "HANmacros.h"

_HANDLER_START
#ifndef _WNDGUI
class HANDLER_API Application
{
public:
	inline Application()
	{
	}
	
	inline ~Application()
	{
	}

	void Run();

private:

};
#else
#include "Window.h"

class Window;
class ViewBase;

class HANDLER_API Application
{
public:
	static void Create(HINSTANCE hInst);
	static void Destroy();
	static Application& Get();

	std::shared_ptr<Window> CreateWindow(const std::wstring& windowName,
						 				 int clientWidth,
						 				 int clientHeight);


	void DestroyWindow(const std::wstring& windowName);
	void DestroyWindow(std::shared_ptr<Window> window);

	std::shared_ptr<Window> GetWindowByName(const std::wstring& windowName);

	int Run(std::shared_ptr<ViewBase> pView);
	
	void Quit(int exitCode = 0);

protected:
	Application(HINSTANCE hInst);
	virtual ~Application();

private:
	Application(const Application& copy) = delete;
	Application& operator=(const Application& other) = delete;

	HINSTANCE m_hInstance;
};
#endif

// To be defined in CLIENT
Application* CreateApplication();
_HANDLER_END
