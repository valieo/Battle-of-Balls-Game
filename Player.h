#pragma once
#include"Candy.h"
#include"Enemy.h"



//���
class Player :public Sprite {
private:
	int immuneTime;		//��Ϸ�տ�ʼʱ���޵�ʱ��
	Vector destination;
public:
	Player(int radius);

	void SetDestination(Vector worldDestination);
	void SetSpeedZero();
	void Move();
	void Eat(Candy& candy);
	void Eat(Enemy& enemy);
	void Eat(Sprite& sprite);
	void Die();
	bool IsDead();
	bool Immune();
	void ShowImmuneTime();
};
