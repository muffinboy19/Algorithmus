#include <bits/stdc++.h>
using namespace std;

class User{
    string userName, Details;
    int age, x_coordinate, y_coordinate;
    int totalBill;
    pair<int, int> RideSt, RideEn;

  public:
    User(string userName, string Details, int age, int x_coordinate=0, int y_coordinate=0, int totalBill=0){
      this-> userName = userName;
      this-> Details = Details;
      this-> age = age;
      this-> x_coordinate = x_coordinate;
      this-> y_coordinate = y_coordinate;
      this-> totalBill = totalBill;
    }
    string getUserName(){
      return userName;
    }
    void setUserName(string userName){
      this->userName = userName;
    }
    void setXcoordinate(int X){
      this-> x_coordinate = X;
    }
    void setYcoordinate(int Y){
      this-> y_coordinate = Y;
    }
    int getXcoordinate(){
      return this->x_coordinate;
    }
    int getYcoordinate(){
      return this->y_coordinate;
    }
    int getTotalBill(){
      return this->totalBill;
    }
    void setTotalBill(int fare){
      this->totalBill += fare;
    }

    void setRideSt(int x1, int y1){
      RideSt = {x1, y1};
    }
    void setRideEn(int x2, int y2){
      RideEn = {x2, y2};
    }
    pair<int,int> getRideSt(){
      return {RideSt.first, RideSt.second};
    }
    pair<int,int> getRideEn(){
      return {RideEn.first, RideEn.second};
    }
};

class Driver{
    string userName, Details, carNo, carType;
    int age, x_coordinate, y_coordinate, totalEarnings;
    bool isAvailable;

  public:
    Driver(string userName, string Details, int age, string carType, string carNo, int x_coordinate=0, int y_coordinate=0, bool isAvailable=true, int totalEarnings=0){
      this-> userName = userName;
      this-> Details = Details;
      this-> age = age;
      this-> carType = carType;
      this-> carNo = carNo;
      this-> x_coordinate = x_coordinate;
      this-> y_coordinate = y_coordinate;
      this-> totalEarnings = totalEarnings;
    }
    void setDriverName(string userName){
      this->userName = userName;
    }
    string getDriverName(){
      return userName;
    }
    void setXcoordinate(int X){
      this-> x_coordinate = X;
    }
    void setYcoordinate(int Y){
      this-> y_coordinate = Y;
    }
    int getYcoordinate(){
      return this-> y_coordinate;
    }
    int getXcoordinate(){
      return this-> x_coordinate;
    }
    bool IsAvailabe(){
      return this->isAvailable;
    }
    void setIsAvailable(bool isAvailable){
      this->isAvailable = isAvailable;
    }
    int getTotalEarnings(){
      return this->totalEarnings;
    }
    void setTotalEarn(int Earn){
      this->totalEarnings += Earn;
    }
};

class Application{
    vector<User> users;
    vector<Driver> drivers;
    
  public:
    Application() = default;

    void add_user(string name, string detail, int age){
      User u(name, detail, age);
      users.push_back(u);
    }

    void add_driver(string name, string detail, int age, string carType, string carNo, int x_coordinate, int y_coordinate){
      Driver d(name, detail, age, carType, carNo, x_coordinate, y_coordinate);
      drivers.push_back(d);
    }

    void updateUserLocation(string name, int x_coordinate, int y_coordinate){
      for(auto &it: users){
        if(it.getUserName() == name){
          it.setXcoordinate(x_coordinate);
          it.setYcoordinate(y_coordinate);
        }
      }
    }

    void updateDriverLocation(string name, int x_coordinate, int y_coordinate){
      for(auto &it: drivers){
        if(it.getDriverName() == name){
          it.setXcoordinate(x_coordinate);
          it.setYcoordinate(y_coordinate);
        }
      }
    }

    void changeStatus(string name, bool status){
      for(auto &it: drivers){
        if(it.getDriverName() == name){
          it.setIsAvailable(status);
        }
      }
    }

