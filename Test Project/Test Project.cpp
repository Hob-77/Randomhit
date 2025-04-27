#include <iostream>
#include <random>

int applydamage(int health, int damage)
{
	return health - damage;
}

int main()
{
	int playerhealth{ 100 };
	int damagetaken{ 20 };
	int headshot{ 34 };

	std::random_device rd; //get a random seed
	std::mt19937 gen(rd()); //intialize random seed with the engine 
	std::uniform_int_distribution<> distrib(1, 2); //define a range

	while (playerhealth > 0)
	{
		int hitlocation = distrib(gen); //random generator between 1 and 2

		if (hitlocation == 1) //if the bullet hits the body
		{
			std::cout << "you took a bodyshot " << "\n";
			playerhealth = applydamage(playerhealth, damagetaken);
		}

		else if (hitlocation == 2) //if the bullet hits the head
		{
			std::cout << "you took a headshot " << "\n";
			playerhealth = applydamage(playerhealth, headshot);
		}

		std::cout << "this is your health: " << playerhealth << "\n";
	}

	std::cout << "You died: \n";

	return 0;
}