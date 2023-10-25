#include <iostream>

#include "Elevator.h"

int main()
{
    std::cout << "Welcome!\n\n";

    int16_t numUpperFloors, numBasementFloors, selectedFloor, initialFloor; // declarations

    bool valid = false; // bool value for validation loops
    while (!valid) // create a loop to allow user to try again after entring bad value
    {
        valid = true;

		std::cout << "How many upper floors does this building have including the lobby?\n";
		std::cin >> numUpperFloors; // get number of upper floors from the user

		if (std::cin.fail()) // if the input is incorrect
		{
			std::cin.clear(); // clear the input
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // ignore what's left in the buffer (if user decides to spam the CL)
			std::cout << "Please enter an integer\n\n"; 
            valid = false; // restart the loop until valid
		}
    }

	valid = false;

    while (!valid) // create a loop to allow user to try again after entring bad value
    {
        valid = true;

		std::cout << "How many basement floors does this building have?\n";
		std::cin >> numBasementFloors; // get number of basement floors from user

		if (std::cin.fail()) // if the input is incorrect
		{
			std::cin.clear(); // clear the input
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // ignore what's left in the buffer (if user decides to spam the CL)
			std::cout << "Please enter an integer\n\n"; 
            valid = false; // restart the loop until valid
		}
    }

	valid = false;

    while (!valid) // create a loop to allow user to try again after entring bad value
    {
        valid = true;

        std::cout << "What floor are you starting out on?\n";
        std::cin >> initialFloor; // get initial floor selection from user

		if (std::cin.fail()) // if the input is incorrect
		{
			std::cin.clear(); // clear the input
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // ignore what's left in the buffer (if user decides to spam the CL)
			std::cout << "Please enter an integer\n\n"; 
            valid = false; // restart the loop until valid
		}
    }

    Elevator* pElevator = new Elevator(numUpperFloors, numBasementFloors, initialFloor);

    std::cout << "You are currently on floor " << initialFloor << ".\n";
    std::cout << "The elevator is currently on floor 1.\n";

    char direction = ' ';
	valid = false;

    while (!valid) // create a loop to allow user to try again after entring bad value
    {
        valid = true;

		std::cout << "\nPlease select which direction you'd like to go.\n";
		std::cout << "(enter \"+\" for up or \"-\" for down\n";
        std::cin >> direction; // get direction selection from user

		if (std::cin.fail()) // if the input is incorrect
		{
			std::cin.clear(); // clear the input
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // ignore what's left in the buffer (if user decides to spam the CL)
			std::cout << "(enter \"+\" for up or \"-\" for down\n";
            valid = false; // restart the loop until valid
		}
    }

    bool callSucceeded = pElevator->callElevator(initialFloor, direction); // call the elevator

    if (!callSucceeded) return 0; // if the call did not succeed, exit

	valid = false;

    while (!valid) // create a loop to allow user to try again after entring bad value
    {
        valid = true;

		std::cout << "\nPlease select a floor between -" << numBasementFloors << " and " << numUpperFloors << "\n";
		std::cin >> selectedFloor; // get floor selection from user

		if (std::cin.fail()) // if the input is incorrect
		{
			std::cin.clear(); // clear the input
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // ignore what's left in the buffer (if user decides to spam the CL)
			std::cout << "\nPlease select a floor between -" << numBasementFloors << " and " << numUpperFloors << "\n";
            valid = false; // restart the loop until valid
		}
    }

    bool selectionSucceeded = pElevator->selectFloor(selectedFloor); //select the floor

    if (!selectionSucceeded) return 0; // if selection doesn't succeed, exit
}

