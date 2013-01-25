//renctangle.h
//written by : Erik Arfvidson


#pragma once

#include<iostream>

#include"shape.h"

using namespace std;

class Rectangle : public Shape
{
public:
	Rectangle(int x, int y, int height, int width) : Shape (Black)
	{
		UpperLX = x;
		UpperLY = y;
		Height = height;
		Width = width;
	}

	void Move(int deltaX, int deltaY)
	{
		UpperLX += deltaX;
		UpperLY += deltaY;
	}

	virtual void Scale(float grow)
	{
		Height = int(Height*grow);
		Width = int(Width*grow);
	}

	virtual void Draw() const
	{
		cout<< "Rectangle at ("<<UpperLX<<", "<<UpperLY<<") of color "<< GetColor() << endl;
	}


	void SetColor(Color changeColor)
	{
		ShapeColor = changeColor;
	}
private:
	int UpperLX, UpperLY;
	int Height, Width;

};