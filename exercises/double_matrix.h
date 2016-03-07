#pragma once

class DoubleMatrix
{
public:
	int m;
	int n;
	std::vector <std::vector<double> > A;

    // default constructor
	DoubleMatrix();
    // matrix A with m rows and n columns initialized to zeros 
	DoubleMatrix(int m, int n);
    // copy constructor A = B
    DoubleMatrix(const DoubleMatrix& B);
    // default destructor
	~DoubleMatrix();

	// Input and output
    // input from console to matrix with name print_name
    void InputFromConsole(std::string print_name);
    // input from file with m rows and n columns
    void InputFromFile(std::string file_name, int m, int n);
    // write matrix print_name to console entry by entry
	void OutputToConsole(std::string print_name);
    // write matrix in rows and column to console
    void NiceOutput(std::string print_name);
    // write matrix in rows and columns to file file_name
    void NiceOutputToFile(std::string file_name);
    
    // Basic matrix operations
    // the sum A+B of two m-by-n matrices
	DoubleMatrix operator+(DoubleMatrix B);
    // scalar multiplication
	DoubleMatrix operator*(double c);
    // transposition
    DoubleMatrix Transpose();

    // Matrix multiplication
    // matrix multiplication if A.n == B.m
	DoubleMatrix operator*(DoubleMatrix B);
	// scalar product of vectors is At * B where A.m = 1 i B.n = 1
	double ScalarProduct(DoubleMatrix B);

    // Row operations
    // row addition, that is adding a row k to row l
	void RowAddition(int k, int l);
    // row multiplication, that is multiply row entries by a non-zero constant
	void RowMultiplication(int k, double c);
	// swap rows k and l, interchanging two rows of matrix
	void SwapRows(int k, int l);

    // Sub-matrix - from matrix is deleted row k and column l
	void Submatrix(int k, int l);

    // Main operations
    // trace - sum of diagonal entries
    double Trace();
    // Sarrus rule - determinant of 3x3 matrix
    double SarrusDeterminant();


    void GaussElimination();
	double MatrixDeterminant();
};
