#pragma once
#include "macros.h"
#include "Events.h"

_HANDLER_START
#ifdef _WNDGUI

class ViewBase;

class HANDLER_API Window
{
public:
	HWND GetWindowHandle() const;
	const std::wstring& GetWindowName() const;
	int GetClientWidth() const;
	int GetClientHeight() const;

	void Destroy();
	void Show();
	void Hide();

protected:
	// The Window procedure needs to call protected methods of this class.
	friend LRESULT CALLBACK WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam);

	// Only the application can create a window.
	friend class Application;
	// The CLIENT class needs to register itself with a window.
	friend class View;

	Window() = delete;
	Window(HWND hWnd,
		   const std::wstring& windowName,
		   int clientWidth,
		   int clientHeight);

	virtual ~Window();

	// Register a CLIENT with this window. This allows
	// the window to callback functions in the CLIENT class.
	void RegisterCallbacks(std::shared_ptr<ViewBase> pView);

	// Update and Draw can only be called by the application.
	virtual void OnUpdate(UpdateEventArgs& e);
	virtual void OnRender(RenderEventArgs& e);

	// A keyboard key was pressed
	virtual void OnKeyPressed(KeyEventArgs& e);
	// A keyboard key was released
	virtual void OnKeyReleased(KeyEventArgs& e);

	// The mouse was moved
	virtual void OnMouseMoved(MouseMotionEventArgs& e);
	// A button on the mouse was pressed
	virtual void OnMouseButtonPressed(MouseButtonEventArgs& e);
	// A button on the mouse was released
	virtual void OnMouseButtonReleased(MouseButtonEventArgs& e);
	// The mouse wheel was moved.
	virtual void OnMouseWheel(MouseWheelEventArgs& e);

	// The window was resized.
	virtual void OnResize(ResizeEventArgs& e);

private:
	Window(const Window& copy) = delete;
	Window& operator=(const Window& other) = delete;

	HWND				m_hWnd;
	std::wstring		m_WindowName;
	int					m_ClientWidth;
	int					m_ClientHeight;

	std::weak_ptr<ViewBase> m_pView;

	RECT m_WindowRect;
};
#endif
_HANDLER_END