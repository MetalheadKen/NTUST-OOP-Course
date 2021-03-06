#include <iostream>

using namespace std;

// add the matrix simple class/structure here
class matrix
{
public:
	//add data members
	int size;
	int **data;

	//add functiom members
	void init(int size);
	void tranpose();
	void destroy();
};

void matrix::init(int size)
{
	int **arr = new int *[size];

	for (int i = 0; i < size; i++)
		arr[i] = new int[size];

	this->size = size;
	this->data = arr;
}

void matrix::tranpose()
{
	int size = this->size;
	int **data = this->data;

	for (int i = 0; i < size; i++) {
		for (int j = i + 1; j < size; j++) {
			swap(data[i][j], data[j][i]);
		}
	}
}

void matrix::destroy()
{
	for (int i = 0; i < this->size; i++)
		delete[] this->data[i];

	delete[] this->data;
}

int main()
{
	// obtain the matrix size from user
	int size;
	cout << "Please input the size of the square matrix." << endl;
	cin >> size;

	// create the matrix object
	matrix m;

	// using init to setup the matrix object
	m.init(size);

	// assign the values to the created matrix
	int count = 1;
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			m.data[i][j] = count;	//this will not work. correct it
			count++;
		}
	}

	// show the matrix on the screen
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++)
			cout << m.data[i][j] << " ";	//this will not work. correct it

		cout << endl;
	}

	// call transpose() to calculate its transpose
	m.tranpose();

	// show the matrix after transpose on the screen
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++)
			cout << m.data[i][j] << " ";	//this will not work. correct it

		cout << endl;
	}

	// call destroy to free the object
	m.destroy();

	system("pause");
}
