#ifndef __VARIATE_H_
#define __VARIATE_H_

#define BULLET_NUM 100
#define ENEMY1_NUM 100

//ֻ�����������ܸ���ֵ�����������������
extern int index_player;
extern int player_speed;//����ٶ�
extern int directionx;//x�᷽��
extern int directiony;//y�᷽��
extern int index_enemy1;
extern struct player//��ҽṹ��
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
