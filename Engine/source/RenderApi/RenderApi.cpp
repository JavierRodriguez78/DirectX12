#include "pch.h"
#include "RenderApi.h"
#include "DirectX12/DXGI/DXGIFactory.h"
#include "DirectX12/DXGI/DXGIAdapter.h"


namespace Engine {

	RenderApi::~RenderApi()
	{
	}

	void RenderApi::Initialize(HWND hwnd)
	{

		DXGIFactory factory;
		DXGIAdapter adapter = factory.GetAdapter();
		
		DXGI_ADAPTER_DESC desc;
		adapter->GetDesc(&desc);

		PRINT_W_N("Selected device -> " << desc.Description);

		mDevice.Init(adapter.Get());
		mDevice->SetName(L"Main virutal device");

	}

}