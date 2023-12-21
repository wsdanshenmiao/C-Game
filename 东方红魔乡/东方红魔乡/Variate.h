#ifndef __VARIATE_H_
#define __VARIATE_H_

#define BULLET_NUM 100
#define ENEMY1_NUM 100

//只声明变量不能赋初值，非则会声明并定义
extern int index_player;
extern int player_speed;//玩家速度
extern int directionx;//x轴方向
extern int directiony;//y轴方向
extern int index_enemy1;
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
extern struct bullet player_Bullet[BULLET_NUM];
extern struct enemy
{
	int x, y;
	int width;
	int height;
	bool live;
	int HP;
};
extern struct enemy enemy1[ENEMY1_NUM];

#endif
