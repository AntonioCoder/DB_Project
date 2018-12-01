//#define _WNDGUI
#include <Handler.h>

class View : public _HANDLER Application
{
public: 
	View()
	{
		H_TRACE("View Initialised");
	}
	~View()
	{
	}

private:

};

_HANDLER Application* _HANDLER CreateApplication()
{
	return new View();
}