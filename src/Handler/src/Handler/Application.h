#pragma once

#include "macros.h"

_HANDLER_START
class H_API Application
{
public:
	Application();
	virtual ~Application();

	void Run();

private:

};

// To be defined in CLIENT
Application* CreateApplication();
_HANDLER_END
