//Circle.h
//written by : Erik Arfvidson


#pragma once

#include<iostream>

#include"shape.h"

using namespace std;

//Circle shape
class Circle: public Shape
{
public:
	Circle(int x, int y, int radius) : Shape(Black)
	{
		CenterX = x;
		CenterY = y;

		Radius = radius;
	}

	void Move(int deltaX, int deltaY)
	{
		CenterX += deltaX;
		CenterY += deltaY;


	}

	virtual void Scale(float grow)
	{

		Radius = int(Radius*grow);
	}

	virtual void Draw() const
	{
		cout<< "circle at (" << CenterX << "," << CenterY << ") is of color " << GetColor() << endl;
	}

private:
	int CenterX, CenterY;
	int Radius;
};