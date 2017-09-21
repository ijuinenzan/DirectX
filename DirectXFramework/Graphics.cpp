#include "Graphics.h"

US_CV_FRAMEWORK


HRESULT Graphics::WinProc ( HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam )
{
	switch (msg)
	{
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hWnd, msg, wParam, lParam);
	}
}

Graphics::Graphics()
{
}


Graphics::Graphics ( HINSTANCE hInstance, LPCSTR className, int width, int height, int fps, int isFullScreen )
{
	_hInstance = hInstance;
	_windowClassName = className;

	_isFullScreen = isFullScreen;

	_width = width;
	_height = height;

	_fps = fps;
}

void Graphics::initWindow ( )
{
	WNDCLASSEX wc;
	wc.cbSize = sizeof(WNDCLASSEX);//

	wc.style = CS_HREDRAW | CS_VREDRAW;
	wc.hInstance = _hInstance;//

	wc.lpfnWndProc = WinProc;//
	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0;
	wc.hIcon = NULL;
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);
	wc.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	wc.lpszMenuName = NULL;
	wc.lpszClassName = _windowClassName;//
	wc.hIconSm = NULL;

	RegisterClassEx(&wc);

	/* --- Init window --- */
	DWORD style;
	if (this->_isFullScreen)
		style = WS_EX_TOPMOST | WS_VISIBLE | WS_POPUP;
	else
		style = WS_OVERLAPPEDWINDOW;

	_hWnd = CreateWindow(
		_windowClassName,
		_windowClassName,
		style,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		_width,
		_height,
		NULL,
		NULL,
		this->_hInstance,
		NULL);
	if (_hWnd == NULL)
	{
		throw;
	}

	/* --- Show and Update --- */
	ShowWindow(this->_hWnd, SW_SHOWNORMAL);
	UpdateWindow(this->_hWnd);
}

int Graphics::isFullScreen ( ) const
{
	return _isFullScreen;
}

int Graphics::getWidth ( ) const
{
	return _width;
}

int Graphics::getHeight ( ) const
{
	return _height;
}

int Graphics::getFrameRate ( ) const
{
	return _fps;
}

HWND Graphics::getWindow ( ) const
{
	return _hWnd;
}

HINSTANCE Graphics::getInstance ( ) const
{
	return _hInstance;
}

Graphics::~Graphics()
{
}
