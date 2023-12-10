#include <stdio.h>
#include <graphics.h>

IMAGE img_bk2;

void change_Background()
{
	loadimage(&img_bk2, "assets\\bk2.jpg");
	putimage(40, 34, &img_bk2);
}

void start_Game()
{
	while (1) {
		BeginBatchDraw();
		cleardevice();

		change_Background();

		EndBatchDraw();
	}
}