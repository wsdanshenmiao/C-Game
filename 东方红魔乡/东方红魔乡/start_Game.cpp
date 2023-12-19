#include <stdio.h>
#include <graphics.h>
#include <time.h>
#include "tools.hpp"
#include "IMAGE.h"

#define BKX 660
#define BKY 700

int img_bk2x = 40;
int img_bk2y = 34;
ExMessage msg2 = { 0 };//定义消息结构体变量

void game_Init()
{
	player.x = BKX / 2 + img_bk2x;
	player.y = BKY * 3 / 4 + img_bk2y;
	player.width = 32;
	player.height = 54;
	player.live = true;
	player.HP = 12;	
	for (int i = 0; i < BULLET_NUM; i++) {
		bullet[i].x = 0;
		bullet[i].y = 0;
		bullet[i].width = 12;
		bullet[i].height = 12;
		bullet[i].live = false;
	}
}

void load_Image()
{	
	loadimage(&img_bk2, "assets\\bk2.jpg");
	loadimage(img_bk3 + 0, "assets\\bk3-1.jpg");
	loadimage(img_bk3 + 1, "assets\\bk3-2.jpg");

	loadimage(img_player + 0, "assets\\博丽灵梦（红魔乡自机像素绘）.png");
	//loadimage(img_player + 0, "assets\\player.jpg");
	//loadimage(img_player + 1, "assets\\player_a.jpg");
	loadimage(img_bullet + 0, "assets\\player.png");
	loadimage(img_bullet + 1, "assets\\player_a.png");
}

void change_Background()
{
	int a = 256;
	int b = 128;
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
	int time_Intervalplayer = 100;
	//时间间隔100ms
	//图片去背景后还是有背景，就换了一个，没有动态效果了，但换了后发现会上下动，看着还行
	//putimage(player.x, player.y, player.width, player.height, img_player + 1, player.width * index_player, 0, NOTSRCERASE);
	//putimage(player.x, player.y, player.width, player.height, img_player + 0, player.width * index_player, 0, SRCERASE);
	drawImg(player.x, player.y, player.width, player.height, img_player + 0, player.width * index_player, 0);
	
	//drawImg(player.x, player.y, player.width, player.height, img_player + 0, player.width * index_player, 0);
	index_player = (clock() / time_Intervalplayer) % frames_player;
	return index_player;
}

void load_Bullet()
{
	for (int i = 0; i < BULLET_NUM; i++) {
		if (bullet[i].live) {//创建子弹
			putimage(bullet[i].x, bullet[i].y, bullet[i].width, bullet[i].height, img_bullet + 1, 130, 2);
			putimage(bullet[i].x, bullet[i].y, bullet[i].width, bullet[i].height, img_bullet + 0, 130, 2);
		}
	}

}

void bullet_Move()
{
	for (int i = 0; i < BULLET_NUM; i++) {
		if (bullet[i].live) {
			bullet[i].y -= 4;
			//bullet[i + 1].y -= 4;
			if (bullet[i].y < img_bk2y) {
				bullet[i].live = false;
				//bullet[i + 1].live = false;
			}
		}
	}

}

int within_Bk(int px, int py, int w, int h)
{
	if (img_bk2x <= px && px <= img_bk2x + BKX - w && img_bk2y <= py && py <= img_bk2y + BKY - h) {
		return 1;
	}
	else {
		return 0;
	}
}

void creat_Bullet()
{
	for (int i = 0; i < BULLET_NUM; i++) {
		if (!bullet[i].live) {//创建子弹
			bullet[i].live = true;
			bullet[i].x = player.x + player.width / 2;
			bullet[i].y = player.y - player.height / 4;
			break;
		}
	}
}

void key_Message(int* dx, int* dy, int ps)
{
	static DWORD time1, time2;
	peekmessage(&msg2, EX_KEY);
	if (GetAsyncKeyState('Z')) {
		if (time2 - time1 > 100) {
			creat_Bullet();
			time1 = time2;
		}
	}
	if (within_Bk(player.x, player.y, player.width, player.height)) {//判断是否在边界内
		if (msg2.message == WM_KEYDOWN) {//判断方向
			switch (msg2.vkcode) {
			case VK_UP:*dy = -1; break;
			case VK_DOWN:*dy = 1; break;
			case VK_LEFT :*dx = -1; break;
			case VK_RIGHT:*dx = 1; break;
			//case 'Z':
			//	if (time2 - time1 > 100) {
			//		creat_Bullet();
			//		time1 = time2;
			//	}
			//	break;
			}
		}
		else if (msg2.message == WM_KEYUP) {
			switch (msg2.vkcode) {
			case VK_UP:*dy = 0; break;
			case VK_DOWN:*dy = 0; break;
			case VK_LEFT:*dx = 0; break;
			case VK_RIGHT:*dx = 0; break;
			}
		}
	}
	else {
		*dy = 0;//角色停止
		*dx = 0; 
		if (player.x > img_bk2x + BKX - player.width) {
			player.x--;
		}		
		if (player.x < img_bk2x) {
			player.x++;
		}
		if (player.y > img_bk2y + BKY - player.height) {
			player.y--;
		}
		if (player.y < img_bk2y) {
			player.y++;
		}
	}
	time2 = GetTickCount();
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

		load_Image();
		change_Background();//改变背景

		//Player();
		index_player = load_Player(index_player);
		player.x += directionx * player_speed;
		player.y += directiony * player_speed;

		load_Bullet();
		bullet_Move();

		key_Message(&directionx, &directiony, player_speed);


		msg2.message = 0;//消息清零
	}
	EndBatchDraw();
}