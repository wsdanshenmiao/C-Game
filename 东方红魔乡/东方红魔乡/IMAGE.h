#ifndef __IMAGE_H_
#define __IMAGE_H_

#define IMG_BK2X 40
#define IMG_BK2Y 34

extern IMAGE img_bk1;
extern IMAGE img_bk2;
extern IMAGE img_bk3[2];
extern IMAGE img_player[2];
extern IMAGE img_bullet[2];

void load_Image();
void change_Background();

#endif 