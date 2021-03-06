#include <iostream>
#include "vector.hpp"

using namespace std;

int vector::count = 0;

vector::vector()
{
	int *data = new int [1];

	vector::count++;

	this->size = 1;
	this->data = data;
}

vector::vector(int size)
{
	int *data = new int [size];

	vector::count++;

	this->size = size;
	this->data = data;
}

vector::~vector()
{
	delete[] this->data;

	vector::count--;
}

vector::vector(const vector& v)
{
	int *data = new int [v.size];

	for (int i = 0; i < v.size; i++)
		data[i] = v.data[i];

	vector::count++;

	this->size = v.size;
	this->data = data;
}

vector& vector::operator=(const vector& v)
{
	delete[] this->data;

	int *data = new int [v.size];
	
	for (int i = 0; i < v.size; i++)
		data[i] = v.data[i];
	
	this->size = v.size;
	this->data = data;

	return *this;
}

void vector::setElement(int idx, int value)
{
	this->data[idx] = value;
}

int vector::getElement(int idx)
{
	return this->data[idx];
}

void vector::printSelf()
{
	for (int i = 0; i < this->size; i++) 
		cout << this->data[i] << " ";
	
	cout << endl;
}

int vector::getCount()
{
	return count;
}