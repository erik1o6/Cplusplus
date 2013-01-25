// complex.h - declaration of complex user- defined type
//Written by Erik Arfvidson

#pragma once

#include<iostream>
#define A this->Re
#define C right.Re
#define Bi this->Im
#define Di right.Im
#define F right
using namespace std;
template<typename TYPE>
//user -define type declaration
struct Complex
{
	//The fields or member variable of Complex
	TYPE Re;
	TYPE Im;


	//constructor
	//1) constructor name has to match exactly the name of the class
	//2) contructor CANNOT have a return value
	Complex()//Default constructor since it does not have arguments
	{
		Re = Im = 0;
	}

	//int constructor
	Complex(TYPE real, TYPE imaginary)
	{
		Re=real;
		Im=imaginary;
	}

	//member function for computing the abolute calue of this complex member
	TYPE Absolute()
	{
		return sqrt(Re*Re+Im*Im);
	}
	
						// -_-Complex operators-_-

	//1.Operator + for adding two complex numbers
	Complex operator + (/*Complex left, IMPLICIT*/Complex right)
	{
		Complex result;
		//(->) is a member access operator (just like .)
		//(this) is a pointer; -> is used to acess member on a POINTER
		//this-> is equivelent to (*this).
		result.Re=A+C;
		result.Im=Bi+Di;
		//result.Re=Re+right.Re; //is also a possible way to do it. it only replaces the left
		return result;
	}

	//2.Operator - for subtracting two complex numbers
	Complex operator - (/*Complex left, IMPLICIT*/Complex right)
	{
		Complex result;
		//(->) is a member access operator (just like .)
		//(this) is a pointer; -> is used to acess member on a POINTER
		//this-> is equivelent to (*this).
		result.Re=A-C;
		result.Im=Bi-Di;
		//result.Re=Re+right.Re; //is also a possible way to do it. it only replaces the left
		return result;
	}
	
	//3.Operator * for multiplying  two complex numbers
	Complex operator * (/*Complex left, IMPLICIT*/Complex right)
	{
		Complex result;
		//(->) is a member access operator (just like .)
		//(this) is a pointer; -> is used to acess member on a POINTER
		//this-> is equivelent to (*this).
		result.Re=(A*C)-(Bi*Di);
		result.Im=(Bi*C)+(A*Di);
		//result.Re=Re+right.Re; //is also a possible way to do it. it only replaces the left
		return result;
	}
		//4.Operator / for multiplying  two complex numbers
	Complex operator / (/*Complex left, IMPLICIT*/Complex right)
	{
		Complex result;
		//(->) is a member access operator (just like .)
		//(this) is a pointer; -> is used to acess member on a POINTER
		//this-> is equivelent to (*this).
		result.Re=((A*C)+(Bi*Di))/((C*C) + (Di*Di));
		result.Im=((Bi*C)-(A*Di))/((C*C) + (Di*Di));
		//result.Re=Re+right.Re; //is also a possible way to do it. it only replaces the left
		return result;
	}
	//5.Operator == is the two complex values the same
	bool operator == (Complex right)
	
           {
			   bool result= false;
			   if((A==C)&&(Bi==Di))
			   result = true;
            return result;
			
            }
	//6.Operator != is true if the two complex number are not equivalent
		bool operator != (Complex right)
	
           {
			   bool result= false;
			   if((A!=C)&&(Bi!=Di))
			   result = true;
            return result;
			
            }
		//+= -+ *= /=
		//7.Operator += sum one complex to another complex
		Complex operator += (Complex right)
	
           {
			   Re+= right.Re;
			   Im+= right.Im;
		
		
		return *this;
			
            }
		//8.Operator -= Subtract one complex to another complex
		Complex operator -= (Complex right)
	
           {

			   Re-= right.Re;
			   Im-= right.Im;
		
		
		return *this;
			
            }
		//9.Operator *= Multiplies one complex to another complex
		Complex operator *= (Complex right)
	
           {
		Complex tmp(A,Bi);
		Re=(A*C)-(Bi*Di);
		Im=(Bi*C)+(tmp.Re*Di);
		
		
		return *this;
			
            }
		//10.Operator /= Devides one complex to another complex
		Complex operator /= (Complex right)
	
           {
		Complex tmp(A,Bi);
		Re=((A*C)+(Bi*Di))/((C*C) + (Di*Di));
		Im=((Bi*C)-(tmp.Re*Di))/((C*C) + (Di*Di));
		
		
		return *this;
			}
						//-_-Float Operators-_-

	//1. Operator + for adding a complex number and a float
		Complex operator + (/*Complex left, IMPLICIT*/TYPE right)
	{
		//Complex result(Re+right,Im);
		//return result;
		return Complex(Re+F,Im); //return an UNNAMED temp instance of Complex
	}


	//2. Operator - for subtracting a complex number and a float
		Complex operator - (/*Complex left, IMPLICIT*/TYPE right)
	{
		//Complex result(Re+right,Im);
		//return result;
		return Complex(Re-F,Im); //return an UNNAMED temp instance of Complex
	}
	//3. Operator * for multiplying a complex number and a float
		Complex operator * (/*Complex left, IMPLICIT*/TYPE right)
	{
		//Complex result(Re+right,Im);
		//return result;
		return Complex(Re*F,Im*F); //return an UNNAMED temp instance of Complex
	}
	//4. Operator / for Divide a complex number and a float
		Complex operator / (/*Complex left, IMPLICIT*/TYPE right)
	{
		//Complex result(Re+right,Im);
		//return result;
		return Complex((Re*F)/(F*F),(Im*F)/(F*F)); //return an UNNAMED temp instance of Complex
	}
	
	//5.Operator += sum one float to complex
		Complex operator += (TYPE right)
	
           {
			   Re+= F;
			
		return *this;
			
            }
	//6.Operator -= minus one float to complex
		Complex operator -= (TYPE right)
	
           {

			   Re-=F;
			   
		
		
		return *this;
			
            }
	//7.Operator *= Multiplies one float to a complex
		Complex operator *= (TYPE right)
	
           {
		Complex tmp(A,Bi);
		Re=A*F;
		Im=Bi*F;
		
		
		return *this;
			
            }
		//8.Operator /= Devides one float to a complex
		Complex operator /= (TYPE right)
	
           {
		Complex tmp(A,Bi);
		Re=(Re*F)/(F*F);
		Im=(Im*F)/(F*F);
		
		
		return *this;
			}
/*	ostream& operator << (ostream& out, Complex c)
{
	out<<"Re="<<c.Re<<"; Im="<<c.Im;
	return out;
}*/

};//Always put a ; at the end of class declaration
  //It is important here because c++ expects a variable

/* Moved to inside the class, possible with change
Complex operator + (Complex left, Complex right)
{
	Complex result;
	result.Re=left.Re+right.Re;
	result.Im=left.Im+right.Im;
	return result;
}
*/

// ostream cannot be moved inside Complex because it is not Complex but ostream

//stream output operator
template<typename TYPE>
ostream& operator << (ostream& out, Complex<TYPE> n)
{
	out << "Re=" << n.Re << "; Im=" << n.Im;
	return out;

}