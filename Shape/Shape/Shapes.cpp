//Shapes.cpp
//written by:  ERik ARfvidson

#include<iostream>
#include "circle.h"


#include "rectangle.h"
#include "triangle.h"


#include <vector>

using namespace std;

void main()
{
	try
	{
		// INSERT shapes 
		vector<Shape*> shapes;

		Circle* myCircle = new Circle(1,0,5);

		shapes.push_back(myCircle);

		Rectangle* myRectangle = new Rectangle(1,2,5,5);

		shapes.push_back(myRectangle);

		Triangle* myTriangle = new Triangle(0,0,1,1,2,2);
		shapes.push_back(myTriangle);


		// Change shapes
		for( unsigned int i = 0; i < shapes.size(); i++)
		{
			cout << "Input color (0=red, 1= green, 2= blue, 3=black): ";
			int color;
			cin >> color;

			Color newColor;
			switch(color)

			{
			case Red:
				newColor = Red;

				break;			case Green:
				newColor = Green;
				break;

			case Blue:
				newColor = Blue;
				break;

			case Black:
				newColor = Black;

				break;
			default:
				throw "FAILED... to recognize color";
			}
			//Change color to the desire
			shapes[i]->SetColor(newColor);
		}


		//Move shape in the desired direction
		for(unsigned int i=0; i < shapes.size(); i++)
			shapes[i]->Move(1, 1);
		//Display SHapes
		for(unsigned int i=0; i < shapes.size(); i++)
			shapes[i]->Draw();


	}
	//exception
	catch(char* Exception)
	{
		cout << "Exception : " << Exception << endl << endl <<endl;

	}

	system("pause");

}
