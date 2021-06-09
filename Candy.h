#pragma once
#include "Object.h"


//食物
class Candy :public Object {
private:
	float energy;
	int rebornTime;	//被吃掉后经过rebornTime时间后重新出现
public:
	Candy(float radius, float energy, Vector worldPosition);
	float GetEnergy();
	void Reborn();
	void BeEaten();
	static Candy* CreateRandomly();
};
