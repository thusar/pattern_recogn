#pragma once

class ConstantPerceptron
{
public:
    int stepNbr;
    bool InputDataAndCalculate();
    void Step(DoubleMatrix& w, DoubleMatrix x, double c, double& functionForX);
    double DecisionFunction(DoubleMatrix wt, DoubleMatrix x);
    DoubleMatrix CalculateIncrement(DoubleMatrix w, DoubleMatrix x, double c);
};
