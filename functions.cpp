#include <iostream>
#include <string>
#include "functions.h"

using namespace std;

int menu()
{
	int choice;
	cout << "\x1B[93m    Menu Options\n";
	cout << "\x1B[91mPirates Menu:\x1B[97m\n";
	cout << "  1:  Say something\n";
	cout << "  2:  Say something to the ninja\n";
	cout << "  3:  Swing sword menacingly\n";
	cout << "  4:  Attack with sword\n";
	cout << "\x1B[94mNinjas Menu:\x1B[97m\n";
	cout << "  5:  Say something\n";
	cout << "  6:  Say something to the pirate\n";
	cout << "  7:  Throw star scarily\n";
	cout << "  8:  Attack with star\n";
	cout << "99:  End Game\n";
	cin >> choice;
	return choice;

}