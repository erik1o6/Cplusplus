//Triangle.h
//Written by: ERik Arfvidson

#pragma once

#include<iostream>

#include"shape.h"

class Triangle : public Shape
{
public:
	//Required Points
	Triangle(int x1, int y1, int x2, int y2, int x3, int y3) : Shape(Black)
	{
		//X
		X1 = x1;
		X2 = x2;
		X3 = x3;
		//Y
		Y1 = y1;
		Y2 = y2;
		Y3 = y3;


	}

	//MOVE TRIANGLE
	virtual void Move(int deltaX, int deltaY)
	{

		//X
		X1 += deltaX;
		X2 += deltaX;
		X3 += deltaX;
		//Y
		Y1 += deltaY;
		Y2 += deltaY;
		Y3 += deltaY;

	}

	//SCALE TRIANGLE
	virtual void Scale(float grow)
	{
		X2 = X1 + int( grow*(X2-X1) );
		X3 = X1 + int( grow*(X2-X1) );

		Y2 = Y1 + int( grow*(Y2-Y1) );
		Y3 = Y1 + int( grow*(Y2-Y1) );
	}

	//Draw Shape
	virtual void Draw() const
	{
		cout<< " The triangle is at ("<<X1<<", "<<Y1<<") and is of color "<< GetColor() << endl;

	}

	int X1,Y1,X2,Y2,X3,Y3;
};