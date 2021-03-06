#ifndef __MATRIX_H__
#define __MATRIX_H__

class vector;

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

	static int getCount();

	friend vector& MmultV(matrix &m, vector &v);
	friend vector  VmultM(vector &m, matrix &v);
	
private:
	int size;
	int **data;

	static int count;
};

#endif /* __MATRIX_H__ */