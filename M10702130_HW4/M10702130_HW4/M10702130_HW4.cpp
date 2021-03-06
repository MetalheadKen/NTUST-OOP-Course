#include <iostream>

using namespace std;

// Please provide the matrix class 
class matrix
{
public:
	matrix();
	matrix(int size);
	~matrix();
	matrix(const matrix& m);
	matrix& operator=(const matrix& m);
	
	void setElement(int x, int y, int value);
	int  getElement(int x, int y);
	void printSelf();

private:
	int size;
	int **data;
};

matrix::matrix()
{
	int **data = new int *[1];
	data[0] = new int[1];

	this->size = 1;
	this->data = data;
}

matrix::matrix(int size)
{
	int **data = new int *[size];

	for (int i = 0; i < size; i++)
		data[i] = new int[size];

	this->size = size;
	this->data = data;
}

matrix::~matrix()
{
	for (int i = 0; i < this->size; i++)
		delete[] this->data[i];

	delete[] this->data;
}

matrix::matrix(const matrix& m)
{
	int **data = new int *[m.size];

	for (int i = 0; i < m.size; i++)
		data[i] = new int [m.size];

	for (int i = 0; i < m.size; i++)
		for (int j = 0; j < m.size; j++)
			data[i][j] = m.data[i][j];

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

int main()
{
	// obtain the matrix size from user
	int size;
	cout << "Please input the size of the square matrix." << endl;
	cin >> size;

	// create the matrix object
	matrix* m = new matrix(size);

	// assign the values to the created matrix
	for (int i = 0; i < size; i++)
		for (int j = 0; j < size; j++)
		{
			if (i == j)
				m->setElement(i, j, 10);
			else
				m->setElement(i, j, 1);
		}

	// show the matrix on the screen
	cout << "m = " << endl;
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
			cout << m->getElement(i, j) << " ";

		cout << endl;
	}


	//testing standard constructors
	matrix* mArr1 = new matrix[10];	//calling default constructor
	matrix mArr2[5];				//calling default constructor
	matrix m1;						//calling default constructor
	matrix* m2 = new matrix(*m);	//calling copy constructor
	matrix m3 = matrix(*m);			//calling copy constructor

	m1 = *m;						//calling copy assignment operator


	//show the testing matrix objects
	cout << "m1 = " << endl;
	m1.printSelf();
	cout << "*m2 = " << endl;
	m2->printSelf();
	cout << "m3 = " << endl;
	m3.printSelf();


	// delete the dynamic allocated object
	delete m;
	delete[] mArr1;
	delete m2;
}
