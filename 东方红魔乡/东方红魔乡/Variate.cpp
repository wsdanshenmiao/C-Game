#define BULLET_NUM 100
#define ENEMY1_NUM 100

int index_player = 0;
int player_speed = 2;//玩家速度
int directionx = 0;//x轴方向
int directiony = 0;//y轴方向
int index_enemy1 = 0;
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
struct bullet player_Bullet[BULLET_NUM] = { 0 };
struct enemy
{
	int x, y;
	int width;
	int height;
	bool live;
	int HP;
};
struct enemy enemy1[ENEMY1_NUM];