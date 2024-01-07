#pragma once
#include "EngineMin.h";
#include <Windows.h>;
#include "D12Device.h";


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

