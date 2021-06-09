#include "Sprite.h"




Sprite::Sprite(float radius, Vector worldPosition, Vector direction): Object(radius, worldPosition) {
	float value = GetSpeedValue();
	velocity = direction.GetUnit() * Vector(value, value);
	localPosition = worldPosition - Object::relativePosition;
}


void Sprite::BeEaten(){
	SetVisible(false);
}

float Sprite::GetSpeedValue()
{	float v = 13.2 - 0.05 * radius;				//radius最大是200
	return v;
}

Vector Sprite::GetVelocity(){
	return velocity;
}

void Sprite::SetVelocityDirection(Vector direction){
	float value = GetSpeedValue();
	velocity = direction.GetUnit() * Vector(value, value);
}





void Sprite::Move() {
	float x = worldPosition.GetX();
	float y = worldPosition.GetY();
	//碰到边界反弹
	if (x + radius >= MAP_WIDTH || x - radius <= 0) {
		velocity = velocity * Vector(-1, 1);
	}
	if (y + radius >= MAP_HEIGTH || y - radius <= 0) {
		velocity = velocity * Vector(1, -1);
	}
	//更新位置
	worldPosition.AddDelta(velocity);
	localPosition = worldPosition - Object::relativePosition;
}



Sprite* Sprite::CreateRandomly() {
	int radius = rand() % (SPRITE_MAX_RADIUS - SPRITE_MIN_RADIUS) + SPRITE_MIN_RADIUS;
	//随机坐标	
	Vector pos = Vector::Random(radius * 2, radius * 2, MAP_WIDTH - radius * 2, HEIGTH - radius * 2);

	Vector direction = Vector::RandomUnit();

	return new Sprite(radius, pos, direction);
}


