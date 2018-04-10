/*Conor Nolan 27/02/18*/
#ifndef MATRIX_CPP

#include <iostream>
#include <random>
#include <ctime>
#include"Matrix.h"
template <class T>
int Matrix<T>::matrixCnt = 0;

template <class T>
int Matrix<T>::GetMatrixCnt()
{
	return matrixCnt;
}

//Default Constructor
template <class T>
Matrix<T>::Matrix() : rows(0), cols(0)
{
#if VERBOSE
	std::cout << "Executing Default constructor" << std::endl;
#endif

	rows = 0;
	cols = 0;
}

//Arg Constructor
template <class T>
Matrix<T>::Matrix(int r, int c) : rows(r), cols(c)
{
#if VERBOSE
	std::cout << "Executing Arg constructor" << std::endl;
#endif

	mat.resize(r);
	for (auto i = mat.begin(); i != mat.end(); i++)
		i->resize(c);

	matrixCnt++;
}

//Copy Constructor
template <class T>
Matrix<T>::Matrix(const Matrix &m)
{
#if VERBOSE
	std::cout << "Executing Matrix copy constructor" << std::endl;
#endif
	mat.resize(m.rows);
	for (auto i = mat.begin(); i != mat.end(); i++)
		i->resize(m.cols);

	rows = m.GetRows();
	cols = m.GetCols();

	matrixCnt++;

}

//Destructor
template <class T>
Matrix<T>::~Matrix()
{
#if VERBOSE
	std::cout << "Executing Matrix destructor" << std::endl;
#endif

	matrixCnt--;

}




// = Operator
template <class T>
Matrix<T>& Matrix::operator=(const Matrix& rhs)
{
#if VERBOSE
	std::cout << "Executing = operator" << std::endl;
#endif

	if (this != &rhs)
	{
		mat.resize(rhs.rows);
		for (auto i = mat.begin(); i != mat.end(); i++)
			i->resize(rhs.cols);

		rows = rhs.rows;
		cols = rhs.cols;

		for (int i = 0; i < rhs.rows; i++)
		{
			for (int j = 0; j < rhs.cols; j++)
			{
				double v = rhs.GetElement(i, j);
				this->SetElement(i, j, v);
			}
		}
		return *this;
	}

}


/*
// + Operator
Matrix& Matrix::operator+(const Matrix& rhs)
{
#if VERBOSE
std::cout << "Executing + operator" << std::endl;

if (this != &rhs)
{
mat.resize(rhs.rows);
for (auto i = mat.begin(); i != mat.end(); i++)
i->resize(rhs.cols);

rows = rhs.rows;
cols = rhs.cols;

for (int i = 0; i < rhs.rows; i++)
{
for (int j = 0; j < rhs.cols; j++)
{
double v = rhs.GetElement(i, j) + this->GetElement(i, j);
this->SetElement(i, j, v);
}
}
return *this;
}

#endif
}
*/

// + Operator
template<class T>
Matrix<T> Matrix<T>::operator+(const Matrix<T>& rhs)
{
#if VERBOSE
	std::cout << "Executing + operator" << std::endl;
#endif

	Matrix result(rows, cols);

	if (cols == rhs.cols && rows == rhs.rows)
	{
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < cols; j++)
			{
				double v = mat[i][j] + rhs.GetElement(i, j);
				result.SetElement(i, j, v);
				//result.mat[i][j] = mat[i][j] + rhs.mat[i][j];				
			}
		}

		std::cout << result << std::endl;

	}

	return result;

}


// * Operator
template<class T>
Matrix<T> Matrix<T>::operator*(Matrix<T>& rhs)
{
#if VERBOSE
	std::cout << "Executing * operator" << std::endl;
#endif

	Matrix result(rows, cols);

	if (this != &rhs)
	{
		mat.resize(rhs.rows);
		for (auto i = mat.begin(); i != mat.end(); i++)
			i->resize(rhs.cols);

		rows = rhs.rows;
		cols = rhs.cols;

		for (int i = 0; i < this->rows; i++)
		{
			for (int j = 0; j < rhs.cols; j++)
			{
				for (int k = 0; k < rhs.rows; k++)
				{
					double v = mat[i][j] * rhs.GetElement(i, j);
					result.SetElement(i, j, v);
				}
			}
		}
	}
	//std::cout << result << std::endl;
	return result;

}
template<class T>
int Matrix<T>::Fill0123()
{
	int val = 0;
	for (auto &r : mat) {
		for (auto &c : r) {
			c = 0 + val;
			val++;
		}
	}
	return 0;
}

template<class T>
int Matrix<T>::FillRand()
{
	std::default_random_engine e(time(0));
	std::uniform_real_distribution<double> u(-1, 1);

	for (auto &r : mat) {
		for (auto &c : r)
			c = u(e);
	}
	return 0;

	/*
	for (auto r = mat.begin(); r != mat.end(); r++)
	{
	for (auto c = r->begin(); c != r->end(); c++)
	{
	c = u(e);
	}
	}
	*/

}

template<class T>
int Matrix<T>::GetRows() const
{
	return rows;
}

template<class T>
int Matrix<T>::GetCols() const
{
	return cols;
}

template <class T>
double Matrix<T>::GetElement(int i, int j)const
{
	return mat[i][j];
}

template <class T>
void Matrix<T>::SetElement(int i, int j, double v)
{
	mat[i][j] = v;
}

template <class T>
double& Matrix<T>::operator()(const int& row, const int& col)
{
	return mat[row][col];
}

template <class T>
std::ostream& operator<<(std::ostream &output, Matrix<T> &m)
{
	for (auto i = 0; i < m.GetRows(); i++)  // loop 3 times for three lines
	{
		for (auto j = 0; j < m.GetCols(); j++)  // loop for the three elements on the line
		{
			output << m.GetElement(i, j);  // display the current element out of the array
			output << " ";
		}
		output << std::endl;  // when the inner loop is done, go to a new line
	}
	return output;
}
#endif // !MATRIX_CPP
