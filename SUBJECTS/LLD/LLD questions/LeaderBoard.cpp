#include <bits/stdc++.h>
using namespace std;

class User{
  private:
    string name, email;
    int score, userId;
  public:
    User(int userId, string name, string email){
      this->userId = userId;
      this->name = name;
      this->email = email;
      this->score = 0;
    }
    const string getName(){
      return this->name;
    } 
    const string getEmail(){
      return this->email;
    }
    int getScore(){
      return this->score;
    }
    void setScore(int val){
      this->score = val;
    }
    int getId(){
      return this->userId;
    }
};

class LeaderBoard{
  private:
    vector<User*> users;
    map<string, User*> nameToUser;
    set<pair<int,pair<int,string>>> Rank;
    int counterId = 0;
  public:
    LeaderBoard(){
      counterId = 0;
    }
    void addUser(string name, string email){
      User *u = new User(counterId, name, email);
      users.push_back(u);
      nameToUser[name] = u;
      Rank.insert({0, {counterId, name}});
      counterId += 1;
    }
    void updateScore(string name, int newScore){
      User* u = nameToUser[name];
      int olderScore = u->getScore();
      Rank.erase({olderScore, {u->getId(), u->getName()}});
      u->setScore(newScore);
      Rank.insert({newScore, {u->getId(), u->getName()}});
    }
    int getRank(string name){
      int rank = 0;
      for(auto &it: Rank){
        rank+=1;
        if(it.second.second == name){
          return rank;
        }
      }
      return -1;
    }

    vector<string> getFirstK(int k){
      vector<string> ans;
      for(auto &it: Rank){
        if(k==0){
          break;
        }
        ans.push_back(it.second.second);
        k-=1;
      }
      return ans;
    }

    vector<string> TotalUser(){
      vector<string> ans;
      for(auto it: users){
        ans.push_back(it->getName());
      }
      return ans;
    }

    vector<int> TotalUserscore(){
      vector<int> ans;
      for(auto it: users){
        ans.push_back(it->getScore());
      }
      return ans;
    }
};


int main(){
  LeaderBoard *l = new LeaderBoard();
  l->addUser("Hitesh1", "xyz11@gmail.com");
  l->addUser("Hitesh2", "xyz12@gmail.com");
  l->addUser("Hitesh3", "xyz13@gmail.com");
  l->addUser("Hitesh4", "xyz14@gmail.com");
  l->addUser("Hitesh5", "xyz15@gmail.com");
  l->addUser("Hitesh6", "xyz16@gmail.com");

  

  l->updateScore("Hitesh1", 50);
  l->updateScore("Hitesh3", 10);
  l->updateScore("Hitesh4", 510);
  l->updateScore("Hitesh2", 502);
  l->updateScore("Hitesh6", 502);
  l->updateScore("Hitesh5", 506);

  vector<int> v = l->TotalUserscore();
  for(auto &it: v){
    cout<<it<<" ";
  }
  cout<<endl;

  cout<<l->getRank("Hitesh2")<<endl;
  vector<string> ans = l->getFirstK(4);
  for(auto &it: ans){
    cout<<it<<" ";
  }
  cout<<endl;
  
  return 0;
}