#include "stdafx.h"
#include <algorithm>

#include "double_matrix.h"

using namespace std;

// default constructor
DoubleMatrix::DoubleMatrix()
{
    m = 0;
    n = 0;
    A = 0;
}

// matrix A with m rows and n columns initialized to zeros 
DoubleMatrix::DoubleMatrix(int m, int n)
{
    (*this).m = m;
    (*this).n = n;
    A = new double*[m]{ };
    for (int i = 0; i < m; i++)
        A[i] = new double[n]{ };
	for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            A[i][j] = 0;
}

// copy constructor A = B
DoubleMatrix::DoubleMatrix(const DoubleMatrix& B)
{
    m = B.m;
    n = B.n;
    A = new double*[m]{ };
    for (int i = 0; i < m; i++)
        A[i] = new double[n]{ };
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            A[i][j] = B.A[i][j];
}

// default destructor
DoubleMatrix::~DoubleMatrix()
{
    for (int i = 0; i < m; i++)
    {
        delete[] A[i];
        A[i] = 0;
    }
    delete[] A;
    m = 0;
    n = 0;
    A = 0;
}

// Input and output
// input from console to matrix with name print_name
void DoubleMatrix::InputFromConsole(string print_name)
{
    for (int i = 0; i < m; i++)
	    for (int j = 0; j < n; j++)
        {
            cout << print_name.c_str() << "[" << i + 1 << "," << j + 1 << "]=";
            cin >> A[i][j];
        }
}

// input from file with m rows and n columns
void DoubleMatrix::InputFromFile(string file_name, int m, int n)
{
}

// write matrix print_name to console entry by entry
void DoubleMatrix::OutputToConsole(string print_name)
{
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
        {
            cout << print_name.c_str() << "[" << i + 1 << "," << j + 1 << "]=" << A[i][j];
        }
}

// write matrix in rows and columns to console
void DoubleMatrix::NiceOutput(string print_name)
{
    cout << print_name << endl;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << A[i][j] << "  ";
        }
        cout << endl;
    }
}

// write matrix in rows and columns to file file_name
void DoubleMatrix::NiceOutputToFile(string file_name)
{

}

// Basic matrix operations
// the sum A+B of two m-by-n matrices
DoubleMatrix DoubleMatrix::operator+(DoubleMatrix B)
{
    if (m != B.m || n != B.n)
    {
        cout << "Sum of two matrices is impossible." << endl;
        return *this;
    }
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            A[i][j] = A[i][j] + B.A[i][j];
    return *this;
}

// scalar multiplication
DoubleMatrix DoubleMatrix::operator*(double c)
{
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            A[i][j] = A[i][j] * c;
    return *this;
}

// transposition
DoubleMatrix DoubleMatrix::Transpose()
{
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            A[j][i] = A[i][j];
    return *this;
}

// Matrix multiplication
// matrix multiplication if A.n == B.m
DoubleMatrix DoubleMatrix::operator*(DoubleMatrix B)
{
    if (n != B.m)
    {
        cout << "Multiplication of two matrices is impossible." << endl;
        return *this;
    }
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
        {
            double sum{ 0 };
            for (int k = 0; k < n; k ++)
                sum += A[i][k] * B.A[k][j];
            A[i][j] = sum;
        }
    return *this;
}

// scalar product of vectors is At * B where A.m = 1 i B.n = 1
double DoubleMatrix::ScalarProduct(DoubleMatrix B)
{
    DoubleMatrix At = Transpose();
    if (At.n != B.m || At.m != 1 || B.n != 1)
    {
        cout << "Scalar product of two vectors is impossible." << endl;
        return 0.0;
    }
    double scalarProduct{0.0};
    for (int k = 0; k < At.n; k ++)
        scalarProduct += At.A[0][k] * B.A[k][0];
    return scalarProduct;
}

// Row operations
// row addition, that is adding a row k to row l
DoubleMatrix DoubleMatrix::RowAddition(int k, int l)
{
    return *this;
}

// row multiplication, that is multiply row entries by a non-zero constant
DoubleMatrix DoubleMatrix::RowMultiplication(int k, double c)
{
    return *this;
}

// swap rows k and l in input matrix
DoubleMatrix DoubleMatrix::SwapRows(int k, int l)
{
    if (k == l)
    {
        cout << "Swaping rows is impossible." << endl;
        return *this;
    }
    for (int j = 0; j < n; j++)
    {
        double temp{ A[k][j] };
        A[k][j] = A[l][j];
        A[l][j] = temp;
    }
    return *this;
}

// Submatrix - from matrix is deleted row k and column l
DoubleMatrix DoubleMatrix::Submatrix(int k, int l)
{
    return *this;
}

// Main operations
// trace - sum of diagonal entries
double DoubleMatrix::Trace()
{
    return 1.0;
}
// Sarrus rule - determinant of 3x3 matrix
double DoubleMatrix::SarrusDeterminant()
{
    return 1.0;
}

DoubleMatrix DoubleMatrix::GaussElimination()
{
    int min_dim = min(m, n);
    for (int k = 0; k < min_dim; k++)
    {
        int maxi { k };
        double maxa { A[k][k] };
        for (int i = k + 1; i < m; i++)
        {
            if (A[i][k] > maxa)
            {
                maxa = A[i][k];
                maxi = i;
            }
        }
        if (maxa == 0)
            throw ("Matrix is singular.");
        *this = SwapRows(k, maxi);
        for (int i = k + 1; i < m; i++)
        {
            double factor{ A[i][k] / A[k][k] };
            for (int j = k + 1; j < n; j++)
                A[i][j] = A[i][j] - factor * A[k][j];
            A[i][k] = 0;
        }
    }
    return *this;
}

// determinant of matrix processed with Gauss Elimination
double DoubleMatrix::MatrixDeterminant()
{
    double determinant { 1.0 };
    for (int i = 0; i < m; i++)
        determinant = determinant * A[i][i];
    return determinant;
}

