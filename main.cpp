/*** DESCRIPTION ***

* This is a simple console application that simply simulates queuing system in a workshop.
There are three workshops basically and each got a queue in which cars enters and then
get out in order. Some additional options are added like searching, checking..etc.

***Considerations & Edits***

* The class workshop was inheriting class (super class) so children classes could have their own
implementation of some function(s) and owning some shared attributes/functions. Due the low number of
unique methods and attributes, edit has been made and WorkShop is now one class representing the workshop.

* Functions
	bool getOrder(std::string); which check the car's order in specefic workshop
	void printAll(); which prints all the car's in specefic workshop in order
  where in the main file but moved to WorkShop class since they are work on the Workshop class level

***Ideas (not implemented yet)***

* LuckyCar -> randomly selecting a car currently in a workshop for winning price or special offer !
* Adding the client's (car owners) data to be stored as linked list permanently on external files (like simple database)

*** END OF DOC***/


#include <iostream>
#include <string>
#include "WorkShop.h"
#include <cstdlib>

//Creating Workshops Objects and giving them a name
WorkShop DentingPainting("Denting & Painting");
WorkShop TireBalancing("Tires Balancing");
WorkShop Electrical("Electrical");

//Constants used in the app for how many options could be choosen by the user
const int actionsNumber = 6;
const int workshopsNumber = 5;

//functions declaration receiving inputs from the users and helping in selecting and checking
int chooseAction();
std::string enterCarNumber();
WorkShop & chooseWorkshop(int &);

int main() {
	//Endless loop
	while (1) {

		//For user input
		int choosenActionNumber = chooseAction();

		//Exit the app selected
		if (choosenActionNumber == 6) {
			std::exit(EXIT_SUCCESS);
		}

		//Choices will need to select workshop
		else if ((choosenActionNumber) == 1 ||
			(choosenActionNumber == 2) ||
			(choosenActionNumber == 4) ||
			(choosenActionNumber == 5)) {

			//Choosing workshop and returning the object of it
			//also checking the return to the first menu without any action
			int statBack = 0;
			WorkShop & w = chooseWorkshop(statBack);
			if (statBack) {
				continue;
			}

			//variable will be used
			std::string carNumber;

			//Checking the choice
			switch (choosenActionNumber)
			{
			case 1: //Adding a car and checking if it's there or not first
				carNumber = enterCarNumber();
				bool exists;
				exists = w.getOrder(carNumber);
				if (!exists)
				{
					w.addCar(carNumber);
					std::cout << "\n==========\n" << w.getOperation() << "\n==========\n";
				}
				break;
			case 2: //Removing the first car in line
				w.remCar(carNumber);
				std::cout << "\n==========\n" << w.getOperation() << "\n==========\n";
				break;
			case 4: //Print all cars in specific workshop
				w.printAll();
				break;
			case 5:  //Getting the order of a car if exists in specific workshop
				carNumber = enterCarNumber();
				w.getOrder(carNumber);
				break;
			}
		}
		//choice will NOT need workshop selection
		//Searching for specific car in all workshops
		else if (choosenActionNumber == 3) {
			std::string carNumber = enterCarNumber();
			DentingPainting.getOrder(carNumber);
			TireBalancing.getOrder(carNumber);
			Electrical.getOrder(carNumber);
		}
	}
	return 0;
}

int chooseAction() {
	bool invalid = true;
	int input;
	while (invalid) {
		std::cout << "What would you like to do ?\n\n";
		std::cout << "1- Add a new car\n";
		std::cout << "2- Remove a finished car\n";
		std::cout << "3- Search for specific car in which workshop\n";
		std::cout << "4- Print all the cars in one workshop\n";
		std::cout << "5- Get the order of specific car in specific workshop\n";
		std::cout << "6- Exit the app !!!\n";
		std::cin >> input;
		if (std::cin.fail()) // has a previous extraction failed?
		{
			std::cin.clear(); // put us back in 'normal' operation mode
			std::cin.ignore(32767, '\n'); // and remove the bad input
		}
		else {std::cin.ignore(32767, '\n');}
		if (input <= actionsNumber && input >= 1)
			invalid = false;
		else
			std::cout << "\n==========\n" << "\nThe Entered value is invalid\n" << "\n==========\n";
	}
	return input;
}

WorkShop & chooseWorkshop(int & statBack) {
	bool invalid = true;
	int input;
	while (invalid) {
		std::cout << "Choose workshop:\n";
		std::cout << "1- " << DentingPainting.getName() << std::endl;
		std::cout << "2- " << TireBalancing.getName() << std::endl;
		std::cout << "3- " << Electrical.getName() << std::endl;
		std::cout << "4- " << "Get back to the main menu" << std::endl;
		std::cout << "5- " << "Exit the app !!!" << std::endl << std::endl;
		std::cin >> input;
		if (std::cin.fail()) // has a previous extraction failed?
		{
			std::cin.clear(); // put us back in 'normal' operation mode
			std::cin.ignore(32767, '\n'); // and remove the bad input
		} else{ std::cin.ignore(32767, '\n'); }
		if ((input <= workshopsNumber) && (input >= 1)) {
			invalid = false;
			switch (input) {
			case 1:
				return DentingPainting;
			case 2:
				return TireBalancing;
			case 3:
				return Electrical;
			case 4:
				statBack = 1;
				break;
			case 5:
				std::exit(EXIT_SUCCESS);
			}
		}
		else
			std::cout << "\nThe Entered value is invalid\n" << "\n==========\n";
	}
}

//small function returns false if there is space in string
bool spaceInString(std::string s) {
	bool Result = false;
	for (int i = 0; i < s.length(); i++) {
		if (s.at(i) == ' ') {
			Result = true;
			break;
		}
	}
	return Result;
}


std::string enterCarNumber() {
	std::string carNumber;
	while (1) {
		std::cout << "\nEnter car number please (Min 1 & Max is 8 characters)\n";
		std::getline(std::cin, carNumber);
		if (std::cin.fail()) // has a previous extraction failed?
		{
			std::cin.clear(); // put us back in 'normal' operation mode
			std::cin.ignore(32767, '\n'); // and remove the bad input
			continue;
		}
		//Checking of spaces inside the string
		if (spaceInString(carNumber)) {
			std::cout << "\nPlease enter valid input\n";
			continue;
		}
		//Checking of minimum and maximum string lenght
		if (!((carNumber.length() <=8) && (carNumber.length() >=1))) {
			std::cout << "\nPlease enter valid input\n";
			continue;
		}
		return carNumber;
	}
}