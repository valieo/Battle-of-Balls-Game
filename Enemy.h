#pragma once
#include "Sprite.h"
class Enemy :public Sprite{
private:
	float scope;
	static int num;
public:
	Enemy(float radius, Vector worldPosition, Vector velocityDirection);
	void Attack(Vector point);		//向point点移动
	void Flee(Vector point);		//逃离point点
	bool InScope(Vector point);		//判断点point是否在视野范围内
	void BeEaten();
	static Enemy* CreateRandomly();
	static int EnemyNum();
	static void SetNum(int num);
	static void ShowNum();
};

