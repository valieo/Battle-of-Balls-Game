#include "Background.h"

Background::Background():Object(){}

void Background::Display(){

	//��ͼ������ɫ
	setPenColor(RGB(61, 59, 81));
	setBrushColor(RGB(61, 59, 81));
	rectangle(0, 0, WIDTH, HEIGTH);

	//��ͼ���� ����߳�Ϊdelta = 20
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

	//���ڱ�Ե�黯Ч��
	//�߽�30������,��30���߿�(����)��ÿ���߿����RGB(1,1,2)
	//�߽��߽�����ɫ:RGB(60, 58, 80)->RGB(22, 22, 34)
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


	//����ͼ�߽�
	localPosition = worldPosition - Object::GetRelativePos();
	Vector rightPosition = Vector(MAP_WIDTH, MAP_HEIGTH) - Object::GetRelativePos();	//��ͼ���½�����
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
