#ifndef __GAME_H__
#define __GAME_H__

#include <windows.h>
#include "Graphics.h"
#include "DeviceManager.h"

NS_CV_FRAMEWORK
NS_CV_FRAMEWORK_BEGIN

class Game
{
public:
	virtual ~Game(void);

	static int isExit;

	Game(HINSTANCE, LPWSTR = "Window Game", int width = 800, int height = 600, int fps = 30, int isFullScreen = 0);

	void virtual init();						// init your objects
	void virtual release();						// release your objects

	void virtual updateInput(float deltatime);	// update input, include played objects and menu button
	void virtual update(float deltatime);		// update your objects
	void virtual draw();						// draw your objects
	void virtual loadResource();

	void run();
	void render();
	static void exit();			// exit the game. call: Game::exit()
	static Graphics* getWindow();

protected:
	pGraphics wnd_Instance;		// for init window. 
	//pGameTime _gametime;
	pDeviceManager _deviceManager;
	//pInputController _input;
	LPD3DXSPRITE _spriteHandle;
	static Graphics *hWindow;
private:
	float _frameRate;			// time for 1 frame, milisecond
	float _oldTime;
	float _deltaTime;
};

typedef Game* pGame;

NS_CV_FRAMEWORK_END

#endif //__GAME_H__