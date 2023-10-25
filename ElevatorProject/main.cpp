#include <iostream>

#include "Elevator.h"

int main()
{
    std::cout << "Welcome!\n\n";

    int16_t numUpperFloors, numBasementFloors, selectedFloor, initialFloor;

    bool valid = false;

    while (!valid)
    {
        valid = true;

		std::cout << "How many upper floors does this building have including the lobby?\n";
		std::cin >> numUpperFloors;

		if (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "Please enter an integer\n\n";
            valid = false;
		}
    }

	valid = false;

    while (!valid)
    {
        valid = true;

		std::cout << "How many basement floors does this building have?\n";
		std::cin >> numBasementFloors;

		if (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "Please enter an integer\n\n";
            valid = false;
		}
    }

	valid = false;

    while (!valid)
    {
        valid = true;

        std::cout << "What floor are you starting out on?\n";
        std::cin >> initialFloor;

		if (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "Please enter an integer\n\n";
            valid = false;
		}
    }

    Elevator* pElevator = new Elevator(numUpperFloors, numBasementFloors, initialFloor);

    std::cout << "You are currently on floor " << initialFloor << ".\n";
    std::cout << "The elevator is currently on floor 1.\n";

    char direction = ' ';
	valid = false;

    while (!valid)
    {
        valid = true;

		std::cout << "\nPlease select which direction you'd like to go.\n";
		std::cout << "(enter \"+\" for up or \"-\" for down\n";
        std::cin >> direction;

		if (std::cin.fail() || !(direction == '+' || direction == '-'))
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "(enter \"+\" for up or \"-\" for down\n";
            valid = false;
		}
    }

    bool callSucceeded = pElevator->callElevator(initialFloor, direction);

    if (!callSucceeded) return 0;

	valid = false;

    while (!valid)
    {
        valid = true;

		std::cout << "\nPlease select a floor between -" << numBasementFloors << " and " << numUpperFloors << "\n";
		std::cin >> selectedFloor;

		if (std::cin.fail() || selectedFloor == 0)
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "\nPlease select a floor between -" << numBasementFloors << " and " << numUpperFloors << "\n";
            valid = false;
		}
    }

    bool selectionSucceeded = pElevator->selectFloor(selectedFloor);

    if (!selectionSucceeded) return 0;
}

