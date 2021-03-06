#include <iostream>
#include "Eagle.hpp"
#include "Penguin.hpp"
#include "Platypus.hpp"
#include "Sheep.hpp"

using namespace std;

/*
 *                   Animal
 *                   /     \
 *                  /       \
 *                 /         \
 *              Bird        Mammal
 *              / \          /   \
 *             /   \        /     \
 *            /     \      /       \
 *       Penguin  Eagle  Platypus  Sheep
 */

int main()
{
	/* Animal class test */
	{
		Animal animal_a;
		Animal animal_b("F", "ANIMAL");
		Animal animal_c(animal_b);
		Animal animal_d;
		animal_d = animal_c;

		cout << "-------------------" << endl;
		// animal_d.makeNoise();
		animal_d.print();
		cout << "-------------------" << endl;
	}
	cout << endl;

	/* Bird class test */
	{
		Bird bird_a;
		Bird bird_b("F", "BIRD", true);
		Bird bird_c(bird_b);
		Bird bird_d;
		bird_d = bird_c;

		cout << "-------------------" << endl;
		// bird_d.makeNoise();
		bird_d.getEggs();
		bird_d.print();
		cout << "-------------------" << endl;
	}
	cout << endl;

	/* Mammal class test */
	{
		Mammal mammal_a;
		Mammal mammal_b("F", "MAMMAL", "two-legged");
		Mammal mammal_c(mammal_b);
		Mammal mammal_d;
		mammal_d = mammal_c;

		cout << "-------------------" << endl;
		// mammal_d.makeNoise();
		mammal_d.getMilk();
		mammal_d.print();
		cout << "-------------------" << endl;
	}
	cout << endl;

	/* Penguin class test */
	{
		Penguin penguin_a;
		Penguin penguin_b("F", "PENGUIN");
		Penguin penguin_c(penguin_b);
		Penguin penguin_d;
		penguin_d = penguin_c;

		cout << "-------------------" << endl;
		// penguin_d.makeNoise();
		penguin_d.getEggs();
		penguin_d.slide();
		penguin_d.print();
		cout << "-------------------" << endl;
	}
	cout << endl;

	/* Eagle class test */
	{
		Eagle eagle_a;
		Eagle eagle_b("F", "EAGLE");
		Eagle eagle_c(eagle_b);
		Eagle eagle_d;
		eagle_d = eagle_c;

		cout << "-------------------" << endl;
		// eagle_d.makeNoise();
		eagle_d.getEggs();
		eagle_d.huntPrey();
		eagle_d.print();
		cout << "-------------------" << endl;
	}
	cout << endl;

	/* Platypus class test */
	{
		Platypus platypus_a;
		Platypus platypus_b("F", "PLATYPUS");
		Platypus platypus_c(platypus_b);
		Platypus platypus_d;
		platypus_d = platypus_c;

		cout << "-------------------" << endl;
		// platypus_d.makeNoise();
		platypus_d.getMilk();
		platypus_d.injectVenom();
		platypus_d.print();
		cout << "-------------------" << endl;
	}
	cout << endl;

	/* Sheep class test */
	{
		Sheep sheep_a;
		Sheep sheep_b("F", "SHEEP");
		Sheep sheep_c(sheep_b);
		Sheep sheep_d;		
		sheep_d = sheep_c;

		cout << "-------------------" << endl;
		// sheep_d.makeNoise();
		sheep_d.getMilk();
		sheep_d.getWool();
		sheep_d.print();
		cout << "-------------------" << endl;
	}
	cout << endl;

	/* Polymorphism test */
	{
		Animal animal("F", "ANIMAL");
		Bird bird("F", "BIRD", true);
		Mammal mammal("F", "MAMMAL", "two-legged");
		Penguin penguin("F", "PENGUIN");
		Eagle eagle("F", "EAGLE");
		Platypus platypus("F", "PLATYPUS");
		Sheep sheep("F", "SHEEP");

		Animal *animal_arr[] = { &animal, &bird, &mammal, &penguin, &eagle, &platypus, &sheep};
		
		cout << "-------------------" << endl;
		for (int i = 0; i < 7; i++) {
			animal_arr[i]->makeNoise();
		}
		cout << "-------------------" << endl;
	}
}
