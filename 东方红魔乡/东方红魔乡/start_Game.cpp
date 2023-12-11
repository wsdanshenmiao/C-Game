#include <stdio.h>
#include <graphics.h>
#include <time.h>
#include "tools.hpp"
#include "IMAGE.h"

int img_bk2x = 40;
int img_bk2y = 34;
struct player player;
ExMessage msg2 = { 0 };//定义消息结构体变量

void game_Init()
{
	player.x = 512;
	player.y = 512;
	player.live = true;
	player.width = 32;
	player.height = 54;
	player.HP = 12;
}

void change_Background()
{
	int a = 256;
	int b = 128;
	loadimage(&img_bk2, "assets\\bk2.jpg");
	loadimage(img_bk3 + 0, "assets\\bk3-1.jpg");
	loadimage(img_bk3 + 1, "assets\\bk3-2.jpg");
	putimage(img_bk2x, img_bk2y, &img_bk2);
	putimage(730, 480, a, a, img_bk3 + 1, a, a, NOTSRCERASE);//先绘制掩码图
	putimage(730, 480, a, a, img_bk3 + 0, a, a, SRCERASE);//再绘制原图
	putimage(700, 440, a, b, img_bk3 + 1, 0, 0, NOTSRCERASE);//先绘制掩码图
	putimage(700, 440, a, b, img_bk3 + 0, 0, 0, SRCERASE);//再绘制原图
	putimage(790, 540, b, b, img_bk3 + 1, a, 0, NOTSRCERASE);//先绘制掩码图
	putimage(790, 540, b, b, img_bk3 + 0, a, 0, SRCERASE);//再绘制原图
	putimage(750, 640, b, b, img_bk3 + 1, 384, 0, NOTSRCERASE);//先绘制掩码图
	putimage(750, 640, b, b, img_bk3 + 0, 384, 0, SRCERASE);//再绘制原图
	putimage(890, 640, b, b, img_bk3 + 1, 0, b, NOTSRCERASE);//先绘制掩码图
	putimage(890, 640, b, b, img_bk3 + 0, 0, b, SRCERASE);//再绘制原图
}

int load_Player(int index_player)
{	
	int frames_player = 4;//人物有四帧
	int time_Intervalplayer = 100;//时间间隔100ms
	loadimage(img_player + 0, "assets\\博丽灵梦（红魔乡自机像素绘）.png");
	//图片去背景后还是有背景，就换了一个，没有动态效果了，但换了后发现会上下动，看着还行
	//loadimage(img_player + 1, "assets\\player_a.png");
	//putimage(512, 512, player.width, player.height, img_player + 1, player.width * index_player, 0, NOTSRCERASE);
	//putimage(512, 512, player.width, player.height, img_player + 0, player.width * index_player, 0, SRCERASE);
	drawImg(player.x, player.y, player.width, player.height, img_player + 0, player.width * index_player, 0);
	index_player = (clock() / time_Intervalplayer) % frames_player;
	return index_player;
}

void key_Message(int* dx, int* dy, int ps)
{
	peekmessage(&msg2, EX_KEY);
	if (msg2.message == WM_KEYDOWN) {
		switch (msg2.vkcode) {
		case 'W':*dy = -1; break;
		case 'S':*dy = 1; break;
		case 'A':*dx = -1; break;
		case 'D':*dx = 1; break;
		}
	}
	else if (msg2.message == WM_KEYUP) {
		switch (msg2.vkcode) {
		case 'W':*dy = 0; break;
		case 'S':*dy = 0; break;
		case 'A':*dx = 0; break;
		case 'D':*dx = 0; break;
		}
	}
}

void start_Game()
{	
	game_Init();//初始化游戏数值

	int index_player = 0;
	int player_speed = 2;//玩家速度
	int directionx = 0;//x轴方向
	int directiony = 0;//y轴方向
	
	BeginBatchDraw();//双缓冲绘图
	while (1) {
		FlushBatchDraw();
		cleardevice();
		change_Background();//改变背景
		index_player = load_Player(index_player);
		key_Message(&directionx, &directiony, player_speed);
		player.x += directionx * player_speed;
		player.y += directiony * player_speed;


		msg2.message = 0;//消息清零
	}
	EndBatchDraw();
}