#pragma once
#include"tool.h"

//��Ϸ�е���������

class Object {
private:
	bool visible;
	Shape shape;
	ACL_Color color;
protected:
	float radius;
	//�ѿ�������任��localPosition = worldPosition - relativePosition		
	Vector worldPosition;		//��������  ��������Ϸ������ͼ�е�����
	Vector localPosition;		//�ֲ�����	����Ϸ�����е�����
	static Vector relativePosition;	//��Ϸ���ڵ�ԭ��������������Ϸ�����е�����
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
	Vector GetLocalPosition(Vector point);		//����һ������ڵ�point������
	static Vector GetRelativePos();
};

