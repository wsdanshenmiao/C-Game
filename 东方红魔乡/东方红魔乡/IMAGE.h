#ifndef __IMAGE_H_
#define __IMAGE_H_

#define BULLET_NUM 100

extern IMAGE img_bk1;
extern IMAGE img_bk2;
extern IMAGE img_bk3[2];
extern IMAGE img_player[2];
extern IMAGE img_bullet[2];
extern struct player//玩家结构体
{
	int x, y;
	bool live;
	int width;
	int height;
	int HP;
};
extern struct player player;
extern struct bullet
{
	int x, y;
	int width;
	int height;
	bool live;
};
extern struct bullet bullet[BULLET_NUM];

#endif 
