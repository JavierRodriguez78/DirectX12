#pragma once
#include "EngineMin.h"
#include <Windows.h>
#include "RenderApi\RenderApi.h"



namespace Engine {
	class YT_API Application
	{
	public:
		Application() = default;
		bool Initialize();
		void OnCreate(HWND hwnd);
		void Update();
		void OnDestroy();
		inline bool IsRunning() { return mIsRunning; };

	private: //Subsystem:

		RenderApi mRendered;

	private: //Variables:
		bool mIsRunning = false;
		HWND mWindowHandle = nullptr;

	};
}
