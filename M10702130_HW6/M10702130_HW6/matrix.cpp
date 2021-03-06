#include <iostream>
#include "matrix.hpp"

using namespace std;

int matrix::count = 0;

matrix::matrix()
{
	int **data = new int *[1];
	data[0] = new int[1];

	matrix::count++;

	this->size = 1;
	this->data = data;
}

matrix::matrix(int size)
{
	int **data = new int *[size];

	for (int i = 0; i < size; i++)
		data[i] = new int[size];

	matrix::count++;

	this->size = size;
	this->data = data;
}

matrix::~matrix()
{
	for (int i = 0; i < this->size; i++)
		delete[] this->data[i];

	delete[] this->data;

	matrix::count--;
}

matrix::matrix(const matrix& m)
{
	int **data = new int *[m.size];

	for (int i = 0; i < m.size; i++)
		data[i] = new int [m.size];

	for (int i = 0; i < m.size; i++)
		for (int j = 0; j < m.size; j++)
			data[i][j] = m.data[i][j];

	matrix::count++;

	this->size = m.size;
	this->data = data;
}

matrix& matrix::operator=(const matrix& m)
{
	for (int i = 0; i < this->size; i++)
		delete[] this->data[i];

	delete[] this->data;

	int **data = new int *[m.size];

	for (int i = 0; i < m.size; i++)
		data[i] = new int [m.size];

	for (int i = 0; i < m.size; i++)
		for (int j = 0; j < m.size; j++)
			data[i][j] = m.data[i][j];

	this->size = m.size;
	this->data = data;

	return *this;
}

void matrix::setElement(int x, int y, int value)
{
	this->data[x][y] = value;
}

int matrix::getElement(int x, int y)
{
	return this->data[x][y];
}

void matrix::printSelf()
{
	for (int i = 0; i < this->size; i++) {
		for (int j = 0; j < this->size; j++) {
			cout << this->data[i][j] << " ";
		}
		cout << endl;
	}
}

int matrix::getCount()
{
	return matrix::count;
}