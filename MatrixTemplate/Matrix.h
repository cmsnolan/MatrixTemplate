/*Conor Nolan 27/02/18*/
#ifndef MATRIX_H
#define MATRIX_H
#define VERBOSE 1

#include <iostream>
#include <vector>

const int n = 10;

template <class T = double>

class Matrix
{
public:
	Matrix();
	Matrix(int, int);
	Matrix(const  Matrix &);
	~Matrix();

	int GetRows() const;
	int GetCols() const;
	double GetElement(int, int) const;
	void SetElement(int, int, double);
	int GetMatrixCnt();

	Matrix& operator=(const Matrix&);
	Matrix operator+(Matrix&);
	Matrix operator*(Matrix&);
	int Fill0123();
	int FillRand();

	double& operator()(const int& row, const int& col);



	friend std::ostream &operator<<
		(std::ostream&, Matrix &);		//Overload << operator to display

private:
	int rows;
	int cols;
	int element;
	std::vector<std::vector<double>> mat;
	static int matrixCnt;
};

#include "Matrix.cpp"
#endif // !MATRIX_H
