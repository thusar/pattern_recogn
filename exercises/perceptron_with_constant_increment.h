#pragma once

class ConstantPerceptron
{
public:
    int stepNbr;
    void InputDataAndCalculate();
    void Step(DoubleMatrix& w, DoubleMatrix x, double c, double& functionForX);
    double DecisionFunction(DoubleMatrix wt, DoubleMatrix x);
    DoubleMatrix CalculateIncrement(DoubleMatrix w, DoubleMatrix x, double c);
};
