// exercises.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include "double_matrix.h"
#include "exercises.h"
#include "perceptron_with_constant_increment.h"

using namespace std;


bool Exercises::SelectAndRunTasks()
{
	cout << "Perceptron with constant increment : 1" << endl;
	cout << "Perceptron with partial increment  : 2" << endl;
	cout << "Select method                      : ";
	int method;
	cin >> method;
	bool result;
	if (method == 1)
	{
        ConstantPerceptron method1;
		result = method1.InputDataAndCalculate();
	}
	else if (method == 2)
	{

	}
	return result;

}

