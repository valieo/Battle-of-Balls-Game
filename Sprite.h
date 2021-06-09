#pragma once
#include "Object.h"


class Sprite :public Object {
protected:
	Vector velocity;
public:
	//默认位置为游戏场景的中央，速度大小为0
	Sprite(float radius, Vector worldPosition = Vector(MAP_WIDTH / 2, MAP_HEIGTH / 2), Vector velocityDirection = Vector(0.0, 0.0));
	//速度的大小	取决于半径
	float GetSpeedValue();
	Vector GetVelocity();
	void SetVelocityDirection(Vector direction);
	virtual void BeEaten();
	virtual void Move();
	static Sprite* CreateRandomly();
};
