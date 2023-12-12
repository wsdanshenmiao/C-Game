#ifndef __IMAGE_H_
#define __IMAGE_H_

extern IMAGE img_bk1;
extern IMAGE img_bk2;
extern IMAGE img_bk3[2];
extern IMAGE img_player[2];
extern struct player//玩家结构体
{
	int x, y;
	bool live;
	int width;
	int height;
	int HP;
};
extern struct player player;

#endif 
