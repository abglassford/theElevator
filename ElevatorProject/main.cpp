#include <iostream>

#include "Elevator.h"

int main()
{
    std::cout << "Welcome!\n\n";

    int16_t numUpperFloors, numBasementFloors, selectedFloor;
    int16_t initialFloor = 1;

    std::cout << "How many upper floors does this building have including the lobby?\n";
    std::cin >> numUpperFloors;

    std::cout << "How many basement floors does this building have?\n";
    std::cin >> numBasementFloors;

    std::cout.flush();

    Elevator* pElevator = new Elevator(numUpperFloors, numBasementFloors, initialFloor);

    char direction = ' ';

    std::cout << "You are currently on floor 1.\n";
    std::cout << "The elevator is currently on floor 1.\n";
    std::cout << "Please select which direction you'd like to go.\n";
    std::cout << "(enter \"+\" for up or \"-\" for down\n";
    std::cin >> direction;

    pElevator->callElevator(initialFloor, direction);

    std::cout << "\nPlease select a floor between -" << numBasementFloors << " and " << numUpperFloors << "\n";

    std::cin >> selectedFloor;

    pElevator->selectFloor(selectedFloor);
}
