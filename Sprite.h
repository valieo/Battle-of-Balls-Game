#pragma once
#include "Object.h"


class Sprite :public Object {
protected:
	Vector velocity;
public:
	//Ĭ��λ��Ϊ��Ϸ���������룬�ٶȴ�СΪ0
	Sprite(float radius, Vector worldPosition = Vector(MAP_WIDTH / 2, MAP_HEIGTH / 2), Vector velocityDirection = Vector(0.0, 0.0));
	//�ٶȵĴ�С	ȡ���ڰ뾶
	float GetSpeedValue();
	Vector GetVelocity();
	void SetVelocityDirection(Vector direction);
	virtual void BeEaten();
	virtual void Move();
	static Sprite* CreateRandomly();
};
