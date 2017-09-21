#include "Game.h"
#include "GameGlobal.h"
#include "Sprite.h"

Sprite *sprite;

bool direction;

Game::Game(int fps)
{
	mFPS = fps;

	sprite = new Sprite("gach.png");
	sprite->SetPosition(0 + sprite->GetWidth (  )/2, GameGlobal::GetHeight (  )/2);

	InitLoop();
}

Game::~Game()
{

}

void Game::Update(float dt)
{


	if(sprite->GetPosition (  ).x < 0)
	{
		direction = true;
	}

	if(sprite->GetPosition (  ).x > GameGlobal::GetWidth (  ))
	{
		direction = false;
	}

	float x;
	if(direction)
	{

		x = sprite->GetPosition().x + 100 * dt;
	}
	else
	{
		x = sprite->GetPosition().x - 100 * dt;

	}


	float y = sin(x / (GameGlobal::GetWidth()/16))*GameGlobal::GetHeight (  )/2 + GameGlobal::GetHeight (  )/2;
	sprite->SetPosition(x, y);

	Render();
}

void Game::Render()
{
	auto device = GameGlobal::GetCurrentDevice();

	device->Clear(0, NULL, D3DCLEAR_TARGET, 0xffff00, 0.0f, 0);

	{
		device->BeginScene();

		//bat dau ve
		GameGlobal::GetCurrentSpriteHandler()->Begin(D3DXSPRITE_ALPHABLEND);

		//draw here
		sprite->Draw();

		//ket thuc ve
		GameGlobal::GetCurrentSpriteHandler()->End();

		device->EndScene();
	}

	device->Present(0, 0, 0, 0);
}

void Game::InitLoop()
{
	MSG msg;

	float tickPerFrame = 1.0f / mFPS, delta = 0;

	while (GameGlobal::isGameRunning)
	{
		GameTime::GetInstance()->StartCounter();

		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}

		delta += GameTime::GetInstance()->GetCouter();

		if (delta >= tickPerFrame)
		{
			Update((delta));
			delta = 0;
		}
		else
		{
			Sleep(tickPerFrame - delta);
			delta = tickPerFrame;
		}
	}
}