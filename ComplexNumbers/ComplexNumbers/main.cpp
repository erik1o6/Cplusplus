// main.cpp - Complex type testing main program entry point
//Written by Erik Arfvidson

#include <iostream>
#include "complex.h"
#include <string>

using namespace std;

void main()
{
	//a is an object; an object is an instance of the class
	//user defined type Complex IS a class
	Complex<double> a(3,4), b(10,20);
	
	/* Changed to a(real,imagenay)
	//. is an operator, member access operator
	a.Re=1;
	a.Im=2;
	b.Re=10;
	b.Im=20;
	*/

	//c=a.+(b)


	//c = a. + (b);
	// +-*/ operations
	Complex<double> c = a + b;
	Complex<double> d = a - b;
	Complex<double> multiplication = a * b;
	Complex<double> division = a / b;
	string yesEqual = "NO"; if(a==a) {yesEqual= "Yes";}
	string notEqual = "NO"; if(a!=b) {notEqual= "Yes";}
	float abs = a.Absolute();
	
	a+=b;
	Complex<double> ty= a;
	ty-=b;
	//
	Complex<double> ta(3,4);
	Complex<double> tb(10,20);
	ta*=tb;
	
	Complex<double> tn= ta;
	tn/=b;
	//Complex e = a * b;
	//Complex f = a / b;
	// output test for Complex to Complex Operations
	cout<<"	   Welcome to the Complex Number Program"<<endl;
	cout<< "		Complex to Complex Operations"<<endl;
	cout<< "		  Written by: Erik Arfvidson"<<endl;
	cout<< "Absolute value of a is :"<<abs <<endl;
	cout << "Addition Test" << endl <<"a + b should print Re=13; Im=24: "<< c <<endl<<endl;
	cout << "Subtraction Test" << endl <<"a - b should print Re=-7; Im=-16: "<< d <<endl<<endl;
	cout << "Multiplication Test" << endl <<"a * b should print Re=-50; Im=100: "<< multiplication <<endl<<endl;
	cout << "Division Test" << endl <<"a / b should print Re=0.22; Im=-0.04: "<< division <<endl<<endl;
	cout << "Equal Operator Test" << endl << " a :" << a << " a :"<< a << " Is a and a Equal? " << yesEqual <<endl<<endl;
	cout << "Not Equal Operator Test" << endl << " a :" << a << " b :"<< b << " Is a and b be not Equal? " << notEqual <<endl<<endl;
	cout << "Addition Equal Operator test +=" << endl <<"a+=b should print Re=13; Im=24: "<< a <<endl<<endl;
	cout << "Subtraction Equal Operator test -=" << endl <<"a-=b should print Re=3; Im=4: "<< ty <<endl<<endl;
	cout << "Multiplication Equal Operator test *=" << endl <<"a*=b should print Re=-50; Im=100: "<< ta <<endl<<endl;
	cout << "Division Equal Operator test /=" << endl <<"a/=b should print Re=3; Im=4: "<< tn <<endl<<endl;

	float x = 3.0f;

	// testing +-*/ operator overload that takes float for right
	Complex<double> sum = c + x;
	Complex<double> minus = c - x;
	Complex<double> Fmultiplication = c * x;
	Complex<double> Fdivision = c / x;
	// output test for Complex to Float Operations
	cout<<endl<< "		Complex to Float Operations"<<endl;
	cout<< "The Float number being tested is x = 3.0f and the value of c is Re=13; Im=24"<<endl;
	cout << "Addition Test" << endl <<"c + x should print Re=16; Im=24: "<< sum	 <<endl<<endl;
	cout << "Subtraction Test" << endl <<"c - x should print Re=10; Im=24: "<< minus <<endl<<endl;
	cout << "Multiplication Test" << endl <<"a * x should print Re=39; Im=72: "<< Fmultiplication <<endl<<endl;
	cout << "Division Test" << endl <<"c / x should print Re=4.33333; Im=8: "<< Fdivision <<endl<<endl;
	cout<<endl<< "The Float number being tested is x = 3.0f and the value of c is Re=13; Im=24"<<endl<<endl;
	c+=x;
	cout << "Addition Equal Operator test +=" << endl <<"c+=x should print Re=16; Im=24: "<< c <<endl<<endl;
	c-=x;
	cout << "Subtraction Equal Operator test -=" << endl <<"c-=x should print Re=13; Im=24: "<< c <<endl<<endl;
	c*=x;
	cout << "Multiplication Equal Operator test *=" << endl <<"c*=x should print Re=39; Im=72: "<< c <<endl<<endl;
	c/=x;
	cout << "Division Equal Operator test /=" << endl <<"c/=x should print Re=13; Im=24: "<< c <<endl<<endl;
	system("pause");
}