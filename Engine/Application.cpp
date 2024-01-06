#include "pch.h"
#include "Application.h"
#include <windowsx.h>
#include <iostream>


namespace Engine {

	LRESULT CALLBACK WindProc(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam) {

		switch (msg) {
		case WM_NCCREATE: {
			std::cout << "Create a Window" << std::endl;
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

		mWindowHandle =  CreateWindow(L"BaseWindowClass",L"ENGINE WINDOW", WS_OVERLAPPEDWINDOW, 200,200,1280,700,0,0,0,0);
		if (!mWindowHandle) {
			return false;
		}
		ShowWindow(mWindowHandle, SW_SHOW);
		UpdateWindow(mWindowHandle);

		mIsRunning = true;

		return mIsRunning;

	}
	void Application::Update()
	{

	}
}