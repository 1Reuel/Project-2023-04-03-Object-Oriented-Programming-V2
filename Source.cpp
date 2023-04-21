#include <iostream>
#include <string>
#include "functions.h"

/*
	Reuel Attwood
	Assignment: Object Oriented Programming
	Due by: Apr 3, 2:59 pm Philippine time

	It's April 6, 9:30 pm, and I think this is going to be late.
*/

using namespace std;

class GameStructure
{
public:
	virtual void help()
	{

	}

};

class Character : public GameStructure
{
private:
	int Health;

public:

	string Name;
	void Talk(string stuffToSay)
	{
		cout << Name << " says:  " << stuffToSay << endl;  // Someone is just saying something.
	}
	void Talk(string name, string stuffToSay)
	{
		cout << Name << " says to " << name << ":  " << stuffToSay << endl;  // Someone is saying something to someone specific.
	}
	bool setHealth(int health)
	{
		if (health < 0)
		{
			Health = 0;
			cout << Name << " has expired.\n";
			return true;
		}
		else
		{
			Health = health;
			return false;
		}

	}
	int getHealth()
	{
		return Health;
	}
	virtual int attack()
	{
		return 10;
	}
	void help()
	{

	}

};

class Pirates : public Character
{
private:

public:
	Pirates(int health, string name); // Constructor
	void useSword()
	{
		cout << "I am swooshing my sword!\n";
	}
	int attack()
	{
		return 25;
	}
	void help()
	{
		cout << "Pirates enjoy a good game of swordplay, yet seem to prefer to win that game.\n";
	}

};

class Ninjas : public Character
{
private:

public:
	Ninjas(int health, string name); // constructor?
	// Ninjas(int health, string name); // Constructor
	void throwStars()
	{
		cout << "I am throwing stars!\n";
	}
	int attack()
	{
		return 25;
	}
	void help()
	{
		cout << "Ninjas prefer dark places so nobody can see them throwing stars.\n";
	}

};

int main()
{
	bool gameNotOver = true, roundOver = false;
	// gameNotOver flag keeps it going until user exits
	// roundOver flat ends the round when a character expires
	string namePirate, nameNinja, nameTalk, somethingToSay;
	int option, hitPoints; // Health is reduced by hitPoints
	cout << "          \x1B[91mPIRATES\x1B[97m vs \x1B[94mNINJAS\x1B[97m\n\n";
	cout << "Here we go!\n\n";
	cout << "Enter the pirate's name: ";
	cin >> namePirate;
	cout << "\nEnter the ninja's name: ";
	cin >> nameNinja;
	cout << "\n";

	Pirates pirate1(60, namePirate);
	Ninjas ninja1(60, nameNinja);

	while (gameNotOver)
	{
		option = menu();
		switch (option)
		{
		case 1:
			cout << "What does the pirate want to say? ";
			cin >> somethingToSay;
			pirate1.Talk(somethingToSay);
			break;
		case 2:
			cout << "What does the pirate want to say to the ninja? ";
			cin >> somethingToSay;
			pirate1.Talk(ninja1.Name, somethingToSay);
			break;
		case 3:
			pirate1.useSword();
			break;
		case 4:
			pirate1.useSword();
			hitPoints = pirate1.attack(); // This time he attacks.
			roundOver = ninja1.setHealth(ninja1.getHealth() - hitPoints); // Updating health and checking for expiration
			if (roundOver) // If the ninja has expired ...
			{
				cout << pirate1.Name << " Wins!\n";
			}
			else
			{
				cout << ninja1.Name << " has a health of " << ninja1.getHealth() << endl;
			}
			break;


		default:
			break;
		}


	}


}