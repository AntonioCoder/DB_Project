#pragma once

#include "macros.h"

#ifdef _PLATFORM_WINDOWS
extern _HANDLER Application* _HANDLER CreateApplication();

int main(int argc, char** argv)
{
	_HANDLER Log::Init();
	H_CORE_WARN("INITIALISE LOG");

	auto app = _HANDLER CreateApplication();
	app->Run();
	delete app;
}
#endif