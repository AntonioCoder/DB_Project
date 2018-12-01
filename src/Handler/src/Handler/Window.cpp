#include "WNDpch.h"
#include "Window.h"
#include "Application.h"

_HANDLER_START
#ifdef _WNDGUI
//------------------------------------------------------------------------------------------------
Window::Window(HWND hWnd, const std::wstring & windowName, int clientWidth, int clientHeight)
	: m_hWnd(hWnd)
	, m_WindowName(windowName)
	, m_ClientWidth(clientWidth)
	, m_ClientHeight(clientHeight)
{
	Application& app = Application::Get();
}

//------------------------------------------------------------------------------------------------
Window::~Window()
{
	// Window should be destroyed with Application::DestroyWindow before
	// the window goes out of scope.
	assert(!m_hWnd && "Use Application::DestroyWindow before destruction.");
}

//------------------------------------------------------------------------------------------------
HWND Window::GetWindowHandle() const
{
	return m_hWnd;
}

//------------------------------------------------------------------------------------------------
const std::wstring& Window::GetWindowName() const
{
	return m_WindowName;
}

//------------------------------------------------------------------------------------------------
void Window::Show()
{
	::ShowWindow(m_hWnd, SW_SHOW);
}

//------------------------------------------------------------------------------------------------
void Window::Hide()
{
	::ShowWindow(m_hWnd, SW_HIDE);
}

//------------------------------------------------------------------------------------------------
void Window::Destroy()
{
	if (auto pView = m_pView.lock())
	{
		// Notify the registered game that the window is being destroyed.
		pView->OnWindowDestroy();
	}
	if (m_hWnd)
	{
		DestroyWindow(m_hWnd);
		m_hWnd = nullptr;
	}
}

//------------------------------------------------------------------------------------------------
int Window::GetClientWidth() const
{
	return m_ClientWidth;
}

//------------------------------------------------------------------------------------------------
int Window::GetClientHeight() const
{
	return m_ClientHeight;
}

//------------------------------------------------------------------------------------------------
void Window::RegisterCallbacks(std::shared_ptr<_HANDLER ViewBase> pView)
{
	m_pView = pView;
}

//------------------------------------------------------------------------------------------------
void Window::OnUpdate(UpdateEventArgs&)
{
	if (auto pView = m_pView.lock())
	{
		pView->OnUpdate();
	}
}

//------------------------------------------------------------------------------------------------
void Window::OnRender(RenderEventArgs&)
{
	if (auto pView = m_pView.lock())
	{
		pView->OnRender();
	}
}

//------------------------------------------------------------------------------------------------
void Window::OnKeyPressed(KeyEventArgs& e)
{
	if (auto pView = m_pView.lock())
	{
		pView->OnKeyPressed(e);
	}
}

//------------------------------------------------------------------------------------------------
void Window::OnKeyReleased(KeyEventArgs& e)
{
	if (auto pView = m_pView.lock())
	{
		pView->OnKeyReleased(e);
	}
}

//------------------------------------------------------------------------------------------------
// The mouse was moved
void Window::OnMouseMoved(MouseMotionEventArgs& e)
{
	if (auto pView = m_pView.lock())
	{
		pView->OnMouseMoved(e);
	}
}

//------------------------------------------------------------------------------------------------
// A button on the mouse was pressed
void Window::OnMouseButtonPressed(MouseButtonEventArgs& e)
{
	if (auto pView = m_pView.lock())
	{
		pView->OnMouseButtonPressed(e);
	}
}

//------------------------------------------------------------------------------------------------
// A button on the mouse was released
void Window::OnMouseButtonReleased(MouseButtonEventArgs& e)
{
	if (auto pView = m_pView.lock())
	{
		pView->OnMouseButtonReleased(e);
	}
}

//------------------------------------------------------------------------------------------------
// The mouse wheel was moved.
void Window::OnMouseWheel(MouseWheelEventArgs& e)
{
	if (auto pView = m_pView.lock())
	{
		pView->OnMouseWheel(e);
	}
}
#endif
_HANDLER_END