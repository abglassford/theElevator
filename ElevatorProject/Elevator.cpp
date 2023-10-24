#include <iostream>
#include <thread>
#include <windows.h>

#include "Elevator.h"

Elevator::Elevator(
    int16_t _numUpperFloors,
    int16_t _numBasementFloors,
    int16_t _initialFloor
) :
    numUpperFloors{ _numUpperFloors },
    numBasementFloors{ _numBasementFloors },
    initialFloor{ _initialFloor }
{
    std::cout << "Elevator created.\nFloors: " << getFloorCount() << "\nInitial Floor: " << initialFloor << std::endl;
}

int16_t Elevator::getFloorCount()
{
    return numUpperFloors + numBasementFloors;
}


void Elevator::callElevator(int16_t floorNum, char direction)
{
    handleElevatorCalled(floorNum, direction);
}

void Elevator::selectFloor(int16_t selectedFloor)
{
    if (selectedFloor > numUpperFloors || selectedFloor < (numBasementFloors * -1))
    {
		std::cout << "\nSorry, floor " << selectedFloor << " doesn't exist! Please select a floor between 1 and " << getFloorCount() << "\n";
        return;
    }

    handleFloorSelected(selectedFloor);
}

void Elevator::handleElevatorCalled(int16_t floorNum, char _direction)
{
    if (_direction == '+')
		direction = Direction::up;
    else if (_direction == '-')
		direction = Direction::down;

    //callQueue.push_back(floorNum);

    if (floorNum > currentFloor)
    {
        if (direction == Direction::up)
			moveToFloor(floorNum);
        else
			std::cout << "\nPlease wait for elevator to change direction";
    }
    else if (floorNum < currentFloor)
    {
        if (direction == Direction::down)
			moveToFloor(floorNum);
        else
			std::cout << "\nPlease wait for elevator to change direction";
    }
    else
    {
		std::cout << "\nElevator is here!";
    }
}

void Elevator::handleFloorSelected(int16_t floorNum)
{

    if (floorNum > currentFloor)
    {
        if (direction == Direction::up)
			moveToFloor(floorNum);
        else
			std::cout << "\nPlease wait for elevator to change direction";
    }
    else if (floorNum < currentFloor)
    {
        if (direction == Direction::down)
			moveToFloor(floorNum);
        else
			std::cout << "\nPlease wait for elevator to change direction";
    }
    else
    {
		std::cout << "\nElevator is here!";
    }

	//callQueue.push_back(floorNum);
}


void Elevator::moveToFloor(int16_t selectedFloor)
{
    currentFloor = selectedFloor;
	std::cout << "\nElevator has arrived on floor " << currentFloor << "\n";
}

//void Elevator::processQueue()
//{
//    std::cout << "TIMEOUT";
//}
//
