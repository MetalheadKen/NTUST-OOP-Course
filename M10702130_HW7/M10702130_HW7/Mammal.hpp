#ifndef __MAMMAL_H__
#define __MAMMAL_H__

#include "Animal.hpp"

class Mammal : public Animal
{
public:
	Mammal();
	~Mammal();
	Mammal(string gender, string name, string moveType);
	Mammal(const Mammal& obj);
	Mammal& operator=(const Mammal& obj);

	virtual void makeNoise();
	virtual void print();
	virtual void getMilk();

	string moveType;
};

Mammal::Mammal()
{
	cout << "Mammal class default constructor" << endl;
	this->species = "Mammal";
	moveType = "";
}

Mammal::~Mammal()
{
	cout << "Mammal class destructor" << endl;
}

Mammal::Mammal(string gender, string name, string moveType) : Animal(gender, name)
{
	cout << "Mammal class user-defined constructor" << endl;
	this->species = "Mammal";
	this->moveType = moveType;
}

Mammal::Mammal(const Mammal& obj) : Animal(obj)
{
	cout << "Mammal class copy constructor" << endl;
	this->moveType = obj.moveType;
}

Mammal& Mammal::operator=(const Mammal& obj)
{
	Animal::operator=(obj);
	cout << "Mammal class copy assignment operaotr" << endl;
	this->moveType = obj.moveType;

	return *this;
}

void Mammal::makeNoise()
{
	cout << "This Mammal's voice is the same as the universal Mammal's voice" << endl;
}

void Mammal::print()
{
	Animal::print();
	cout << "Its movement type is " << this->moveType << endl;
}

void Mammal::getMilk()
{
	if (this->gender == "F") {
		cout << "Get milk from this " << this->species << endl;
	} else {
		cout << "The male " << this->species << " cannot produce milk" << endl;
	}
}

#endif /* __MAMMAL_H__ */
