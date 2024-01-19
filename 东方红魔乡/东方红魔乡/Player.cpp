#include <graphics.h>
#include "Variate.h"
#include "Image.h"
#include <time.h>
#include "tools.hpp"

int load_Player(int index_player)
{
	int frames_player = 4;		//人物有四帧
	int time_Intervalplayer = 100;		//时间间隔100ms
	//图片去背景后还是有背景，就换了一个，没有动态效果了，但换了后发现会上下动，看着还行
	//putimage(player.x, player.y, player.width, player.height, img_player + 1, player.width * index_player, 0, NOTSRCERASE);
	//putimage(player.x, player.y, player.width, player.height, img_player + 0, player.width * index_player, 0, SRCERASE);
	drawImg(player.x, player.y, player.width, player.height, img_player + 0, player.width * index_player, 0);

	//drawImg(player.x, player.y, player.width, player.height, img_player + 0, player.width * index_player, 0);
	index_player = (clock() / time_Intervalplayer) % frames_player;
	return index_player;
}

void load_Playerbullet()
{
	for (int i = 0; i < BULLET_NUM1; i++) {
		for (int j = 0; j < BULLET_NUM2; j++) {
			if (player_Bullet[i][j].live) {//创建子弹
				putimage(player_Bullet[i][j].x, player_Bullet[i][j].y, player_Bullet[i][j].width, player_Bullet[i][j].height, img_playerbullet1 + 1, 130, 2, NOTSRCERASE);
				putimage(player_Bullet[i][j].x, player_Bullet[i][j].y, player_Bullet[i][j].width, player_Bullet[i][j].height, img_playerbullet1 + 0, 130, 2, SRCERASE);
			}
		}
	}
}

void creat_Playerbullet()
{
	for (int i = 0; i < BULLET_NUM1; i++) {
		for (int j = 0; j < BULLET_NUM2; j++) {
			if (!player_Bullet[i][j].live) {//创建子弹
				player_Bullet[i][j].live = true;
				player_Bullet[i][j].y = player.y - player.height / 4;
				if (i == 0) {
					player_Bullet[i][j].x = player.x;
				}
				else {
					player_Bullet[i][j].x = player.x + player.width - player_Bullet[i][j].width;
				}
				break;
			}

		}
	}
}

void bullet_Move()
{
	for (int i = 0; i < BULLET_NUM1; i++) {
		for (int j = 0; j < BULLET_NUM2; j++) {
			if (player_Bullet[i][j].live) {
				player_Bullet[i][j].y -= BULLETSPY;
				//if (i == 0) {
				//	player_Bullet[i][j].x -= BULLETSPX;
				//}
				//else {
				//	player_Bullet[i][j].x += BULLETSPX;
				//}
				if (player_Bullet[i][j].y < IMG_BK2Y) {
					player_Bullet[i][j].live = false;
				}
			}
		}
	}

}

void Player()
{
	index_player = load_Player(index_player);
	load_Playerbullet();
	bullet_Move();

	player.x += directionx * player_speed;
	player.y += directiony * player_speed;
}