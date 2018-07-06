#include <windows.h>
#include <stdio.h>
#include <stdlib.h>

int main(){
	printf("123\n");
	SetCursorPos(1260, 10);
	mouse_event(MOUSEEVENTF_LEFTDOWN,0,0,0,0);
	mouse_event(MOUSEEVENTF_LEFTUP,0,0,0,0);
	Sleep(20);
	SetCursorPos(20, 460);
	mouse_event(MOUSEEVENTF_LEFTDOWN,0,0,0,0);
	mouse_event(MOUSEEVENTF_LEFTUP,0,0,0,0);
	Sleep(20);
	mouse_event(MOUSEEVENTF_LEFTDOWN,0,0,0,0);
	mouse_event(MOUSEEVENTF_LEFTUP,0,0,0,0);
	Sleep(1000);
	keybd_event(VK_HANGEUL,0,KEYEVENTF_EXTENDEDKEY, 0);
	keybd_event(68,0,KEYEVENTF_EXTENDEDKEY, 0);
	Sleep(100);
	keybd_event(68,0,KEYEVENTF_KEYUP, 0);
	keybd_event(76,0,KEYEVENTF_EXTENDEDKEY, 0);
	Sleep(100);
	keybd_event(76,0,KEYEVENTF_KEYUP, 0);
	keybd_event(84,0,KEYEVENTF_EXTENDEDKEY, 0);
	Sleep(100);
	keybd_event(84,0,KEYEVENTF_KEYUP, 0);
	keybd_event(75,0,KEYEVENTF_EXTENDEDKEY, 0);
	Sleep(100);
	keybd_event(75,0,KEYEVENTF_KEYUP, 0);
	keybd_event(68,0,KEYEVENTF_EXTENDEDKEY, 0);
	Sleep(100);
	keybd_event(68,0,KEYEVENTF_KEYUP, 0);
	keybd_event(68,0,KEYEVENTF_EXTENDEDKEY, 0);
	Sleep(100);
	keybd_event(68,0,KEYEVENTF_KEYUP, 0);
	keybd_event(76,0,KEYEVENTF_EXTENDEDKEY, 0);
	Sleep(100);
	keybd_event(76,0,KEYEVENTF_KEYUP, 0);
	keybd_event(83,0,KEYEVENTF_EXTENDEDKEY, 0);
	
	return 0;
}