#pragma once
#include"tool.h"

//游戏中的所有物体

class Object {
private:
	bool visible;
	Shape shape;
	ACL_Color color;
protected:
	float radius;
	//笛卡尔坐标变换：localPosition = worldPosition - relativePosition		
	Vector worldPosition;		//世界坐标  在整个游戏场景地图中的坐标
	Vector localPosition;		//局部坐标	在游戏窗口中的坐标
	static Vector relativePosition;	//游戏窗口的原点坐标在整个游戏场景中的坐标
	void SetVisible(bool visible);
public:
	Object();
	Object(float radius, Vector worldPosition, Shape shape = circle, ACL_Color color = Draw::RandomColor());
	virtual void Display();
	bool GetVisible();
	Shape GetShape();
	ACL_Color GetColor();
	float GetRadius();
	Vector GetWorldPosition();
	Vector GetLocalPosition(Vector point);		//返回一个相对于点point的坐标
	static Vector GetRelativePos();
};

