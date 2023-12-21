#include <graphics.h>
#include "Variate.h"
#include "Image.h"
#include <time.h>
#include "tools.hpp"

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

void bullet_Move()
{
	for (int i = 0; i < BULLET_NUM; i++) {
		if (bullet[i].live) {
			bullet[i].y -= 4;
			//bullet[i + 1].y -= 4;
			if (bullet[i].y < IMG_BK2Y) {
				bullet[i].live = false;
				//bullet[i + 1].live = false;
			}
		}
	}

}

void Player()
{
	index_player = load_Player(index_player);
	load_Bullet();
	bullet_Move();

	player.x += directionx * player_speed;
	player.y += directiony * player_speed;
}