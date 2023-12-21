#include <graphics.h>

#define IMG_BK2X 40
#define IMG_BK2Y 34

IMAGE img_bk1;
IMAGE img_bk2;
IMAGE img_bk3[2];
IMAGE img_player[2];
IMAGE img_bullet[2];

void load_Image()
{	
	loadimage(&img_bk2, "assets\\bk2.jpg");
	loadimage(img_bk3 + 0, "assets\\bk3-1.jpg");
	loadimage(img_bk3 + 1, "assets\\bk3-2.jpg");

	loadimage(img_player + 0, "assets\\博丽灵梦（红魔乡自机像素绘）.png");
	//loadimage(img_player + 0, "assets\\player.jpg");
	//loadimage(img_player + 1, "assets\\player_a.jpg");
	loadimage(img_bullet + 0, "assets\\player.png");
	loadimage(img_bullet + 1, "assets\\player_a.png");
}
void change_Background()
{
	int a = 256;
	int b = 128;
	putimage(IMG_BK2X, IMG_BK2Y, &img_bk2);
	putimage(730, 480, a, a, img_bk3 + 1, a, a, NOTSRCERASE);//先绘制掩码图
	putimage(730, 480, a, a, img_bk3 + 0, a, a, SRCERASE);//再绘制原图
	putimage(700, 440, a, b, img_bk3 + 1, 0, 0, NOTSRCERASE);//先绘制掩码图
	putimage(700, 440, a, b, img_bk3 + 0, 0, 0, SRCERASE);//再绘制原图
	putimage(790, 540, b, b, img_bk3 + 1, a, 0, NOTSRCERASE);//先绘制掩码图
	putimage(790, 540, b, b, img_bk3 + 0, a, 0, SRCERASE);//再绘制原图
	putimage(750, 640, b, b, img_bk3 + 1, 384, 0, NOTSRCERASE);//先绘制掩码图
	putimage(750, 640, b, b, img_bk3 + 0, 384, 0, SRCERASE);//再绘制原图
	putimage(890, 640, b, b, img_bk3 + 1, 0, b, NOTSRCERASE);//先绘制掩码图
	putimage(890, 640, b, b, img_bk3 + 0, 0, b, SRCERASE);//再绘制原图
}