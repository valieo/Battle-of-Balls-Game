#pragma once
#include<math.h>
#include<stdlib.h>
#include"acllib.h"


//candy������ʱ��
#define REBORN_TIME 500
//��ͼ�봰�ڴ�С
#define MAP_WIDTH 1500
#define MAP_HEIGTH 1500
#define WIDTH 1000
#define HEIGTH 600
//�뾶��Χ
#define PLAYER_MAX_RADIUS 200
#define CANDY_MAX_RADIUS 10
#define CANDY_MIN_RADIUS 5
#define SPRITE_MAX_RADIUS 25
#define SPRITE_MIN_RADIUS 15
#define ENEMY_MIN_RADIUS 30
#define ENEMY_MAX_RADIUS 100


//��ά����/����
class Vector {
private:
	float x;
	float y;

public:
	Vector() { x = 0; y = 0; }
	Vector(int a, int b) { x = a; y = b; }
	Vector(const Vector& v) { x = v.x; y = v.y; }



	float GetX() { return x; }
	float GetY() { return y; }
	float GetNorm();			//��С
	float GetDistance(Vector v);
	Vector GetAbs();		//��x��y����Ϊ����
	Vector GetUnit();
	

	void SetXY(float x, float y);
	void AddDelta(Vector& delta);

	Vector operator + (Vector v);
	Vector operator - (Vector v);
	Vector operator * (Vector v);

	static Vector RandomUnit();		//�������һ����λ����
	static Vector Random(int xmin, int ymin, int xmax, int ymax);
};

typedef enum Shpae{circle,square}Shape;
//��ͼ
static class Draw {
public:
	static void Circle(int radius, Vector& position, ACL_Color color);
	static void Square(int radius, Vector& position, ACL_Color color);		//radius�ǰ�߳�
	static ACL_Color RandomColor();
	static Shape RandomShape();
	static void DrawShape(int radius, Vector& position, Shape shape, ACL_Color color);
};