#include <graphics.h>
#include <time.h>
#include "Variate.h"
#include "Image.h"

int load_Enemy1(int index_enemy1)
{
	int frames_enemy1 = 8;	//敌人1有八帧
	int time_Intervalenemy1 = 100;		//时间间隔100ms
	for (int i = 0; i < ENEMY1_NUM; i++) {
		if (enemy1[i].live) {	//绘制敌人
			putimage(enemy1[i].x, enemy1[i].y, enemy1[i].width, enemy1[i].height, &img_enemy1[1], player.width * index_enemy1, 0, NOTSRCERASE);
			putimage(enemy1[i].x, enemy1[i].y, enemy1[i].width, enemy1[i].height, &img_enemy1[0], player.width * index_enemy1, 0, SRCERASE);
		}
	}
	index_enemy1 = (clock() / time_Intervalenemy1) % frames_enemy1;
	return index_enemy1;
}

void enemy1_Move()
{
	for (int i = 0; i < ENEMY1_NUM; i++) {
		if (enemy1[i].live) {	//绘制敌人
			enemy1[i].x++;
			enemy1[i].y++;
		}
	}
}

void Enemy()
{
	index_enemy1 = load_Enemy1(index_enemy1);
	enemy1_Move();
}