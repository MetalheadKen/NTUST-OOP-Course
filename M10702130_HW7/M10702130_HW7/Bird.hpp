#ifndef __BIRD_H__
#define __BIRD_H__

#include "Animal.hpp"

class Bird : public Animal
{
public:
	Bird();
	~Bird();
	Bird(string gender, string name, bool canFly);
	Bird(const Bird& obj);
	Bird& operator=(const Bird& obj);

	virtual void makeNoise();
	virtual void print();
	virtual void getEggs();

	bool canFly;
};

Bird::Bird()
{
	cout << "Bird class default constructor" << endl;
	this->species = "Bird";
	this->canFly = true;
}

Bird::~Bird()
{
	cout << "Bird class destructor" << endl;
}

Bird::Bird(string gender, string name, bool canFly) : Animal(gender, name)
{
	cout << "Bird class user-defined constructor" << endl;
	this->species = "Bird";
	this->canFly = canFly;
}

Bird::Bird(const Bird& obj) : Animal(obj)
{
	cout << "Bird class copy constructor" << endl;
	this->canFly = obj.canFly;
}

Bird& Bird::operator=(const Bird& obj)
{
	Animal::operator=(obj);
	cout << "Bird class copy assignment operaotr" << endl;
	this->canFly = obj.canFly;

	return *this;
}

void Bird::makeNoise()
{
	cout << "This Bird's voice is the same as the universal Bird's voice" << endl;
}

void Bird::print()
{
	Animal::print();

	if (this->canFly) {
		cout << "It can fly" << endl;
	} else {
		cout << "It cannot fly" << endl;
	}
}

void Bird::getEggs()
{
	if (this->gender == "F") {
		cout << "Get eggs from this " << this->species << endl;
	} else {
		cout << "The male " << this->species << " cannot lay eggs" << endl;
	}
}

#endif /* __BIRD_H__ */
