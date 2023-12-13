#include <stdio.h>
#include <graphics.h>
#include <time.h>
#include "tools.hpp"
#include "IMAGE.h"

#define BKX 660
#define BKY 700

int img_bk2x = 40;
int img_bk2y = 34;
ExMessage msg2 = { 0 };//������Ϣ�ṹ�����

void game_Init()
{
	player.x = BKX / 2 + img_bk2x;
	player.y = BKY * 3 / 4 + img_bk2y;
	player.width = 32;
	player.height = 54;
	player.live = true;
	player.HP = 12;
}

void bullet_Init()
{
	int x = 0, y = 0;
	int width = 16;
	int height = 16;
	bool live = false;
}

void change_Background()
{
	int a = 256;
	int b = 128;
	loadimage(&img_bk2, "assets\\bk2.jpg");
	loadimage(img_bk3 + 0, "assets\\bk3-1.jpg");
	loadimage(img_bk3 + 1, "assets\\bk3-2.jpg");
	putimage(img_bk2x, img_bk2y, &img_bk2);
	putimage(730, 480, a, a, img_bk3 + 1, a, a, NOTSRCERASE);//�Ȼ�������ͼ
	putimage(730, 480, a, a, img_bk3 + 0, a, a, SRCERASE);//�ٻ���ԭͼ
	putimage(700, 440, a, b, img_bk3 + 1, 0, 0, NOTSRCERASE);//�Ȼ�������ͼ
	putimage(700, 440, a, b, img_bk3 + 0, 0, 0, SRCERASE);//�ٻ���ԭͼ
	putimage(790, 540, b, b, img_bk3 + 1, a, 0, NOTSRCERASE);//�Ȼ�������ͼ
	putimage(790, 540, b, b, img_bk3 + 0, a, 0, SRCERASE);//�ٻ���ԭͼ
	putimage(750, 640, b, b, img_bk3 + 1, 384, 0, NOTSRCERASE);//�Ȼ�������ͼ
	putimage(750, 640, b, b, img_bk3 + 0, 384, 0, SRCERASE);//�ٻ���ԭͼ
	putimage(890, 640, b, b, img_bk3 + 1, 0, b, NOTSRCERASE);//�Ȼ�������ͼ
	putimage(890, 640, b, b, img_bk3 + 0, 0, b, SRCERASE);//�ٻ���ԭͼ
}

int load_Player(int index_player)
{	
	int frames_player = 4;//��������֡
	int time_Intervalplayer = 100;//ʱ����100ms
	loadimage(img_player + 0, "assets\\�������Σ���ħ���Ի����ػ棩.png");
	//ͼƬȥ���������б������ͻ���һ����û�ж�̬Ч���ˣ������˺��ֻ����¶������Ż���
	//loadimage(img_player + 1, "assets\\player_a.png");
	//putimage(512, 512, player.width, player.height, img_player + 1, player.width * index_player, 0, NOTSRCERASE);
	//putimage(512, 512, player.width, player.height, img_player + 0, player.width * index_player, 0, SRCERASE);
	drawImg(player.x, player.y, player.width, player.height, img_player + 0, player.width * index_player, 0);
	index_player = (clock() / time_Intervalplayer) % frames_player;
	return index_player;
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

void key_Message(int* dx, int* dy, int ps)
{
	peekmessage(&msg2, EX_KEY);
	if (within_Bk(player.x, player.y, player.width, player.height)) {//�ж��Ƿ��ڱ߽���
		if (msg2.message == WM_KEYDOWN) {//�жϷ���
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
	else {
		*dy = 0;//��ɫֹͣ
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
}

void start_Game()
{	
	game_Init();//��ʼ����Ϸ��ֵ
	bullet_Init();

	int index_player = 0;
	int player_speed = 2;//����ٶ�
	int directionx = 0;//x�᷽��
	int directiony = 0;//y�᷽��
	
	BeginBatchDraw();//˫�����ͼ
	while (1) {
		FlushBatchDraw();
		cleardevice();
		change_Background();//�ı䱳��
		index_player = load_Player(index_player);
		key_Message(&directionx, &directiony, player_speed);
		player.x += directionx * player_speed;
		player.y += directiony * player_speed;


		msg2.message = 0;//��Ϣ����
	}
	EndBatchDraw();
}