#include "stdio.h"
#include "graphics.h"
#include "mmsystem.h"
#pragma comment(lib,"winmm.lib")
#include "scan.h"
IMAGE img[10], img_Big[10];//大图片，小图片
struct Point
{
	int x;
	int y;
};
void InitImg()
{
  //保存图片路径
	char buf[128] = {0};
	for (int i = 0; i < 10; i++) {
		sprintf_s(buf, "图片//%d.jpg",i+1);
		loadimage (&img[i],buf, 30, 30);
		loadimage(&img_Big[i], buf, 300, 200);
	}
}

int main()
{

	//获取当前窗口句柄
	HWND hwnd = initgraph(GetSystemMetrics(SM_CXSCREEN),
	GetSystemMetrics(SM_CYSCREEN));

	//设置窗口风格 减去窗口标题
	SetWindowLong(hwnd, GWL_STYLE,
		GetWindowLong(hwnd, GWL_STYLE) - WS_CAPTION);

	//设置窗口的起始点  默认风格
	SetWindowPos(hwnd, HWND_TOPMOST, 280, 0, GetSystemMetrics(SM_CXSCREEN),
		GetSystemMetrics(SM_CYSCREEN), SWP_SHOWWINDOW);

	//拿到我背面的窗口风格
	LONG WindowLong = GetWindowLong(hwnd, GWL_EXSTYLE) | WS_EX_LAYERED;

	//设置窗口风格
	SetWindowLong(hwnd, GWL_EXSTYLE, WindowLong);

	//把黑色的背景设置为透明
	SetLayeredWindowAttributes(hwnd, RGB(0, 0, 0), 0, LWA_COLORKEY);
	void fireflower();
	Point arr[46] = {

		{395,268}, //第一个
		{406,222},
		{416,193},
		{441,162},
		{468,133},
		{500,117},
		{537,105},
		{577,107},
		{617,120},
		{649,146},
		{666,173},
		{680,211},
		{683,247},
		{680,293},
		{675,338},
		{660,385},
		{640,440},
		{616,484},
		{588,529},
		{557,573},
		{530,610},
		{493,645},
		{460,675},
		{422,696},
		{381,676},
		{350,654},
		{320,626},
		{292,606},
		{257,570},
		{230,540},
		{200,500},
		{180,470},
		{160,430},
		{140,390},
		{126,342},
		{117,293},
		{120,250},
		{133,203},
		{160,170},
		{200,140},
		{240,130},
		{280,135},
		{312,146},
		{340,170},
		{360,195},
		{375,230} };
	InitImg();
	mciSendString("open 音乐//0.mp3", 0, 0, 0);
	mciSendString("play 音乐//0.mp3", 0, 0, 0);
	int II = 1;
		for (int i = 0; i < 46; i++)
		{
			putimage(arr[i].x, arr[i].y, &img[i % 10]);//屏幕上随机打印46张照片
			Sleep(100);
		}
		putimage(250, 290, &img_Big[II% 10]);
		Sleep(1480);
		cleardevice();
		
		int I = 1; int n = 1;
		while (n) {
			
			I++;
			for (int i = 1; i < 46; i++)
			{
				putimage(arr[i].x, arr[i].y, &img[(i+I) % 10]);//屏幕上随机打印46张照片
			}
			putimage(250, 290, &img_Big[I % 10]);
			Sleep(1000);
			cleardevice();
			scan(n);
		}
}
