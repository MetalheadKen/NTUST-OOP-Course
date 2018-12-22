#ifndef __SHEEP_H__
#define __SHEEP_H__

#include "Mammal.hpp"

class Sheep : public Mammal
{
public:
	Sheep();
	~Sheep();
	Sheep(string gender, string name);
	Sheep(const Sheep& obj);
	Sheep& operator=(const Sheep& obj);

	void makeNoise();
	void getWool();
};

Sheep::Sheep()
{
	cout << "Sheep class default constructor" << endl;
	this->species = "Sheep";
}

Sheep::~Sheep()
{
	cout << "Sheep class destructor" << endl;
}

Sheep::Sheep(string gender, string name) : Mammal(gender, name, "four-legged")
{
	cout << "Sheep class user-defined constructor" << endl;
	this->species = "Sheep";
}

Sheep::Sheep(const Sheep& obj) : Mammal(obj)
{
	cout << "Sheep class copy constructor" << endl;
}

Sheep& Sheep::operator=(const Sheep& obj)
{
	Mammal::operator=(obj);
	cout << "Sheep class copy assignment operaotr" << endl;

	return *this;
}

void Sheep::makeNoise()
{
	cout << "The sound that the Sheep made was BAA" << endl;
}

void Sheep::getWool()
{
	cout << "Get wool from this Sheep" << endl;
}

#endif /* __SHEEP_H__ */
