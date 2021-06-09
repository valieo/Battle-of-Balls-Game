#include "Background.h"

Background::Background():Object(){}

void Background::Display(){

	//地图背景颜色
	setPenColor(RGB(61, 59, 81));
	setBrushColor(RGB(61, 59, 81));
	rectangle(0, 0, WIDTH, HEIGTH);

	//地图网格 网格边长为delta = 20
	int delta = 20;
	int x = Object::GetRelativePos().GetX();
	int y = Object::GetRelativePos().GetY();
	int dx = delta - x % delta;
	int dy = delta - y % delta;
	setPenColor(RGB(67, 65, 87));
	for (int i = dy; i < MAP_HEIGTH; i += delta) {
		line(0, i, WIDTH, i);
	}
	for (int i = dx; i < MAP_WIDTH; i += delta) {
		line(i, 0, i, HEIGTH);
	}

	//窗口边缘虚化效果
	//边界30个像素,画30个边框(矩形)，每个边框相差RGB(1,1,2)
	//边界线渐变颜色:RGB(60, 58, 80)->RGB(22, 22, 34)
	int lineSum = 30;
	int r, g, b;
	int x1, y1, x2, y2;
	r = 60;
	g = 58;
	b = 80;
	x1 = lineSum - 1;
	y1 = lineSum - 1;
	x2 = WIDTH - lineSum + 1;
	y2 = HEIGTH - lineSum + 1;
	for (int i = 0; i < lineSum; i++)
	{
		setPenColor(RGB(r, g, b));
		setBrushColor(EMPTY);
		rectangle(x1, y1, x2, y2);
		--r;
		--g;
		--b;
		--x1;
		--y1;
		++x2;
		++y2;
	}


	//画地图边界
	localPosition = worldPosition - Object::GetRelativePos();
	Vector rightPosition = Vector(MAP_WIDTH, MAP_HEIGTH) - Object::GetRelativePos();	//地图右下角坐标
	int leftX = localPosition.GetX();
	int leftY = localPosition.GetY();
	int rightX = rightPosition.GetX();
	int rightY = rightPosition.GetY();
	setPenColor(RED);
	setBrushColor(EMPTY);
	for (int i = 0; i < 5; ++i) {
		line(leftX - i, leftY - i, rightX + i, leftY - i);		//up
		line(leftX - i, rightY + i, rightX + i, rightY + i);	//down
		line(leftX - i, leftY - i, leftX - i, rightY + i);		//left
		line(rightX + i, leftY - i, rightX + i, rightY + i);	//right
	}
}
