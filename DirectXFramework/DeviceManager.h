#ifndef __DEVICE_MANAGER_H__
#define __DEVICE_MANAGER_H__

#include "Definitions.h"
#include "Graphics.h"

NS_CV_FRAMEWORK
NS_CV_FRAMEWORK_BEGIN

class DeviceManager
{
public:
	~DeviceManager();
	static DeviceManager* getInstance();
	static void release();
	void clearScreen() const;
	void present() const;
	void init(Graphics);

	LPDIRECT3DDEVICE9 getDevice() const;
	LPDIRECT3DSURFACE9 getSurface() const;
private:
	static DeviceManager* _instance;
	LPDIRECT3D9 _pD3d;
	LPDIRECT3DDEVICE9 _pDevice;
	LPDIRECT3DSURFACE9 _surface;
	DeviceManager();
};

typedef  DeviceManager* pDeviceManager;

NS_CV_FRAMEWORK_END
#endif //__DEVICE_MANAGER_H__