    vector<Driver> findRide(string name, int start_x, int start_y, int end_x, int end_y){
      vector<Driver> AvailableRides;
      for(auto &driver: drivers){
        if(driver.IsAvailabe() && distanceFromUser(driver.getXcoordinate(), driver.getYcoordinate(), start_x, start_y) <= 5){
          AvailableRides.push_back(driver);
        }
      }
      if(AvailableRides.size() == 0) cout<<"No ride found"<<endl;
      else{
        for(auto &it: users){
          if(it.getUserName() == name){
            it.setRideSt(start_x, start_y);
            it.setRideEn(end_x, end_y);
          }
        }
      }
      return AvailableRides;
    }

    int distanceFromUser(int a, int b, int c, int d){
      return abs(c-a)+abs(d-b);
    }

    void chooseRide(string userName, string driverName){
      for(auto &driver: drivers){
        if(driver.getDriverName() == driverName){
          if(driver.IsAvailabe()){
            for(auto &user: users){
              if(user.getUserName() == userName){
                cout<<"ride started"<<endl;
                addPayment(user, distanceFromUser(user.getRideSt().first, user.getRideSt().second, user.getRideEn().first, user.getRideEn().second));
                
                addEarning(driver, distanceFromUser(user.getRideSt().first, user.getRideSt().second, user.getRideEn().first, user.getRideEn().second));
                updateUserLocation(user.getUserName(), user.getRideEn().first, user.getRideEn().second);
                return;
              }
            }
            cout<<"No Users are found on the Application"<<endl;
          }else{
            cout<<"No Drivers are available"<<endl;
          }
        }
      }
    }

    void addPayment(User &u1, int totalFare){
      u1.setTotalBill(totalFare);
    }

    void addEarning(Driver &d1, int totalEarning){
      d1.setTotalEarn(totalEarning);
    }

    int calculateBill(string name){
      for(auto &it: users){
        if(it.getUserName() == name){
          return it.getTotalBill();
        }
      }
      return 0;
    }

    void findTotalEarning(){
      for(auto &it: drivers){
        cout<<it.getDriverName()<<" earn Rs."<<it.getTotalEarnings()<<endl;
      }
    }
    // void Location(){
    //   for(auto &it: users){
    //     cout<<"User: "<<it.getUserName()<<" "<<it.getXcoordinate()<<","<<it.getYcoordinate()<<endl;
    //   }

    //   for(auto it: drivers){
    //     cout<<"Driver: "<<it.getDriverName()<<" "<<it.getXcoordinate()<<","<<it.getYcoordinate()<<endl;
    //   }
    // }
};

int main(){
  try{
    Application App;

    App.add_user("Abhay", "M", 23);
    App.updateUserLocation("Abhay", 0, 0);
    
    App.add_user("Vikram", "M", 29);
    App.updateUserLocation("Vikram", 10, 0);
    
    App.add_user("Kriti", "F", 22);
    App.updateUserLocation("Kriti", 15, 6);

     App.add_driver("Driver1", "M", 22, "Swift", "KA-01-12345", 10 ,1);
     App.add_driver("Driver2", "M", 29, "Swift", "KA-01-12345", 11 ,10);
     App.add_driver("Driver3", "M", 24, "Swift", "KA-01-12345", 5, 3);

    // App.Location();
    // cout<<endl;

    vector<Driver> find_ride = App.findRide("Abhay", 0, 0, 20, 1);
    for(auto driver: find_ride){
      cout<<driver.getDriverName()<<" [Available]"<<endl;
    }

    find_ride = App.findRide("Vikram", 10, 0, 15, 3);
    for(auto driver: find_ride){
      cout<<driver.getDriverName()<<" [Available]"<<endl;
    }

    App.chooseRide("Vikram", "Driver1");
    cout<<"Ride ended Bill amount Rs. "<<App.calculateBill("Vikram")<<endl;

    App.changeStatus("Driver1", false);

    find_ride = App.findRide("Kriti", 15, 6, 20, 4);

    App.findTotalEarning();
  }catch(const exception &e){
    cout<<"Exception: "<<e.what()<<endl;
  }
  return 0;
}