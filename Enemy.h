#pragma once
#include "Sprite.h"
class Enemy :public Sprite{
private:
	float scope;
	static int num;
public:
	Enemy(float radius, Vector worldPosition, Vector velocityDirection);
	void Attack(Vector point);		//��point���ƶ�
	void Flee(Vector point);		//����point��
	bool InScope(Vector point);		//�жϵ�point�Ƿ�����Ұ��Χ��
	void BeEaten();
	static Enemy* CreateRandomly();
	static int EnemyNum();
	static void SetNum(int num);
	static void ShowNum();
};

