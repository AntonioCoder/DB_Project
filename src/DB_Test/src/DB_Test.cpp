#include <Handler.h>

class Test : public _HANDLER Application
{
public: 
	Test()
	{
		PrintInfo("TEST_MESSAGE");
	}
	~Test()
	{
	}

private:

};

_HANDLER Application* _HANDLER CreateApplication()
{
	return new Test();
}