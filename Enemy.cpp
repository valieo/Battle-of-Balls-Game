#include "Enemy.h"

int Enemy::num = 0;

Enemy::Enemy(float radius, Vector worldPosition, Vector velocityDirection) :Sprite(radius, worldPosition, velocityDirection) {
	scope = 100;
	num++;
};


void Enemy::Attack(Vector point) {
	SetVelocityDirection(point - worldPosition);
}
void Enemy::Flee(Vector point) {
	SetVelocityDirection(worldPosition - point);
}

bool Enemy::InScope(Vector point){
	if (worldPosition.GetDistance(point) < radius + scope) {
		return true;
	}
	else {
		return false;
	}
}

void Enemy::BeEaten(){
	SetVisible(false);
	num--;
}



Enemy* Enemy::CreateRandomly(){
	int radius = rand() % (ENEMY_MAX_RADIUS - ENEMY_MIN_RADIUS) + ENEMY_MIN_RADIUS;
	//随机坐标	
	Vector pos = Vector::Random(radius*2, radius*2, MAP_WIDTH - radius*2, MAP_HEIGTH - radius*2);

	Vector direction = Vector::RandomUnit();

	return new Enemy(radius, pos, direction);
}

int Enemy::EnemyNum(){
	return num;
}

void Enemy::SetNum(int num){
	Enemy::num = num;
}

void Enemy::ShowNum(){
	//显示剩余enemy数
	setTextBkColor(EMPTY);
	setTextColor(RGB(128, 128, 128));
	setTextSize(20);
	char detail[] = "Number of enemies: 0";
	detail[19] = num + 48;
	paintText(5, 5, detail);
}
