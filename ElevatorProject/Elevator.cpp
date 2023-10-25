#include <iostream>
#include <thread>
#include <windows.h>

#include "Elevator.h"

/*==================================================*
    constructor
 *==================================================*/
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

/*==================================================*
    help to get the total number of floors 
    (note: there is no floor 0)
 *==================================================*/
int16_t Elevator::getFloorCount()
{
    return numUpperFloors + numBasementFloors;
}


/*==================================================*
    called when user calls the elevator 
 *==================================================*/
bool Elevator::callElevator(int16_t floorNum, char direction)
{
    if (direction == '+' || direction == '-')
    {
		handleElevatorCalled(floorNum, direction);
        return true;
    }
    else
    {
        std::cout << "\n*The elevator has exploded*";
        return false;
    }
}


/*==================================================*
    called when user selects floor from inside 
    the elevator
 *==================================================*/
bool Elevator::selectFloor(int16_t selectedFloor)
{
    if (selectedFloor == 0 || selectedFloor > numUpperFloors || selectedFloor < (numBasementFloors * -1)) // don't allow selection of floor 0 or other out of range floors
    {
		std::cout << "\nSorry, floor " << selectedFloor << " doesn't exist! Please select a floor between -" << numBasementFloors << " and " << numUpperFloors << "\n";
        return false;
    }

    handleFloorSelected(selectedFloor);
    return true;
}


/*==================================================*
    handles when a user has called the elevator
 *==================================================*/
void Elevator::handleElevatorCalled(int16_t floorNum, char _direction)
{
    //callQueue.push_back(floorNum);

    if (direction == Direction::none) // if the elevator is currently not moving
    {
		if (_direction == '+')
			direction = Direction::up;  // set the current direction of the elevator
		else if (_direction == '-')
			direction = Direction::down;  // set the current direction of the elevator
    }
    else // if the elevator is moving, inform the user
    {
		if (_direction == '+')
			std::cout << "\nElevator is currently going up.";
		else if (_direction == '-')
			std::cout << "\nElevator is currently going down.";
    }

    // in either instance, we're still going to send the elevator to the requested floor
    // this is where I'd like to implement a timer to simulate the elevator going to each floor
	moveToFloor(floorNum);
	std::cout << "\nElevator is here!";
}

/*==================================================*
    handles when a user has selected a floor
 *==================================================*/
void Elevator::handleFloorSelected(int16_t floorNum)
{
    if (floorNum > currentFloor)
    {
        if (direction == Direction::down) // if the elevator is supposed to be going down, but the requested floor is up...
			std::cout << "\nElevator is currently going down."
			          << "\nPlease wait for elevator to change direction";

		moveToFloor(floorNum); // still go to the floor (implement timer to simulate waiting for task completion)
    }
    else if (floorNum < currentFloor) // if the elevator is supposed to be going up, but the requested floor is down...
    {
        if (direction == Direction::up)
			std::cout << "\nElevator is currently going up."
			          << "\nPlease wait for elevator to change direction";

		moveToFloor(floorNum); // still go to the floor (implement timer to simulate waiting for task completion)
    }
    else
    {
		moveToFloor(floorNum); // elevator wasn't moving so immediately arrives at desired floor.
		std::cout << "\nElevator is here!";
    }

	//callQueue.push_back(floorNum);
}


/*==================================================*
    moves the elevator to the selected floor
 *==================================================*/
void Elevator::moveToFloor(int16_t selectedFloor)
{
    currentFloor = selectedFloor;
	std::cout << "\nElevator has arrived on floor " << currentFloor << "\n\n";
}

//void Elevator::processQueue()
//{
//    std::cout << "TIMEOUT";
//}
//
