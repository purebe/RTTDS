// RTTDS
// Date: 09/12/2013

#include <Windows.h>
#include "CApp.h"

int main(int argc, char **argv)
{
	// We can print errors to the console window
	// FreeConsole();

	CApp app;

	app.Startup();

	app.Run();

	app.Shutdown();

	;

	return 0;
}