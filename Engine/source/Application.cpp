#include "pch.h"
#include "Application.h"



namespace Engine {

	LRESULT CALLBACK WindProc(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam) {

		switch (msg) {
		case WM_NCCREATE: {
			LPCREATESTRUCT param = reinterpret_cast<LPCREATESTRUCT>(lparam);
			Application* pointer = reinterpret_cast<Application*>(param->lpCreateParams);
			
			SetWindowLongPtr(hwnd, GWLP_USERDATA, reinterpret_cast<LONG_PTR>(pointer));
			std::cout << "Sent Create a Window" << std::endl;
			break;
		}
		case WM_CREATE: {
			Application* pointer = reinterpret_cast<Application*>(GetWindowLongPtr(hwnd, GWLP_USERDATA));
			pointer->OnCreate(hwnd);
			break;
		}

		case WM_DESTROY: {
			Application* pointer = reinterpret_cast<Application*>(GetWindowLongPtr(hwnd, GWLP_USERDATA));
			pointer->OnDestroy();
			PostQuitMessage(0);
			break;
		}

		}

		return DefWindowProc(hwnd, msg, wparam, lparam);
	}

	bool Application::Initialize()
	{
		WNDCLASS wndClass = {};		
		wndClass.lpszClassName = L"BaseWindowClass";
		wndClass.style = 0;
		wndClass.hCursor = LoadCursor(NULL, IDC_ARROW);
		wndClass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
		wndClass.hbrBackground = (HBRUSH)COLOR_WINDOW;
		wndClass.lpszMenuName = 0;
		wndClass.hInstance = 0;
		wndClass.lpfnWndProc = WindProc;
		wndClass.cbClsExtra = 0;
		wndClass.cbWndExtra = 0;

		RegisterClass(&wndClass);

		mWindowHandle =  CreateWindow(L"BaseWindowClass",L"ENGINE WINDOW", WS_OVERLAPPEDWINDOW, 200,200,1280,700,0,0,0,this);
		if (!mWindowHandle) {
			return false;
		}
		ShowWindow(mWindowHandle, SW_SHOW);
		UpdateWindow(mWindowHandle);

		mIsRunning = true;

		return mIsRunning;

	}


	void Application::OnCreate(HWND hwnd) {

		std::cout << "Created the actual window!!";
		mRendered.Initialize(hwnd);
	}



	void Application::Update()
	{
		MSG message;
		while (PeekMessage(&message, 0, 0, 0, PM_REMOVE)) {
			TranslateMessage(&message);
			DispatchMessage(&message);
		}
	}

	void Application::OnDestroy()
	{
		std::cout << "Closed the Windows - Shutting Down application" << std::endl;
		mIsRunning = false;
	}
}