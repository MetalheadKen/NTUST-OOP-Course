#ifndef __PENGUIN_H__
#define __PENGUIN_H__

#include "Bird.hpp"

class Penguin : public Bird
{
public:
	Penguin();
	~Penguin();
	Penguin(string gender, string name);
	Penguin(const Penguin& obj);
	Penguin& operator=(const Penguin& obj);

	void makeNoise();
	void slide();
};

Penguin::Penguin()
{
	cout << "Penguin class default constructor" << endl;
	this->species = "Penguin";
	this->canFly = false;
}

Penguin::~Penguin()
{
	cout << "Penguin class destructor" << endl;
}

Penguin::Penguin(string gender, string name) : Bird(gender, name, 0)
{
	cout << "Penguin class user-defined constructor" << endl;
	this->species = "Penguin";
}

Penguin::Penguin(const Penguin& obj) : Bird(obj)
{
	cout << "Penguin class copy constructor" << endl;
}

Penguin& Penguin::operator=(const Penguin& obj)
{
	Bird::operator=(obj);
	cout << "Penguin class copy assignment operaotr" << endl;

	return *this;
}

void Penguin::makeNoise()
{
	cout << "The sound that the Penguin made was GAW" << endl;
}

void Penguin::slide()
{
	cout << "The penguin sliding on ice" << endl;
}

#endif /* __PENGUIN_H__ */
