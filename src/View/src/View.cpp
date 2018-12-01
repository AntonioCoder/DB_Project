//#define _WNDGUI
#include <Handler.h>
#include <Log.h>
#include <SQLConnection.h>

class View : public _HANDLER Application
{
public: 
	View()
	{
	    LOG_TRACE("View Initialised");
		LOG_TRACE("Establishong SQL connection");
		_SQLC SQLConnection connection;
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