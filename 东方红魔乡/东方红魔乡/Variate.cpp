#define BULLET_NUM 100

int index_player = 0;
int player_speed = 2;//����ٶ�
int directionx = 0;//x�᷽��
int directiony = 0;//y�᷽��
struct player//��ҽṹ��
{
	int x, y;
	int width;
	int height;
	bool live;
	int HP;
};
struct player player = { 0 };
struct bullet
{
	int x, y;
	int width;
	int height;
	bool live;
};
struct bullet bullet[BULLET_NUM] = { 0 };
struct enemy
{
	int x, y;
	int width;
	int height;
	bool live;
	int HP;
};