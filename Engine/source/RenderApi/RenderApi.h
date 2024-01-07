#pragma once
#include "..\EngineMin.h";
#include <Windows.h>;

#include "DirectX12\Base\D12Device.h";


namespace Engine {
	class YT_API RenderApi
	{
	public:
		RenderApi() = default;
		~RenderApi();
		void Initialize(HWND hwnd);

	private:
		D12Device mDevice;
	};
}

