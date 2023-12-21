#include <stdio.h>
#include <graphics.h>
#include <time.h>
#include "Image.h"
#include "Player.h"
#include "Variate.h"
#include "Enemy.h"

#define BKX 660
#define BKY 700

ExMessage msg2 = { 0 };		//������Ϣ�ṹ�����

void game_Init()
{
	player.x = BKX / 2 + IMG_BK2X;
	player.y = BKY * 3 / 4 + IMG_BK2Y;
	player.width = 32;
	player.height = 54;
	player.live = true;
	player.HP = 12;	
	for (int i = 0; i < BULLET_NUM; i++) {
		player_Bullet[i].x = 0;
		player_Bullet[i].y = 0;
		player_Bullet[i].width = 12;
		player_Bullet[i].height = 12;
		player_Bullet[i].live = false;
	}
	for (int i = 0; i < ENEMY1_NUM; i++) {
		enemy1[i].x = 100;
		enemy1[i].y = 100;
		enemy1[i].width = 34;
		enemy1[i].height = 34;
		enemy1[i].live = true;
		enemy1[i].HP = 20;
	}
}

int within_Bk(int px, int py, int w, int h)		//�ж��Ƿ��ڵ�ͼ��
{
	if (IMG_BK2X <= px && px <= IMG_BK2X + BKX - w && IMG_BK2Y <= py && py <= IMG_BK2Y + BKY - h) {
		return 1;
	}
	else {
		return 0;
	}
}

void key_Message(int* dx, int* dy, int ps)
{
	static DWORD time1, time2;	//���������ӵ������ٶ�
	peekmessage(&msg2, EX_KEY);
	if (within_Bk(player.x, player.y, player.width, player.height)) {	//�ж��Ƿ��ڱ߽���
#if 0//z����ͷ������ͻ������Windows��GetAsyncKeyState����
		if (msg2.message == WM_KEYDOWN) {//�жϷ���
			switch (msg2.vkcode) {
			case VK_UP:*dy = -1; break;
			case VK_DOWN:*dy = 1; break;
			case VK_LEFT:*dx = -1; break;
			case VK_RIGHT:*dx = 1; break;
			case 'Z':
				if (time2 - time1 > 100) {
					creat_Bullet();
					time1 = time2;
				}
				break;
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
#else
		if (GetAsyncKeyState(VK_UP)) {
			*dy = -1;
		}
		if (GetAsyncKeyState(VK_DOWN)) {
			*dy = 1;
		}
		if (GetAsyncKeyState(VK_LEFT)) {
			*dx = -1;
		}
		if (GetAsyncKeyState(VK_RIGHT)) {
			*dx = 1;
		}
		if (GetAsyncKeyState('Z')) {	//�����ӵ�
			if (time2 - time1 > 100) {
				creat_Playerbullet();
				time1 = time2;
			}
		}
		if (msg2.message == WM_KEYUP) {		//���ɿ��������ٶ����㣬��ɫֹͣ
			if (!GetAsyncKeyState(VK_UP) || !GetAsyncKeyState(VK_DOWN)) {
				*dy = 0;
			}
			if (!GetAsyncKeyState(VK_LEFT) || !GetAsyncKeyState(VK_RIGHT)) {
				*dx = 0;
			}
		}
#endif
	}
	else {
		*dy = 0;	//��ɫֹͣ
		*dx = 0; 
		if (player.x > IMG_BK2X + BKX - player.width) {
			player.x--;		//��ֹ��ɫ���ڵ�ͼ��
		}		
		if (player.x < IMG_BK2X) {
			player.x++;
		}
		if (player.y > IMG_BK2Y + BKY - player.height) {
			player.y--;
		}
		if (player.y < IMG_BK2Y) {
			player.y++;
		}
	}
	time2 = GetTickCount();
}

void Game()
{
	game_Init();	//��ʼ����Ϸ��ֵ
	
	BeginBatchDraw();	//˫�����ͼ
	while (1) {
		FlushBatchDraw();
		cleardevice();

		load_Image();
		change_Background();	//�ı䱳��

		Player();
		Enemy();

		key_Message(&directionx, &directiony, player_speed);

		msg2.message = 0;	//��Ϣ����
	}
	EndBatchDraw();
}