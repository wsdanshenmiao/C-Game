#include <graphics.h>

IMAGE img_bk1;
IMAGE img_bk2;
IMAGE img_bk3[2];
IMAGE img_player[2];
IMAGE img_bullet[2];
struct player//玩家结构体
{
	int x, y;
	int width;
	int height;
	bool live;
	int HP;
};
struct player player;
struct bullet
{
	int x, y;
	int width;
	int height;
	bool live;
};
struct bullet bullet;