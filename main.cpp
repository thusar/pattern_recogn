# include <iostream>

#include "exercises/exercises.h"

using namespace std;

int main()
{
	cout << "Exercises                          : 1" << endl;
	cout << "Recording of samples               : 2" << endl;
	cout << "Wavelet analysis of samples        : 3" << endl;
	cout << "Learning from samples              : 4" << endl;
	cout << "Select task                        : ";
	int task;
	cin >> task;
	bool result = true;
	if (task == 1)
	{
        Exercises exercises;
        result = exercises.SelectAndRunTasks();
	}
	else if (task == 2)
	{

	}
	if (result)
		return 0;
	else
		return -1;

}
