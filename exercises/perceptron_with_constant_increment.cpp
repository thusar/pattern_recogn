#include "stdafx.h"

#include "double_matrix.h"
#include "exercises.h"
#include "perceptron_with_constant_increment.h"

using namespace std;


void ConstantPerceptron::InputDataAndCalculate()
{
    cout << "Input how many vectors x you will use: ";
    int nbrVectors = 0;
    cin >> nbrVectors;
    int m = 0;
    cout << "Input number of rows in vector x: ";
    cin >> m;
    cout << "Input constant c:";
    double c = 0.0;
    cin >> c;
    std::vector<DoubleMatrix> xVectors;
    xVectors.resize(nbrVectors);
    for (int i = 0; i < nbrVectors; i++)
    {
        xVectors[i] = DoubleMatrix(m, 1);
        stringstream name;
        name << "Vector x(" << i + 1 << ")" << ends;
        xVectors[i].InputFromConsole(name.str());
    }
    DoubleMatrix w(m, 1);
    stringstream name("");
    name << "Vector w" << ends;
    w.InputFromConsole(name.str());

    int countPositive = 0;
    stepNbr = 0;
    double functionForX = 0.0;
    int index = 0;
    while (true)
    {
        index = stepNbr % nbrVectors;
        Step(w, xVectors[index], c, functionForX);
        if (functionForX > 0)
            countPositive++;
        else
            countPositive=0;
        if (countPositive == nbrVectors)
        {
            cout << "End of method." << endl;
            stringstream wname;
            wname << " Result decision function w: " << ends;
            w.NiceVectorOutput(wname.str());
            break;
        }
    }
    double prekid(0);
    cout << "For end input any number: ";
    cin >> prekid;
    return;
}

void ConstantPerceptron::Step(DoubleMatrix& w, DoubleMatrix x, double c, double& functionForX)
{
    stepNbr ++;
    functionForX = DecisionFunction(w, x);
    cout << stepNbr << ". step:" << endl;
    stringstream xname;
    xname << "x(" << stepNbr << "):" << ends;
    x.NiceVectorOutput(xname.str());
    cout << "wt * x: " << functionForX << endl;
    if (functionForX <= 0)
    {
        w = CalculateIncrement(w, x, c);
    }

    stringstream wname;
    wname << "w(" << stepNbr + 1 << "):" << ends;
    w.NiceVectorOutput(wname.str());

    double prekid(0);
    cout << "For continue input any number: ";
    cin >> prekid;
    return;
}


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

