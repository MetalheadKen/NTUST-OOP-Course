#ifndef __EAGLE_H__
#define __EAGLE_H__

#include "Bird.hpp"

using namespace std;

class Eagle : public Bird
{
public:
	Eagle();
	~Eagle();
	Eagle(string gender, string name);
	Eagle(const Eagle& obj);
	Eagle& operator=(const Eagle& obj);

	void makeNoise();
	void huntPrey();
};

Eagle::Eagle()
{
	cout << "Eagle class default constructor" << endl;
	this->species = "Eagle";
	this->canFly = true;
}

Eagle::~Eagle()
{
	cout << "Eagle class destructor" << endl;
}

Eagle::Eagle(string gender, string name) : Bird(gender, name, 1)
{
	cout << "Eagle class user-defined constructor" << endl;
	this->species = "Eagle";
}

Eagle::Eagle(const Eagle& obj) : Bird(obj)
{
	cout << "Eagle class copy constructor" << endl;
}

Eagle& Eagle::operator=(const Eagle& obj)
{
	Bird::operator=(obj);
	cout << "Eagle class copy assignment operaotr" << endl;

	return *this;
}

void Eagle::makeNoise()
{
	cout << "The sound that the Eagle made was SCREE" << endl;
}

void Eagle::huntPrey()
{
	cout << "The Eagle is hunting the prey" << endl;
}

#endif /* __EAGLE_H__ */
