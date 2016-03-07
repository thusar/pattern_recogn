#include "stdafx.h"

#include "double_matrix.h"
#include "exercises.h"
#include "perceptron_with_constant_increment.h"

using namespace std;

DoubleMatrix ConstantPerceptron::CalculateIncrement(DoubleMatrix w, DoubleMatrix x, double c)
{
    w = w + x * c;
    return w;
}

double ConstantPerceptron::DecisionFunction(DoubleMatrix w, DoubleMatrix x)
{
    double functionForX = w.ScalarProduct(x);
    return functionForX;
}

void ConstantPerceptron::Step(DoubleMatrix& w, DoubleMatrix x, double c, double& functionForX)
{
    stepNbr ++;
    functionForX = DecisionFunction(w, x);
    cout << stepNbr << ". step:" << endl;
    cout << "wt * x: " << functionForX << endl;
    if (functionForX <= 0)
    {
        w = CalculateIncrement(w, x, c);
    }

    string name("New w:");
    w.NiceOutput(name);

    double prekid(0);
    cout << "For continue input any number: ";
    cin >> prekid;
    return;
}

void ConstantPerceptron::InputDataAndCalculate()
{
    cout << "Input how many vectors you will use:";
    int nbrVectors = { 0 };
    cin >> nbrVectors;
    int m = { 0 };
    cout << "Input number of rows in vector:";
    cin >> m;
    cout << "Input constant c:";
    double c { 0.0 };
    cin >> c;
    DoubleMatrix* xVectors = 0;
    xVectors = new DoubleMatrix[nbrVectors] { };
    for (int i = 0; i < m; i++)
    {
        xVectors[i] = DoubleMatrix(m, 1);
        stringstream name("");
        name << "Vector nbr. " << i + 1 << ends;
        xVectors[i].InputFromConsole(name.str());
    }
    DoubleMatrix w(m, 1);
    stringstream name("");
    name << "Vector w " << ends;
    w.InputFromConsole(name.str());

    int countPositive { 0 };
    stepNbr = 0;
    while (true)
    {
        double functionForX { 0.0 };
        int index { stepNbr % nbrVectors };
        Step(w, xVectors[index], c, functionForX);
        if (functionForX > 0)
            countPositive++;
        else
            countPositive=0;
        if (countPositive == nbrVectors)
        {
            cout << "End" << endl;
            break;
        }
    }

    return;
}
