#include"tool.h"


Vector Vector::GetUnit() {
	Vector v(0.0, 0.0);
	float norm = GetNorm();
	if (norm != 0) {
		v.x = x / norm;
		v.y = y / norm;
	}
	return v;
}

Vector Vector::RandomUnit(){
	int x = rand() % 1001 - 500;
	int y = rand() % 1001 - 500;
	return Vector((float)x,(float)y).GetUnit();
}

Vector Vector::Random(int xmin, int ymin, int xmax, int ymax){
	int deltaX = xmax - xmin + 1;
	int deltaY = ymax - ymin + 1;
	float x = xmin + rand() % deltaX;
	float y = ymin + rand() % deltaY;
	return Vector(x, y);
}

float Vector::GetNorm() {
	return sqrt(x * x + y * y);
}
float Vector::GetDistance(Vector v) {
	Vector d = *this - v;
	return d.GetNorm();
}

Vector Vector::GetAbs()
{
	return Vector(x >= 0 ? x : -x, y >= 0 ? y : -y);
}

void Vector::SetXY(float x, float y) {
	this->x = x;
	this->y = y;
}
void Vector::AddDelta(Vector& delta) {
	x += delta.GetX();
	y += delta.GetY();
}

Vector Vector::operator+(Vector v) {
	Vector s(x + v.x, y + v.y);
	return s;
}
Vector Vector::operator-(Vector v) {
	Vector s(x - v.x, y - v.y);
	return s;
}
Vector Vector::operator*(Vector v) {
	Vector s(x * v.x, y * v.y);
	return s;
}











void Square(int size, Vector& position, ACL_Color color) {
	int x = position.GetX();
	int y = position.GetY();
	beginPaint();
	setPenColor(color);
	setBrushColor(color);
	rectangle(x - size, y - size, x + size, y + size);
	endPaint();
}

void Draw::Circle(int radius, Vector& position, ACL_Color color){
	int leftX = position.GetX() - radius;
	int leftY = position.GetY() - radius;
	int rightX = leftX + 2 * radius;
	int rightY = leftY + 2 * radius;
	setPenColor(color);
	setBrushColor(color);
	ellipse(leftX, leftY, rightX, rightY);
}


void Draw::Square(int radius, Vector& position, ACL_Color color) {
	int x = position.GetX() - radius;
	int y = position.GetY() - radius;
	setPenColor(color);
	setBrushColor(color);
	rectangle(x, y, x + 2 * radius, y + 2 * radius);
}



ACL_Color Draw::RandomColor()
{
	int r = rand() % 256;
	int g = rand() % 256;
	int b = rand() % 256;
	return RGB(r, g, b);
}

Shape Draw::RandomShape(){
	int x = rand() % 100;
	if (x >= 50) {
		return circle;
	}
	else {
		return square;
	}
}

void Draw::DrawShape(int radius, Vector& position, Shape shape, ACL_Color color){
	if (shape == circle) {
		Circle(radius, position, color);
	}
	else {
		Square(radius, position, color);
	}
}
