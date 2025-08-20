#include <bits/stdc++.h>
using namespace std;

class User{
  private:
    string userId, name;
  public:
    User(string &userId, string &name){
      this->userId = userId;
      this->name = name;
    }
    const string getuserId() const{
      return this->userId;
    }
    const string getName(){
      return this->name;
    }
};

class Application{
  private:
    map<User, int> users;
  public:
    Application() = default;
    void addUser(string &id, string &name){
      User user(id, name);
      users[user]=1;
    }
    void deactivate(string &userId){
      for(auto &user: users){
        if(user.first.getuserId() == userId){
          users.erase(user.first);
          break;
        }
      }
    }
};

int main(){
  return 0;
}