#include <graphics.h>
#include <stdio.h>
#include "start_Game.h"
#include "IMAGE.h"

#define WINWIDTH 1024
#define WINHEIGHT 768

ExMessage msg1 = { 0 };//定义消息结构体变量

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
	if (within_Limits(msg1.x, msg1.y, x, y, width, height)) {
		setfillcolor(RGB(51, 51, 51));
	}
	else {
		setfillcolor(RGB(0, 0, 0));

	}
	solidrectangle(x, y, x + width, y + height);//绘制按钮
	settextstyle(80, 0, "华文隶书");
	settextcolor(RGB(215, 88, 117));
	outtextxy(x, y, text);//绘制文字
	if (msg1.message == WM_LBUTTONDOWN && within_Limits(msg1.x, msg1.y, x, y, width, height)) {
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
	setbkcolor(RGB(38, 0, 0));
	setbkmode(TRANSPARENT);

	while (1) {
		peekmessage(&msg1, EX_MOUSE);//获取消息

		int x = 256 - textwidth("开始游戏") / 2;
		int y = 500;
		int width = textwidth("开始游戏");
		int height = textheight("开始游戏");

		BeginBatchDraw();
		cleardevice();

		create_Background();//创建背景
		if (botton(x, y, width, height, "开始游戏")) {//判断按钮是否按下
			printf("start game\n");
			start_Game();
		}
		if (botton(x + 512, y, width, height, "退出游戏")) {
			printf("end game\n");
			break;
		}
		msg1.message = 0;//消息清零
		EndBatchDraw();
	}

	return 0;
}