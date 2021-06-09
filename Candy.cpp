#include "Candy.h"


Candy::Candy(float radius, float energy, Vector worldPosition) : Object(radius, worldPosition,Draw::RandomShape()) {
	this->energy = energy;
	rebornTime = REBORN_TIME;
}

float Candy::GetEnergy(){
	return energy;
}

void Candy::Reborn() {
	if (!GetVisible()) {
		if (rebornTime <= 0) {
			SetVisible(true);
		}
		else {
			--rebornTime;
		}
	}
}
void Candy::BeEaten() {
	SetVisible(false);
	rebornTime = REBORN_TIME;
}



Candy* Candy::CreateRandomly(){
	float radius = (float)(rand() % (CANDY_MAX_RADIUS - CANDY_MIN_RADIUS) + CANDY_MIN_RADIUS);
	//随机坐标(worldPosition)
	float size = 2 * radius;
	Vector pos = Vector::Random(size, size, MAP_WIDTH - size, MAP_HEIGTH - size);
	//energy取决于size
	float energy = radius * 0.8;

	return new Candy(radius, energy, pos);
}
