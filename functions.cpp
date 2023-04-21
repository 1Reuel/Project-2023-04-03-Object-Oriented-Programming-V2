#include <iostream>
#include <string>
#include "functions.h"
#include <Windows.h>

using namespace std;

int menu()
{
	int choice;
	cout << "\x1B[93m    Menu Options\n"; // Yellow for Menu Options
	cout << "\x1B[91mPirate's Menu:\x1B[97m\n"; // Red for Pirate's Menu!
	cout << "  1:  Say something\n";
	cout << "  2:  Say something to the ninja\n";
	cout << "  3:  Swing sword menacingly\n";
	cout << "  4:  Attack with sword\n";
	cout << "\x1B[94mNinja's Menu:\x1B[97m\n"; // Blue for Ninja's Menu!
	cout << "  5:  Say something\n";
	cout << "  6:  Say something to the pirate\n";
	cout << "  7:  Throw star scarily\n";
	cout << "  8:  Attack with star\n";
	cout << "99:  End Game\n";
	Sleep(1000); // Pausing for dramatic effect again...
	cin >> choice; // Pick menu item here.
	return choice; // Return menu selection.

}