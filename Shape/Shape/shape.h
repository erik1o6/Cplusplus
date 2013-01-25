//Shape.h
//written by : Erik Arfvidson


#pragma once

#include<iostream>

using namespace std;

//Selected colors
enum Color 
{
	Red, 
	Green, 
	Blue, 
	Black
}; 

class Shape
{
public:
	Shape(Color color)
	{
		ShapeColor = color;
	}

	//MOVE function
	virtual void Move(int deltaX, int deltaY) = 0;

	//ScaleFunction
	virtual void Scale(float grow) = 0;

	//Draw Function
	virtual void Draw() const

	{
		cout<< "Shape of color" << GetColor() << endl;
	}

	//SetColor function
	void SetColor(Color changeColor)

	{
		ShapeColor = changeColor;
	}

protected:

	char* GetColor() const
	{
		switch(ShapeColor)
		{

		case Red:
			return "Red";
		case Green:
			return "Green";
		case Blue:
			return "Blue";
		case Black:
			return "Black";
		default:
			throw "FAiled to find the color :";
		}

	}

	Color ShapeColor;


};