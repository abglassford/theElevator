#ifndef Elevator_h
#define Elevator_h

#include <vector>

class Elevator {

public:

/*==================================================*
    enum to describe directions
 *==================================================*/
    enum Direction {up, down, none};

/*==================================================*
    constructor/destructor
 *==================================================*/
    Elevator(
        int16_t _numUpperFloors,
        int16_t _numBasementFloors,
        int16_t _initialFloor
    );
    ~Elevator() = default;


/*==================================================*
    called when user selects floor from inside 
    the elevator
 *==================================================*/
    bool selectFloor(int16_t selectedFloor);

/*==================================================*
    called when user calls the elevator 
 *==================================================*/
    bool callElevator(int16_t floorNumber, char direction);


/*==================================================*
    help to get the total number of floors 
    (note: there is no floor 0)
 *==================================================*/
    int16_t getFloorCount();


protected:

/*==================================================*
    handles when a user has called the elevator
 *==================================================*/
    void handleElevatorCalled(int16_t floorNum, char direction);


/*==================================================*
    handles when a user has selected a floor
 *==================================================*/
    void handleFloorSelected(int16_t floorNum);
 

/*==================================================*
    moves the elevator to the selected floor
 *==================================================*/
    void moveToFloor(int16_t floorNum);


private:

/*==================================================*
    members
 *==================================================*/
    //void processQueue();

    int16_t numUpperFloors          {10};
    int16_t numBasementFloors       {3};
    int16_t initialFloor            {1};
    int16_t currentFloor            {1};
    int16_t destinationFloor        {INT16_MAX};

    Direction direction             {Direction::none};

    //std::vector<int16_t> callQueue;
};

#endif