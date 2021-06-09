#pragma once
#include "Object.h"


//ʳ��
class Candy :public Object {
private:
	float energy;
	int rebornTime;	//���Ե��󾭹�rebornTimeʱ������³���
public:
	Candy(float radius, float energy, Vector worldPosition);
	float GetEnergy();
	void Reborn();
	void BeEaten();
	static Candy* CreateRandomly();
};
