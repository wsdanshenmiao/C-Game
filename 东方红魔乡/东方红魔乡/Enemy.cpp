#include <graphics.h>
#include <time.h>
#include <stdlib.h>
#include "Variate.h"
#include "Image.h"
#include "Game.h"

int load_Enemy1(int index_enemy1)
{
	int frames_enemy1 = 8;	//����1�а�֡
	int time_Intervalenemy1 = 100;		//ʱ����100ms
	for (int j = 0; j < ENEMY1_NUM1; j++) {
		for (int i = 0; i < ENEMY1_NUM2; i++) {
			if (enemy1[j][i].live) {	//���Ƶ���
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
				if (j == 0) {	//��ߵĵ���1����
					enemy1[j][i].x -= enemy1_SpeedX;
					enemy1[j][i].y += enemy1_SpeedY;
				}
				else {	//�ұߵ�����
					enemy1[j][i].x += enemy1_SpeedX;
					enemy1[j][i].y += enemy1_SpeedY;
				}
				//�����߽����ʧ
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
				enemy1[j][i].HP = 2;
				enemy1[j][i].y = IMG_BK2Y;
				if (j == 0) {
					enemy1[j][i].x = IMG_BK2X + BKX * 3 / 8;	//��ߵĵ���1
				}
				else {
					enemy1[j][i].x = IMG_BK2X + BKY * 5 / 8 - enemy1[j][i].width;	//�ұߵ�
				}
				break;
			}
		}
	}
}

void Enemy1()
{
	static DWORD enemy1_Time1, enemy1_Time2;	//����1֮����ֵ�ʱ��
	static DWORD enemy1_Time3, enemy1_Time4;	//����1ÿ�����ֵ�ʱ��
	static int enemies1_Appears = ENEMY1_NUM1 * ENEMY1_NUM2;		//ÿ�����ֵĵ���1

	index_enemy1 = load_Enemy1(index_enemy1);
	enemy1_Move();

	if (enemies1_Appears) {
		if (enemy1_Time2 - enemy1_Time1 > 200) {	//û200�������һ������1
			creat_Enemy1();
			enemy1_Time1 = enemy1_Time2;
			enemies1_Appears--;		//ÿ��ʣ��ĵ���1
		}
	}
	if (enemy1_Time4 - enemy1_Time3 > 10000) {	//û10�����һ������1
		enemies1_Appears = ENEMY1_NUM1 * ENEMY1_NUM2;	//���¼��ص���1
		enemy1_Time3 = enemy1_Time4;
	}

	enemy1_Time4 = clock();
	enemy1_Time2 = clock();
}

void defeat_Enemy1()
{
	for (int i = 0; i < ENEMY1_NUM1; i++) {
		for (int j = 0; j < ENEMY1_NUM2; j++) {
			for (int a = 0; a < BULLET_NUM1; a++) {
				for (int b = 0; b < BULLET_NUM2; b++) {
					if (enemy1[i][j].x < player_Bullet[a][b].x
						&& player_Bullet[a][b].x < enemy1[i][j].x + enemy1[i][j].width
						&& enemy1[i][j].y < player_Bullet[a][b].y
						&& player_Bullet[a][b].y < enemy1[i][j].x + enemy1[i][j].height
						&& player_Bullet[a][b].live == true
						&& enemy1[i][j].live == true) {
						enemy1[i][j].HP--;
						player_Bullet[a][b].live = false;
					}
					if (enemy1[i][j].HP <= 0) {
						enemy1[i][j].live = false;
					}
				}
			}
		}
	}
}

void Enemy()
{
	Enemy1();
	defeat_Enemy1();
}