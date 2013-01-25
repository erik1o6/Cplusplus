//Queue Lab-- program related to the queue talked in class
//Written: Erik Arfvidson


#include <queue>
#include <iostream>
#include <string>

using namespace std;
#define MAX 25

//Defines Struct operationsQueue

struct OperationsQueue
{
	char Operator;
	int Priority;
};
//Print returns no value
void Print(queue<OperationsQueue>& myQueue)
{
	OperationsQueue newEntry;
	while( !myQueue.empty() )
	{
		newEntry = myQueue.front();
		cout << "(" << newEntry.Operator << ", " << newEntry.Priority << ")" << endl;
		myQueue.pop();
	}
}

void main()
{
	int Level = 0;

	// represent character and its level of priority
	OperationsQueue entry;
	queue<OperationsQueue> operatorQueue;

	char input[MAX];
	cout << "Please enter an equation" << endl;

	cin.getline(input,MAX);

	// Moves an array of characters into a string.
	string equation(input);

	// Looks for operators with if statements and for loops
	for(int i = 0; i < (int)equation.size(); i++)
	{	//parenthesis open
		if(equation[i] == '(')
		{
			//increase
			Level++;
		}
		//parenthesis close
		else if(equation[i] == ')')
		{
			//decrease
			Level--;
		}
		else if(equation[i] == '*' || equation[i] == '/')
		{
			// * ||  /
			entry.Operator = equation[i];
			entry.Priority =  2*Level + 2;
			operatorQueue.push(entry);
		}
		else if(equation[i] == '+' || equation[i] == '-')
		{
			// + || -
			entry.Operator = equation[i];
			entry.Priority =  2*Level +1 ;
			operatorQueue.push(entry);
		}
	}
	//outputs solution
	Print(operatorQueue);

	system("pause");
}