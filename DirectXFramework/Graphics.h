#ifndef __GRAPHICS_H__
#define __GRAPHICS_H__
#include "Definitions.h"

NS_CV_FRAMEWORK
NS_CV_FRAMEWORK_BEGIN

class Graphics
{
public:
	Graphics(HINSTANCE hInstance, LPCSTR className, int width, int height, int fps, int isFullScreen);
	~Graphics();

	void initWindow();

	int isFullScreen() const;
	int getWidth() const;
	int getHeight() const;
	int getFrameRate() const;
	HWND getWindow() const;
	HINSTANCE getInstance() const;
protected:
	HINSTANCE _hInstance;
	HWND _hWnd;

	LPCSTR _windowClassName;
	int _isFullScreen;

	int _width;
	int _height;
	int _fps;

	static HRESULT CALLBACK WinProc(HWND, UINT, WPARAM, LPARAM);
	Graphics();
};

typedef Graphics* pGraphics;

NS_CV_FRAMEWORK_END

#endif __GRAPHICS_H__
