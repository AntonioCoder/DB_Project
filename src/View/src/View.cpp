//#define _WNDGUI
#include <Handler.h>
#include <Log.h>
#include <SQLConnection.h>

#include "info.h"

class View : public _HANDLER Application
{
public: 
	View()
		: m_connection(EstablishODNCConnection(CONNECTION_STR))
	{
	    LOG_TRACE("View Initialised");
		LOG_TRACE("Establishong SQL connection");
		if (m_connection.Connect())
		{
			LOG_CORE_INFO("Connected");
		} else {
			LOG_CORE_ERROR("FAILED TO CONNECT");
		}

	}
	~View()
	{
	}

	void Run() override;

protected:
	_SQLC SQLConnection EstablishODNCConnection(SQLWCHAR* pwszConnStr)
	{
		return _SQLC SQLConnection::SQLConnection(pwszConnStr);
	}

private:
	_SQLC SQLConnection m_connection;
};

#define SQL_QUERY_SIZE 200

void View::Run()
{
	m_connection.Run();
}



_HANDLER Application* _HANDLER CreateApplication()
{
	return new View();
}