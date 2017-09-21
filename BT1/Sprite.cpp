#include "Sprite.h"

Sprite::Sprite(const char* filePath, RECT sourceRect, int width, int height, D3DCOLOR colorKey)
{
	this->InitWithSprite(filePath, sourceRect, width, height, colorKey);
}

Sprite::Sprite()
{

}

Sprite::~Sprite()
{
	if (mTexture != NULL)
		mTexture->Release();
}

void Sprite::InitWithSprite(const char* filePath, RECT sourceRect, int width, int height, D3DCOLOR colorKey)
{
	HRESULT result;
	mSpriteHandler = GameGlobal::GetCurrentSpriteHandler();
	mPosition = D3DXVECTOR3(0, 0, 0);

	mSourceRect = sourceRect;

	D3DXGetImageInfoFromFileA(filePath, &mImageInfo);

	if (width == NULL)
	{
		if (!isRect(sourceRect))
			mWidth = mImageInfo.Width;
		else
			mWidth = sourceRect.right - sourceRect.left;
	}
	else
		mWidth = width;

	if (height == NULL)
	{
		if (!isRect(sourceRect))
			mHeight = mImageInfo.Height;
		else
			mHeight = sourceRect.bottom - sourceRect.top;
	}
	else
		mHeight = height;

	if (!isRect(sourceRect))
	{
		mSourceRect.left = 0;
		mSourceRect.right = mWidth;
		mSourceRect.top = 0;
		mSourceRect.bottom = mHeight;
	}

	LPDIRECT3DDEVICE9 device;
	mSpriteHandler->GetDevice(&device);

	D3DXCreateTextureFromFileExA(
		device,
		filePath,
		mImageInfo.Width,
		mImageInfo.Height,
		1,
		D3DUSAGE_DYNAMIC,
		D3DFMT_UNKNOWN,
		D3DPOOL_DEFAULT,
		D3DX_DEFAULT,
		D3DX_DEFAULT,
		colorKey,
		&mImageInfo,
		NULL,
		&mTexture);
}

bool Sprite::isRect(RECT rect)
{
	if (rect.left == rect.right)
		return false;

	if (rect.top == rect.bottom)
		return false;

	return true;
}

int Sprite::GetWidth()
{
	return mWidth;
}

int Sprite::GetHeight()
{
	return mHeight;
}

void Sprite::Draw(D3DXVECTOR3 position, RECT sourceRect)
{
	D3DXVECTOR3 inPosition = mPosition;
	RECT inSourceRect = mSourceRect;

	if (position != D3DXVECTOR3())
		inPosition = position;

	if (isRect(sourceRect))
		inSourceRect = sourceRect;

	D3DXVECTOR3 center = D3DXVECTOR3(mWidth / 2, mHeight / 2, 0);

	mSpriteHandler->Draw(mTexture,
		&inSourceRect,
		&center,
		&inPosition,
		D3DCOLOR_ARGB(255, 255, 255, 255)); // nhung pixel nao co mau trang se duoc to mau nay len
}

void Sprite::SetSourceRect(RECT rect)
{
	mSourceRect = rect;
}

LPDIRECT3DTEXTURE9 Sprite::GetTexture()
{
	return mTexture;
}

void Sprite::SetPosition(D3DXVECTOR3 pos)
{
	mPosition = pos;
}

void Sprite::SetPosition(float x, float y)
{
	mPosition = D3DXVECTOR3(x, y, 0);
}

void Sprite::SetPosition(D3DXVECTOR2 pos)
{
	this->SetPosition(pos.x, pos.y);
}

D3DXVECTOR3 Sprite::GetPosition()
{
	return mPosition;
}

D3DXIMAGE_INFO Sprite::GetImageInfo()
{
	return mImageInfo;
}

void Sprite::SetWidth(int width)
{
	mWidth = width;
}

void Sprite::SetHeight(int height)
{
	mHeight = height;
}