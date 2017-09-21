#ifndef __SPRITE__
#define __SPRITE__
#include <d3d9.h>
#include <d3dx9.h>

#include "GameGlobal.h"

class Sprite
{
public:
	Sprite(const char* filePath, RECT sourceRect = RECT(), int width = NULL, int height = NULL, D3DCOLOR colorKey = NULL);

	Sprite();

	~Sprite();

	LPDIRECT3DTEXTURE9 GetTexture();

	//void Draw();
	void Draw(D3DXVECTOR3 position = D3DXVECTOR3(), RECT sourceRect = RECT());

	void SetWidth(int width);
	int GetWidth();

	void SetHeight(int height);
	int GetHeight();

	D3DXIMAGE_INFO GetImageInfo(); // lay thong tin thuc cua hinh anh duoc lay

	D3DXVECTOR3 GetPosition();
	void SetPosition(D3DXVECTOR3 pos);
	void SetPosition(float x, float y);
	void SetPosition(D3DXVECTOR2 pos);

	void SetSourceRect(RECT rect);

protected:
	//su dung cho ke thua
	void InitWithSprite(const char* filePath, RECT sourceRect = RECT(), int width = NULL, int height = NULL, D3DCOLOR colorKey = NULL);

	bool isRect(RECT rect);

	D3DXVECTOR3             mPosition; // vi tri cua Sprite, co goc la chinh giua hinh anh Texture
	LPDIRECT3DTEXTURE9      mTexture; // load hinh anh vao day
	LPD3DXSPRITE            mSpriteHandler; //SpriteHandler ho tro ve hinh
	D3DXIMAGE_INFO          mImageInfo; // thong tin thuc cua hinh anh duoc lay
	RECT                    mSourceRect; // hinh chu nhat cat tu anh cua texture

	int                     mWidth, mHeight; // kich thuoc cua texture

	D3DXMATRIX              mMatrix; // ma tran cua Spite ho tro trong cac phep hinh hoc
};
#endif