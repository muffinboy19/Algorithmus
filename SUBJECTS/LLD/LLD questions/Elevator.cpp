#include <bits/stdc++.h>
using namespace std;
#define int long long

// Elevator Class::
class Elevator{
    int elevatorNumber;
    int currentFloor;
  public:
    Elevator(int elevatorNumber, int currentFloor){
      this->elevatorNumber = elevatorNumber;
      this->currentFloor = currentFloor;
    }
    int getElevatorNumber(){
      return this->elevatorNumber;
    }
    int getFloorNumber(){
      return this->currentFloor;
    }
    void setFloorNumber(int floorNumber){
      this->currentFloor = floorNumber;
    }
    void moveToElevator(int floorNumber){
      setFloorNumber(floorNumber);
    }
};


// Elevator System::
class ElevatorSystem {
    int noOfFloor, noOfElevator;
    vector<Elevator> elevator;
    
  public:
    ElevatorSystem(int noOfFloor, int noOfElevator){
      this->noOfFloor = noOfFloor;
      this->noOfElevator = noOfElevator;
    }
  
    int getNoOfFloor(){
      return this->noOfFloor;
    }
    int getNoOfElevator(){
      return this->noOfElevator;
    }
    void InitialiseElevator(int noOfElevator){
      for(int i=0;i<noOfElevator;i++){
        Elevator e(i+1, 0);
        this->elevator.push_back(e);
      }
    }

    void requestToCome(int floorNumber){
      priority_queue<pair<int, Elevator>, vector<pair<int,Elevator>> , greater<pair<int,Elevator>>>pq;
      for(auto it: elevator){
        pq.push({abs(it.getFloorNumber()-floorNumber), it});
      }
      auto it = pq.top();
      Elevator ele = it.second;
      ele.moveToElevator(floorNumber);
    }
};



int32_t main() {
  return 0;
}