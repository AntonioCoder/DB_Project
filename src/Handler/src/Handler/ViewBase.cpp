#include "WNDpch.h"
#include "ViewBase.h"

#include "Application.h"
#include "Window.h"

_HANDLER_START
#ifdef _WNDGUI
ViewBase::ViewBase(const std::wstring& name, int width, int height, bool vSync)
	: m_Name(name)
	, m_Width(width)
	, m_Height(height)
	, m_vSync(vSync)
{
}

ViewBase::~ViewBase()
{
	assert(!m_pWindow && "Use Game::Destroy() before destruction.");
}

bool ViewBase::Initialize()
{
	// Check for DirectX Math library support.
	if (!DirectX::XMVerifyCPUSupport())
	{
		MessageBoxA(NULL, "Failed to verify DirectX Math library support.", "Error", MB_OK | MB_ICONERROR);
		return false;
	}

	m_pWindow = Application::Get().CreateRenderWindow(m_Name, m_Width, m_Height, m_vSync);
	m_pWindow->RegisterCallbacks(shared_from_this());
	m_pWindow->Show();

	return true;
}

void ViewBase::Destroy()
{
	Application::Get().DestroyWindow(m_pWindow);
	m_pWindow.reset();
}

void ViewBase::OnUpdate(UpdateEventArgs& e)
{

}

void ViewBase::OnRender(RenderEventArgs& e)
{

}

void ViewBase::OnKeyPressed(KeyEventArgs& e)
{
	// By default, do nothing.
}

void ViewBase::OnKeyReleased(KeyEventArgs& e)
{
	// By default, do nothing.
}

void ViewBase::OnMouseMoved(class MouseMotionEventArgs& e)
{
	// By default, do nothing.
}

void ViewBase::OnMouseButtonPressed(MouseButtonEventArgs& e)
{
	// By default, do nothing.
}

void ViewBase::OnMouseButtonReleased(MouseButtonEventArgs& e)
{
	// By default, do nothing.
}

void ViewBase::OnMouseWheel(MouseWheelEventArgs& e)
{
	// By default, do nothing.
}

void ViewBase::OnResize(ResizeEventArgs& e)
{
	m_Width = e.Width;
	m_Height = e.Height;
}

void ViewBase::OnWindowDestroy()
{
	// If the Window which we are registered to is 
	// destroyed, then any resources which are associated 
	// to the window must be released.
	UnloadContent();
}
#endif
_HANDLER_END
