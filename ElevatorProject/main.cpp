#include <iostream>

#include "Elevator.h"

int main()
{
    std::cout << "Welcome!\n\n";

    Elevator* pElevator = new Elevator(10, 0, 0);

    std::cout << "Select floor (1-10)\n";

    int selectedFloor;

    std::cin >> selectedFloor;

    pElevator->selectFloor(selectedFloor);
}
