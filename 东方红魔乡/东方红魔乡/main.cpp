#include <graphics.h>
#include <stdio.h>
#include "start_Game.h"
#include "IMAGE.h"

#define WINWIDTH 1024
#define WINHEIGHT 768

ExMessage msg1 = { 0 };//������Ϣ�ṹ�����

void create_Background()
{
	loadimage(&img_bk1, "assets\\bk1.jpg");//��ʼ����
	putimage(0, 0, &img_bk1);
}

int within_Limits(int mx, int my, int x, int y, int w, int h)
{
	if (x < mx && mx < x + w && y < my && my < y + h) {
		return 1;
	}
	else {
		return 0;
	}
}

int botton(int x, int y, int width, int height, const char* text)//�жϰ�ť�Ƿ���
{
	int wspace = (width - textwidth(text)) / 2;
	int hspace = (height - textheight(text)) / 2;
	if (within_Limits(msg1.x, msg1.y, x, y, width, height)) {
		setfillcolor(RGB(51, 51, 51));
	}
	else {
		setfillcolor(RGB(0, 0, 0));

	}
	solidrectangle(x, y, x + width, y + height);//���ư�ť
	settextstyle(80, 0, "��������");
	settextcolor(RGB(215, 88, 117));
	outtextxy(x, y, text);//��������
	if (msg1.message == WM_LBUTTONDOWN && within_Limits(msg1.x, msg1.y, x, y, width, height)) {
		return 1;
	}
	else {
		return 0;
	}
}

int main()
{
	initgraph(WINWIDTH, WINHEIGHT);//��������
	cleardevice();
	setbkcolor(RGB(38, 0, 0));
	setbkmode(TRANSPARENT);

	while (1) {
		peekmessage(&msg1, EX_MOUSE);//��ȡ��Ϣ

		int x = 256 - textwidth("��ʼ��Ϸ") / 2;
		int y = 500;
		int width = textwidth("��ʼ��Ϸ");
		int height = textheight("��ʼ��Ϸ");

		BeginBatchDraw();
		cleardevice();

		create_Background();//��������
		if (botton(x, y, width, height, "��ʼ��Ϸ")) {//�жϰ�ť�Ƿ���
			printf("start game\n");
			start_Game();
		}
		if (botton(x + 512, y, width, height, "�˳���Ϸ")) {
			printf("end game\n");
			break;
		}
		msg1.message = 0;//��Ϣ����
		EndBatchDraw();
	}

	return 0;
}