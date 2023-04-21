#include <iostream>
#include <string>
#include "functions.h"
#include <windows.h>


/*
	Reuel Attwood
	Assignment: Object Oriented Programming
	Due by: Apr 3, 2:59 pm Philippine time

	It's April 6, 9:30 pm, and I think this is going to be late.
*/

using namespace std;

class GameStructure // Game Structure class (There's not a lot here yet...)
{
public:
	virtual void help() // Here's our virtual Help
	{

	}

};

class Character : public GameStructure // Character Class
{
private:
	int Health; // Let's keep our health private until it's necessary.

public:

	string Name; // Here's your character's name!
	void Talk(string stuffToSay) // Here's the Talk method
	{
		cout << Name << " says:  " << stuffToSay << endl;  // Someone is just saying something.
	}
	void Talk(string name, string stuffToSay) // Here's the Overload
	{
		cout << Name << " says to " << name << ":  " << stuffToSay << endl;  // Someone is saying something to someone specific.
	}
	bool setHealth(int health) // Set Health privately
	{
		if (health < 0)
		{
			Health = 0; // Health can't be negative
			cout << Name << " has expired.\n";
			return true; // The round must end.
		}
		else
		{
			Health = health;
			return false; // Althought health can reach 0, as long as it did not actually go below 0, our character is not quite expired.
		}

	}
	int getHealth()
	{
		return Health; // Return our private health value
	}
	virtual int attack()
	{
		return 10; // This is our Character attack value
	}
	void help() // Override GameStructure virtual Help
	{

	}

};

class Pirates : public Character // Pirates class
{
private:

public:
	Pirates(int health, string name) // Constructor
	{
		Name = name; // Initialize name
		setHealth(health); // Initialize health
	}
	void useSword()
	{
		cout << "I am swooshing my sword!\n"; // ... Menacingly!
	}
	int attack()
	{
		return 25; // Pirate's attack hitpoint value override
	}
	void help() // Override Character help
	{
		cout << "Pirates enjoy a good game of swordplay, yet seem to prefer to win that game.\n";
	}

};

class Ninjas : public Character
{
private:

public:
	Ninjas(int health, string name) // Constructor
	{
		Name = name; // Initialize name
		setHealth(health); // Initialize health
	}
	void throwStars()
	{
		cout << "I am throwing stars!\n";  // Scarily!  (Is that a word?)
	}
	int attack()
	{
		return 25; // Ninja's attack hitpoint value override
	}
	void help() // Override character help
	{
		cout << "Ninjas prefer dark places so nobody can see them throwing stars.\n";
	}

};

int main()
{
	bool gameNotOver = true, roundOver = false;
	// gameNotOver flag keeps it going until user exits
	// roundOver flat ends the round when a character expires
	string namePirate, nameNinja, nameTalk, somethingToSay; // Names to initialize and stuff to say
	int option, hitPoints; // Health is reduced by hitPoints
	cout << "          \x1B[91mPIRATES\x1B[97m vs \x1B[94mNINJAS\x1B[97m\n\n";  // Our title!
	cout << "Here we go!\n\n";
	cout << "Enter the pirate's name: ";
	cin >> namePirate; // Pirate's name
	cout << "\nEnter the ninja's name: ";
	cin >> nameNinja; // Ninja's name
	cout << "\n";

	Pirates pirate1(60, namePirate);  // Create a Pirates object
	Ninjas ninja1(60, nameNinja); // Create a Ninjas object

	while (gameNotOver) // Game loop!
	{
		cout << pirate1.Name << "'s health is now " << pirate1.getHealth() << endl; // Let's display health every round
		cout << ninja1.Name << "'s health is now " << ninja1.getHealth() << endl; // ...
		option = menu(); // Call the Menu function!
		switch (option) // Switch according to the user's choice
		{
		case 1: // Talk method of pirate1
			cout << "What does the pirate want to say? ";
			cin >> somethingToSay; // Putting a space between things here can wreak havoc
			pirate1.Talk(somethingToSay); // Calling the Talk method
			cout << endl; // Another linefeed for neatness
			Sleep(1000); // A pause for added effect!
			break;
		case 2: // Talk overload!  The pirate wants to say something to the ninja!
			cout << "What does the pirate want to say to the ninja? ";
			cin >> somethingToSay; // Definitely do not put a space in this!
			pirate1.Talk(ninja1.Name, somethingToSay); // Calling the overloaded Talk method
			cout << endl;
			Sleep(1000); // For Dramatic Effect
			break;
		case 3:
			pirate1.useSword(); // Swish!
			cout << endl;
			Sleep(1000); // Dramatic ...
			break;
		case 4:
			pirate1.useSword(); // Swish! ...
			Sleep(1000); 
			hitPoints = pirate1.attack(); // This time he attacks.
			roundOver = ninja1.setHealth(ninja1.getHealth() - hitPoints); // Updating health and checking for expiration
			if (roundOver) // If the ninja has expired ...
			{
				cout << pirate1.Name << " Wins!\n";
			}
			else
			{
				cout << ninja1.Name << " has a health of " << ninja1.getHealth() << endl; // He's still not expired, so let's see how he's doing
			}
			cout << endl;
			Sleep(1000);
			break;
		case 5:  // See case 1 and swap pirate and ninja
			cout << "What does the ninja want to say? ";
			cin >> somethingToSay;
			ninja1.Talk(somethingToSay);
			cout << endl;
			Sleep(1000);
			break;
		case 6: // See case 2 and swap ...
			cout << "What does the ninja want to say to the pirate? ";
			cin >> somethingToSay;
			ninja1.Talk(pirate1.Name, somethingToSay);
			cout << endl;
			Sleep(1000);
			break;
		case 7: // See case 3 and swap ...
			ninja1.throwStars();
			cout << endl;
			Sleep(1000);
			break;
		case 8: // See case 4 and swap ...
			ninja1.throwStars();
			Sleep(1000);
			hitPoints = ninja1.attack(); // This time he attacks.
			roundOver = pirate1.setHealth(pirate1.getHealth() - hitPoints); // Updating health and checking for expiration
			if (roundOver) // If the ninja has expired ...
			{
				cout << ninja1.Name << " Wins!\n";
			}
			else
			{
				cout << pirate1.Name << " has a health of " << pirate1.getHealth() << endl;
			}
			cout << endl;
			Sleep(1000);
			break;
		case 99: // If he chooses this, we're done!  Time to exit!
			gameNotOver = false; // We do that by setting gameNotOver to false, which means the game is now over.
			break;
		default:
			Sleep(1000);
			cout << "\nWell That's Not A Choice That I Presented To You!  Please pick one from the menu.\n\n"; // Invalid Choice
			Sleep(1000);
			break;
		}
		if (roundOver)
		{
			cout << "\nLooks like this round is over!  Let's do it again!  We'll add 60 to both characters and continue.\n\n";
			pirate1.setHealth(pirate1.getHealth() + 60); // Each round starts over by adding 60 to both characters.
			ninja1.setHealth(ninja1.getHealth() + 60); // This seems a bit unfair because the winner will always have the advantage.
			Sleep(1000);
			cout << pirate1.Name << "'s health is now " << pirate1.getHealth() << endl; // Updated values
			cout << ninja1.Name << "'s health is now " << ninja1.getHealth() << endl;
			Sleep(1000);
			cout << "Here we go again!\n\n";
		}


	}


}