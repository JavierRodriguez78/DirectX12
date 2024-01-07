#include "pch.h"
#include "DXGIFactory.h"
#include "DXGIAdapter.h"



namespace Engine {
	
	using namespace Microsoft::WRL;

	DXGIFactory::DXGIFactory()
	{
		YT_EVAL_HR(CreateDXGIFactory2(DXGI_CREATE_FACTORY_DEBUG, IID_PPV_ARGS(&ptr_)), "Some Error");
		


	}

	DXGIAdapter DXGIFactory::GetAdapter()
	{

		ComPtr<IDXGIFactory6> fac6;

		ComPtr<IDXGIAdapter> adapter;
		
		if (Get()->QueryInterface(IID_PPV_ARGS(&fac6)) == S_OK) {
			
			YT_EVAL_HR(fac6->EnumAdapterByGpuPreference(0, DXGI_GPU_PREFERENCE_HIGH_PERFORMANCE, IID_PPV_ARGS(&adapter)), "Error finding the adapter");
		}
		else {
			YT_ASSERT(false);
		}

		return DXGIAdapter(adapter.Get());
	}
}