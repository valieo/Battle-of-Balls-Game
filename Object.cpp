#include"Object.h"

//初始化视图窗口在整个游戏场景的中央位置		localPosition = worldPosition - relativePosition
Vector Object::relativePosition = Vector((MAP_WIDTH - WIDTH) / 2, (MAP_HEIGTH - HEIGTH) / 2);

Object::Object() {
	visible = true;
	radius = 0;
	this->worldPosition = Vector(0, 0);
	localPosition = worldPosition - Object::relativePosition;
	color = BLACK;
	shape = circle;
}
Object::Object(float radius, Vector worldPosition, Shape shape, ACL_Color color) {
	visible = true;
	this->radius = radius;
	this->worldPosition = worldPosition;
	localPosition = worldPosition - Object::relativePosition;
	this->color = color;
	this->shape = shape;
}


void Object::SetVisible(bool visible) {
	this->visible = visible;
}

void Object::Display() {
	if (visible) {
		localPosition = worldPosition - relativePosition;
		Draw::DrawShape(radius, localPosition, shape, color);
	}
}

bool Object::GetVisible(){
	return visible;
}

Shape Object::GetShape(){
	return shape;
}

ACL_Color Object::GetColor(){
	return color;
}

float Object::GetRadius(){
	return radius;
}

Vector Object::GetWorldPosition() {
	return worldPosition;
}

Vector Object::GetLocalPosition(Vector point){
	return localPosition;
}

Vector Object::GetRelativePos(){
	return relativePosition;
}

