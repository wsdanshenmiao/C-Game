#include <graphics.h>

IMAGE img_bk1;
IMAGE img_bk2;
IMAGE img_bk3[2];
IMAGE img_player[2];
struct player//玩家结构体
{
	int x, y;
	bool live;
	int width;
	int height;
	int HP;
};
struct player player;