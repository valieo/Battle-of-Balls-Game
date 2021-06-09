#include "Player.h"


//player的localPosition是固定的，一直是在窗口中央
Player::Player(int radius) :Sprite(radius) {
	immuneTime = 60;	//3 seconds
	localPosition = Vector(WIDTH / 2, HEIGTH / 2);
	Object::relativePosition = worldPosition - localPosition;
	destination = worldPosition;
}

void Player::SetDestination(Vector worldDestination) {
	
	this->destination = worldDestination;
	SetVelocityDirection(destination - worldPosition);		//速度方向：指向目标点
	
}


void Player::SetSpeedZero(){
	velocity = Vector(0, 0);
}

void Player::Move(){
	if (immuneTime > 0)immuneTime--;
	float x = worldPosition.GetX();
	float y = worldPosition.GetY();
	//碰到边界
	if (x + radius > MAP_WIDTH) {
		velocity = velocity * Vector(-1, 1);
		worldPosition.SetXY(MAP_WIDTH - radius, y);
	}
	else if (x - radius < 0) {
		velocity = velocity * Vector(-1, 1);
		worldPosition.SetXY(radius, y);
	}
	else if (y + radius > MAP_HEIGTH) {
		velocity = velocity * Vector(1, -1);
		worldPosition.SetXY(x, MAP_HEIGTH - radius);
	}
	else if (y - radius < 0) {
		velocity = velocity * Vector(1, -1);
		worldPosition.SetXY(x, radius);
	}
	//更新位置
	else {
		worldPosition.AddDelta(velocity);
	}
	localPosition = Vector(WIDTH / 2, HEIGTH / 2);
	Object::relativePosition = worldPosition - localPosition;
}




void Player::Eat(Candy& candy) {
	float distance = worldPosition.GetDistance(candy.GetWorldPosition());
	if (candy.GetVisible() && distance < radius) {
		candy.BeEaten();
		if (radius < PLAYER_MAX_RADIUS) {	
			radius += sqrt(candy.GetEnergy())/2;
		}
	}
}
void Player::Eat(Enemy& enemy) {
	float distance = worldPosition.GetDistance(enemy.GetWorldPosition());
	if (enemy.GetVisible() && distance < radius) {
		if (enemy.GetRadius() < radius) {
			enemy.BeEaten();
			if (radius < PLAYER_MAX_RADIUS) {
				radius += sqrt(enemy.GetRadius())/2;
			}
		}
		else {
			Die();
		}
	}
}
void Player::Eat(Sprite& sprite) {
	float distance = worldPosition.GetDistance(sprite.GetWorldPosition());
	if (sprite.GetVisible() && distance < radius ) {
		if (sprite.GetRadius() < radius) {
			sprite.BeEaten();
			if (radius < PLAYER_MAX_RADIUS) {
				radius += sqrt(sprite.GetRadius());
			}
		}
	}
}

void Player::Die(){
	if (immuneTime <= 0) {
		SetVisible(false);
		velocity = Vector(0, 0);
	}
}

bool Player::IsDead(){
	return !GetVisible();
}

bool Player::Immune(){
	return immuneTime>0;
}

void Player::ShowImmuneTime(){
	if (immuneTime > 0) {
		setTextBkColor(EMPTY);
		setTextColor(RGB(128, 128, 128));
		setTextSize(20);
		char detail[] = "Seconds of invulnerability: 4";
		detail[28] = immuneTime * 50/1000 + 49;
		paintText(5, 30, detail);
	}
}

