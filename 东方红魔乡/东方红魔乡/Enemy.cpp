#include <graphics.h>
#include <time.h>
#include <stdlib.h>
#include "Variate.h"
#include "Image.h"
#include "Game.h"

void Enemy1()
{
	static DWORD enemy1_Time1, enemy1_Time2;	//敌人1之间出现的时间
	static DWORD enemy1_Time3, enemy1_Time4;	//敌人1每波出现的时间
	static int enemies_Appears = ENEMY1_NUM1 * ENEMY1_NUM2;

	index_enemy1 = load_Enemy1(index_enemy1);
	enemy1_Move();

	if (enemies_Appears) {
		if (enemy1_Time2 - enemy1_Time1 > 200) {
			creat_Enemy1();
			enemy1_Time1 = enemy1_Time2;
			enemies_Appears--;
		}
	}
	if (enemy1_Time4 - enemy1_Time3 > 10000) {
		enemies_Appears = ENEMY1_NUM1 * ENEMY1_NUM2;
		enemy1_Time3 = enemy1_Time4;
	}

	enemy1_Time4 = clock();
	enemy1_Time2 = clock();
}

int load_Enemy1(int index_enemy1)
{
	int frames_enemy1 = 8;	//敌人1有八帧
	int time_Intervalenemy1 = 100;		//时间间隔100ms
	for (int j = 0; j < ENEMY1_NUM1; j++) {
		for (int i = 0; i < ENEMY1_NUM2; i++) {
			if (enemy1[j][i].live) {	//绘制敌人
				putimage(enemy1[j][i].x, enemy1[j][i].y, enemy1[j][i].width, enemy1[j][i].height, &img_enemy1[1], player.width * index_enemy1, 0, NOTSRCERASE);
				putimage(enemy1[j][i].x, enemy1[j][i].y, enemy1[j][i].width, enemy1[j][i].height, &img_enemy1[0], player.width * index_enemy1, 0, SRCERASE);
			}
		}
	}
	index_enemy1 = (clock() / time_Intervalenemy1) % frames_enemy1;
	return index_enemy1;
}

void enemy1_Move()
{
	for (int j = 0; j < ENEMY1_NUM1; j++) {
		for (int i = 0; i < ENEMY1_NUM2; i++) {
			if (enemy1[j][i].live) {
				if (j == 0) {
					enemy1[j][i].x -= enemy1_SpeedX;
					enemy1[j][i].y += enemy1_SpeedY;
				}
				else {
					enemy1[j][i].x += enemy1_SpeedX;
					enemy1[j][i].y += enemy1_SpeedY;
				}
				if (enemy1[j][i].x< IMG_BK2X || enemy1[j][i].x>IMG_BK2X + BKX - enemy1[j][i].width || enemy1[j][i].y< IMG_BK2Y || enemy1[j][i].y>IMG_BK2Y + BKY - enemy1[j][i].height) {
					enemy1[j][i].live = false;
				}
			}
		}
	}
}

void creat_Enemy1()
{
	for (int j = 0; j < ENEMY1_NUM1; j++) {
		for (int i = 0; i < ENEMY1_NUM2; i++) {
			if (!enemy1[j][i].live) {
				enemy1[j][i].live = true;
				enemy1[j][i].y = IMG_BK2Y;
				if (j == 0) {
					enemy1[j][i].x = IMG_BK2X + BKX * 3 / 8;
				}
				else {
					enemy1[j][i].x = IMG_BK2X + BKY * 5 / 8 - enemy1[j][i].width;
				}
				break;
			}
		}
	}
}

void Enemy()
{
	Enemy1();
}