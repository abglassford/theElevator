#ifndef Elevator_h
#define Elevator_h

#include <vector>

class Elevator {

public:

    enum Direction {up, down, none};

    Elevator(
        int16_t _numUpperFloors,
        int16_t _numBasementFloors,
        int16_t _initialFloor
    );
    ~Elevator() = default;

    void selectFloor(int16_t selectedFloor);
    void callElevator(int16_t floorNumber, char direction);

    int16_t getFloorCount();

protected:

    void handleElevatorCalled(int16_t floorNum, char direction);
    void handleFloorSelected(int16_t floorNum);
 
    void moveToFloor(int16_t floorNum);


private:

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