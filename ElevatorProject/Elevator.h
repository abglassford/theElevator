#ifndef Elevator_h
#define Elevator_h

class Elevator {

public:

    Elevator(
        int _numUpperFloors,
        int _numBasementFloors,
        int _initialFloor
    );
    ~Elevator() = default;

    void selectFloor(int selectedFloor);

    int getFloorCount();

protected:

    void handleElevatorCalled(int floorNum);
    void handleFloorSelected(int floorNum);
 
    void moveToFloor(int floorNum);


private:

    int numUpperFloors      {10};
    int numBasementFloors   {3};
    int initialFloor        {0};
    int currentFloor        {0};

};

#endif