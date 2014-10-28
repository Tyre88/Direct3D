#ifndef GRAPHICSDEVICE_H
#define GRAPHICSDEVICE_H

// Direct 3D logic
#include <d3d9.h>

class GraphicsDevice
{
public:
	GraphicsDevice();
	~GraphicsDevice();

	//Direct 3D functions
	bool Initialize(HWND hWnd, bool windowed);
	void Clear(D3DCOLOR color);
	void Begin();
	void End();
	void Present();

	LPDIRECT3DDEVICE9 device;

private:
	LPDIRECT3D9 direct3d;
};

#endif /* GRAPHICSDEVICE_H */