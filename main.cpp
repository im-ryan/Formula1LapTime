/**
* Ryan Huett
* Date: 5/14/2018
* Visual Studio 2017
* The driver for class LapTime that includes a simple UI as well as
* input validation. Also contains class LapTime's member functions.
*/
#include"LapTime.h"

int getUserInput();
void promptUserToContinue(bool *);

int main() {
	LapTime lapTime;
	bool userWantsToGoAgain = true;

	cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	cout.precision(2);

	// Validation and input collection broken into
	// separate functions for legibility/testing.
	do {
		lapTime.setLapNumber( getUserInput() );
		lapTime.displayLapTime();
		promptUserToContinue(&userWantsToGoAgain);
	} while (userWantsToGoAgain);

	cout << "\nPress any key to close this window...";
	cin.get();

	return 0;
}

// Calculates then displays the lap time in MM:SS:mm format
void LapTime::displayLapTime() {
	double fuelUsed = FUEL_USED_PER_LAP * (currentLapNumber - 1);
	double fuelTime = (fuelUsed / 10.0) * FUEL_LOSS_TIME;
	double tireTime = (currentLapNumber - 1) * TIRE_DEGREDATION_TIME;
	double lapTime = BASE_TIME - fuelTime + tireTime;

	int minutes = static_cast<int>(lapTime / 60);

	// Display the lap time in minutes and seconds
	cout << "Lap " << currentLapNumber << " Time: " <<
		minutes << ":" << (lapTime - (minutes * 60)) << endl;
}

// Collects, validates and returns user input for the wanted lap number
int getUserInput() {
	int lapNum = 0;
	bool userEnteredWrongData = true;

	system("CLS");
	cout << "Enter a lap number to see the estimated time: ";
	do {
		cin >> lapNum;

		// If wrong data type or out of range (1-57)
		if ( cin.fail() || (lapNum < 1 || lapNum > TOTAL_LAPS) ) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');

			cout << "Must be between 1-57: ";
		}
		else {
			userEnteredWrongData = false;
			cin.ignore();
		}
	} while (userEnteredWrongData);

	return lapNum;
}

// Prompts user to continue, only accepting (y)es or (n)o
void promptUserToContinue(bool *goAgain) {
	char userInput = '\0';
	bool userEnteredWrongChoice = true;
	bool flag = false;

	do {
		cout << "Would you like to go again (y/n)? ";
		cin.get(userInput);
		cin.ignore(numeric_limits<streamsize>::max(), '\n');

		if (userInput == 'Y' || userInput == 'y') {
			flag = true;
			userEnteredWrongChoice = false;
		}
		else if (userInput == 'N' || userInput == 'n') {
			flag = false;
			userEnteredWrongChoice = false;
		}
	} while (userEnteredWrongChoice);

	*goAgain = flag;
}