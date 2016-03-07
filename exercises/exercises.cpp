// exercises.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include "double_matrix.h"
#include "exercises.h"
#include "perceptron_with_constant_increment.h"

using namespace std;


int main()
{
	cout << "Perceptron with constant increment : 1" << endl;
	cout << "Perceptron with partial increment  : 2" << endl;
	cout << "Select method:                        " << endl;
	int methodNbr;
	cin >> methodNbr;
	if (methodNbr == 1)
	{
        ConstantPerceptron method1;
		method1.InputDataAndCalculate();
	}
	else if (methodNbr == 2)
	{

	}
	return 0;

}

