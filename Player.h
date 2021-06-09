#pragma once
#include"Candy.h"
#include"Enemy.h"



//玩家
class Player :public Sprite {
private:
	int immuneTime;		//游戏刚开始时的无敌时间
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
