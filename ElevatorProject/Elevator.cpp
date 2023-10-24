#include <iostream>

#include "Elevator.h"

Elevator::Elevator(
    int _numUpperFloors,
    int _numBasementFloors,
    int _initialFloor
) :
    numUpperFloors{ _numUpperFloors },
    numBasementFloors{ _numBasementFloors },
    initialFloor{ _initialFloor }
{
    std::cout << "Elevator created.\nFloors: " << getFloorCount() << "\nInitial Floor: " << initialFloor << std::endl;
}

int Elevator::getFloorCount()
{
    return numUpperFloors + numBasementFloors + 2;
}

void Elevator::selectFloor(int selectedFloor)
{
    if (selectedFloor > getFloorCount() || selectedFloor < 1)
    {
		std::cout << "\nSorry, floor " << selectedFloor << " doesn't exist! Please select a floor between 1 and " << getFloorCount() << "\n";
        return;
    }

    moveToFloor(selectedFloor);
}

void Elevator::moveToFloor(int selectedFloor)
{
    currentFloor = selectedFloor;
}

void Elevator::handleElevatorCalled(int floorNum)
{

}

void Elevator::handleFloorSelected(int floorNum)
{

}
