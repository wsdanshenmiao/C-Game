#include <graphics.h>
#include <stdio.h>
#include "start_Game.h"

#define WINWIDTH 1024
#define WINHEIGHT 768

IMAGE img_bk1;
ExMessage msg = { 0 };//定义消息结构体变量

void create_Background()
{
	loadimage(&img_bk1, "assets\\bk1.jpg");//初始背景
	putimage(0, 0, &img_bk1);
}

int within_Limits(int mx, int my, int x, int y, int w, int h)
{
	if (x < mx && mx < x + w && y < my && my < y + h) {
		return 1;
	}
	else {
		return 0;
	}
}

int botton(int x, int y, int width, int height, const char* text)//判断按钮是否按下
{
	int wspace = (width - textwidth(text)) / 2;
	int hspace = (height - textheight(text)) / 2;
	if (within_Limits(msg.x, msg.y, x, y, width, height)) {
		setfillcolor(RGB(51, 51, 51));
	}
	else {
		setfillcolor(RGB(0, 0, 0));

	}
	solidrectangle(x, y, x + width, y + height);//绘制按钮
	settextstyle(80, 0, "华文隶书");
	settextcolor(RGB(215, 88, 117));
	outtextxy(x, y, "开始游戏");//绘制文字
	if (msg.message == WM_LBUTTONDOWN && within_Limits(msg.x, msg.y, x, y, width, height)) {
		return 1;
	}
	else {
		return 0;
	}
}

int main()
{
	initgraph(WINWIDTH, WINHEIGHT);//创建窗口
	cleardevice();
	setbkmode(TRANSPARENT);

	while (1) {
		peekmessage(&msg, EX_MOUSE);//获取消息

		int x = 512 - textwidth("开始游戏") / 2;
		int y = 500;
		int width = textwidth("开始游戏");
		int height = textheight("开始游戏");

		BeginBatchDraw();
		cleardevice();

		create_Background();//创建背景
		if (botton(x, y, width, height, "开始游戏")) {//判断按钮是否按下
			start_Game();
			printf("start game\n");
		}

		EndBatchDraw();
	}

	getchar();

	return 0;
}