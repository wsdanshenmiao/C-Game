#define BULLET_NUM 100
#define ENEMY1_NUM1 2
#define ENEMY1_NUM2 10
#define IMG_BK2X 40
#define IMG_BK2Y 34
#define WINWIDTH 1024
#define WINHEIGHT 768
#define BULLTESP 4
#define BKX 660
#define BKY 700

int index_player = 0;
int player_speed = 2;//����ٶ�
int directionx = 0;//x�᷽��
int directiony = 0;//y�᷽��
int index_enemy1 = 0;
int enemy1_SpeedX = 1; 
int enemy1_SpeedY = 2;

struct player//��ҽṹ��
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
struct enemy enemy1[ENEMY1_NUM1][ENEMY1_NUM2];