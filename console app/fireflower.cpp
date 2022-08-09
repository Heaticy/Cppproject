#include "fireflower.h"

void fireflower()
{


	//打开一个窗口 1200 800
	initgraph(1200, 800);
	srand((unsigned int)time(NULL));


	DWORD t1 = GetTickCount();
	DWORD* pem = GetImageBuffer();

	for (int i = 0; i < NUM; i++)
	{
		Init(i);
	}
	Load();
	BeginBatchDraw();
	while (1)
	{
		Sleep(10);

		for (int clr = 0; clr < 1000; clr++)
		{
			for (int j = 0; j < 2; j++)
			{
				int px1 = rand() % 1200;
				int py1 = rand() % 800;

				if (py1 < 799)
				{
					pem[py1 * 1200 + px1] = pem[py1 * 1200 + px1 + 1] = BLACK;
				}
			}
		}

		Chose(t1);
		Shoot();
		Show(pem);
		FlushBatchDraw();
	}
	
}

//初始化 13个
void Init(int i)
{
	// 分别为：烟花中心到图片边缘的最远距离、烟花中心到图片左上角的距离 (x、y) 两个分量
	int r[15] = { 120, 120, 155, 123, 130, 147, 138, 138, 130, 135, 140, 132, 155, 145, 124 };
	int x[15] = { 120, 120, 110, 117, 110, 93, 102, 102, 110, 105, 100, 108, 110, 145, 124 };
	int y[15] = { 120, 120, 85, 118, 120, 103, 105, 110, 110, 120, 120, 104, 85, 145, 124 };

	fire[i].width = 500;
	fire[i].height = 500;
	fire[i].maxr = r[i];
	fire[i].cenx = x[i];
	fire[i].ceny = y[i];
	fire[i].show = false;
	fire[i].t1 = GetTickCount();
	fire[i].dt = 5;
	fire[i].r = 0;

	//初始化烟花弹的部分数据
	jet[i].t1 = GetTickCount();  //定个时间点
	jet[i].dt = rand() % 10;     //0-9 ms
	jet[i].n = 0;
	jet[i].shoot = false;        //都是没有发射的。
}

//加载图片
void Load()  //加载到哪里去？
{
	IMAGE fm, gm;
	char FM[128] = { 0 };
	sprintf_s(FM, ". / fire / flower.jpg");
	loadimage(&fm, FM, 3120, 240);
	for (int i = 0; i < NUM; i++)
	{
		SetWorkingImage(&fm); //fm去拿
		getimage(&gm, i * 240, 0, 240, 240);  //gm
		SetWorkingImage(&gm); //gm去拿

		for (int a = 0; a < 240; a++)
		{
			for (int b = 0; b < 240; b++)
			{
				fire[i].xy[a][b] = getpixel(a, b);
			}
		}
	}

	//文件夹
	IMAGE sm;
	char SM[128] = { 0 };
	sprintf_s(SM, ". /fire/shoot.jpg");
	loadimage(&sm,SM, 200, 50);
	//保存在sm
	for (int i = 0; i < NUM; i++)
	{
		SetWorkingImage(&sm); //sm去拿
		int n = rand() % 5;  //0-4
		getimage(&jet[i].img[0], n * 20, 0, 20, 50);  //暗的
		getimage(&jet[i].img[1], (n + 5) * 20, 0, 20, 50);  //亮的
	}
	SetWorkingImage(NULL);			//sm去拿
}

//选择烟花弹  烟花弹产生的速度！！！
void Chose(DWORD& t1)
{
	DWORD t2 = GetTickCount();   //13个

	if (t2 - t1 > 1)  //每隔1个ms  产生一个烟花弹
	{
		int n = rand() % NUM;  //0-12
		if (jet[n].shoot == false && fire[n].show == false) //非发射状态
		{
			jet[n].x = rand() % 1200;
			jet[n].y = rand() % 100 + 600; //600-699之间
			jet[n].hx = jet[n].x;
			jet[n].hy = rand() % 400;			//0-399
			jet[n].shoot = true;            //发射状态

			putimage(jet[n].x, jet[n].y, &jet[n].img[jet[n].n], SRCINVERT);
		}
		t1 = t2;
	}
}

void Shoot()
{
	for (int i = 0; i < NUM; i++)
	{
		jet[i].t2 = GetTickCount();
		if (jet[i].t2 - jet[i].t1 >= jet[i].dt && jet[i].shoot == true)
		{
			putimage(jet[i].x, jet[i].y, &jet[i].img[jet[i].n], SRCINVERT);
			if (jet[i].y >= jet[i].hy)
			{
				jet[i].n++;		//一闪一闪
				jet[i].y -= 5;  //上升
			}
			//putimage(jet[i].x, jet[i].y, &jet[i].img[jet[i].n], SRCINVERT);

			if (jet[i].y <= jet[i].hy)  //到达最高点了
			{
				//擦除烟花弹
				putimage(jet[i].x, jet[i].y, &jet[i].img[jet[i].n], SRCINVERT);
				//烟花弹最高点的 hx hy  -----》烟花
				fire[i].x = jet[i].hx;
				fire[i].y = jet[i].hy;
				//改变烟花弹的状态
				jet[i].shoot = false;
				fire[i].show = true;
			}

			putimage(jet[i].x, jet[i].y, &jet[i].img[jet[i].n], SRCINVERT);
			jet[i].t1 = jet[i].t2;
		}
	}
}

void Show(DWORD* pem)
{
	int dir[16] = { 5, 5, 5, 5, 5, 8, 25, 25, 25, 55, 55, 55, 55, 65, 65, 66 };

	for (int i = 0; i < NUM; i++)
	{
		fire[i].t2 = GetTickCount();

		if (fire[i].t2 - fire[i].t1 > fire[i].dt && fire[i].show == true)
		{
			if (fire[i].r < fire[i].maxr)
			{
				fire[i].r++;
				fire[i].dt = dir[fire[i].r / 10];
				fire[i].draw = true;
			}

			if (fire[i].r >= fire[i].maxr - 1)
			{
				fire[i].draw = false;
				Init(i);
			}
			fire[i].t1 = fire[i].t2;
		}

		if (fire[i].draw == true)
		{
			//圆  PI
			for (double a = 0; a <= 6.28; a += 0.01)
			{
				int x1 = (int)(fire[i].cenx + fire[i].r * cos(a));
				int y1 = (int)(fire[i].ceny - fire[i].r * sin(a));
				if (x1 > 0 && x1 < fire[i].width && y1>0 && y1 < fire[i].height)
				{
					int b = fire[i].xy[x1][y1] & 0xff;
					int g = (fire[i].xy[x1][y1] >> 8) & 0xff;
					int r = fire[i].xy[x1][y1] >> 16;

					int xx = (int)(fire[i].x + fire[i].r * cos(a));
					int yy = (int)(fire[i].y - fire[i].r * sin(a));

					if (r > 0x20 && g > 0x20 && b > 0x20 && xx > 0 && xx < 1200 && yy>0 && yy < 800)
						pem[yy * 1200 + xx] = BGR(fire[i].xy[x1][y1]);
				}
			}
			fire[i].draw = false;
		}
	}
}