#include <windows.h>
#include "balls.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	CBalls rec(hInstance, "Ball game",GAME_SCREEN_RESOLUTION_800_600_24,0, 24);
	
	rec.Init();
	rec.Run();

	return 0;
}


