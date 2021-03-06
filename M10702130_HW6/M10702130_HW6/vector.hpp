#ifndef __VECTOR_H__
#define __VECTOR_H__

class matrix;

// Please provide the vector class 
class vector
{
public:
	vector();
	vector(int size);
	~vector();
	vector(const vector& v);
	vector& operator=(const vector& v);
	
	void setElement(int idx, int value);
	int  getElement(int idx);
	void printSelf();
	
	static int getCount();

	friend vector& MmultV(matrix &m, vector &v);
	friend vector  VmultM(vector &m, matrix &v);
	
private:
	int size;
	int *data;

	static int count;
};

#endif /* __VECTOR_H__ */