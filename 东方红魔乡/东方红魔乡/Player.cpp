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
	for (int i = 0; i < BULLET_NUM; i++) {
		if (player_Bullet[i].live) {//创建子弹
			putimage(player_Bullet[i].x, player_Bullet[i].y, player_Bullet[i].width, player_Bullet[i].height, img_playerbullet1 + 1, 130, 2, NOTSRCERASE);
			putimage(player_Bullet[i].x, player_Bullet[i].y, player_Bullet[i].width, player_Bullet[i].height, img_playerbullet1 + 0, 130, 2, SRCERASE);
		}
	}
}

void creat_Playerbullet()
{
	for (int i = 0; i < BULLET_NUM; i++) {
		if (!player_Bullet[i].live) {//创建子弹
			player_Bullet[i].live = true;
			player_Bullet[i].x = player.x + player.width / 2;
			player_Bullet[i].y = player.y - player.height / 4;
			break;
		}
	}
}

void bullet_Move()
{
	for (int i = 0; i < BULLET_NUM; i++) {
		if (player_Bullet[i].live) {
			player_Bullet[i].y -= BULLTESP;
			//player_Bullet[i + 1].y -= BULLTESP;
			if (player_Bullet[i].y < IMG_BK2Y) {
				player_Bullet[i].live = false;
				//player_Bullet[i + 1].live = false;
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