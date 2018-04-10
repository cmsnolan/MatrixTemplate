/*Conor Nolan 27/02/18*/
#include <iostream>
#include <stdlib.h>     /* srand, rand */
#include <chrono>
#include "Matrix.h"
#include "TestMatrix.h"

int testDefaultCstr()
{
	Matrix<double> m1;

	std::cout << "Rows:" << m1.GetRows() << std::endl;
	std::cout << "Cols:" << m1.GetCols() << std::endl;


	return 0;

}

int test2ArgCstr()
{
	auto start = std::chrono::high_resolution_clock::now();


	Matrix<double> m1(3, 3);
	std::cout << "Rows:" << m1.GetRows() << std::endl;
	std::cout << "Cols:" << m1.GetCols() << std::endl;

	m1.Fill0123();

	std::cout << m1 << std::endl;


	auto stop = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double>elapsed = stop - start;
	std::cout << elapsed.count() << std::endl;
	return 0;

}

int testCopyCstr()
{
	Matrix<double> mA(3, 4);
	Matrix<double> m1(mA);
	std::cout << "Rows:" << m1.GetRows() << std::endl;
	std::cout << "Cols:" << m1.GetCols() << std::endl;
	fillRand(m1);
	std::cout << m1 << std::endl;

	return 0;

}

int testEqualsOperator()
{
	Matrix<double> m1(2, 2);
	Matrix<double> m2(3, 3);

	fillRand(m1);

	std::cout << m1 << std::endl;

	fillRand(m2);

	std::cout << m2 << std::endl;

	m1 = m2;
	std::cout << m1 << std::endl;

	return 0;
}

int testPlusOperator()
{
	Matrix<double> m1(4, 4);
	Matrix<double> m2(4, 4);


	m1.Fill0123();
	std::cout << m1 << std::endl;

	m2.Fill0123();
	std::cout << m2 << std::endl;
	m1 + m2;

	std::cout << "check" << std::endl;

	//Matrix m3 = (m1 + m2);

	//std::cout << m3 << std::endl;

	return 0;
}

int testMultiplyOperator()
{
	Matrix<double> m1(2, 2);
	Matrix<double> m2(2, 2);

	fillRand(m1);

	std::cout << m1 << std::endl;

	fillRand(m2);

	std::cout << m2 << std::endl;

	Matrix<double> m3 = (m1 * m2);
	//std::cout << m3 << std::endl;

	return 0;
}
void fillRand(Matrix<double> &m)
{
	for (int i = 0; i < m.GetRows(); i++)
	{
		for (int j = 0; j < m.GetCols(); j++)
		{
			m.SetElement(i, j, (rand() % 10));
		}
	}
}
