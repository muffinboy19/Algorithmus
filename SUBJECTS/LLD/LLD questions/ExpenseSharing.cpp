#include <bits/stdc++.h>
using namespace std;

// Expense::
enum Expense{EQUAL, EXACT, PERCENT};

// User Class::
class User{
    
  public:
    int userId;
    string name, email, mobNo;
    User(int userId, string name, string email, string mobNo){
       this->userId = userId;
       this->name = name;
       this->email = email;
       this->mobNo = mobNo;
    }

    bool operator<(const User &other) const{
        return userId < other.userId;
    }
};

// BalanceSheet Class::
class BalanceSheet{
   map<User,map<User,double>> balance;

   public:
      void addBalance(User payer, vector<User> participants, vector<double> amount){
        for(int i=0;i<participants.size();i++){
          if(participants[i].name != payer.name){
            balance[participants[i]][payer] += amount[i];
            balance[payer][participants[i]] -= amount[i];
          }
        }
      }

      void showBalance(){
        bool noBalance = true;
        for(auto payer: balance){
           for(auto taker: payer.second){
              if(taker.second!=0){
                if(taker.second>0){
                  cout<<payer.first.name<<" owes "<<taker.first.name<<": "<<taker.second<<endl;
                  noBalance = false;
                }
              }
           }
        }
        if(noBalance) cout<<"No Balance"<<endl;
      }

      void showUserBalance(User user){
        bool noBalance = true;

        for(auto user1: balance){
          if(user1.first.userId != user.userId){
            if(user1.second.find(user) != user1.second.end()){
              if(user1.second[user] != 0){
                if(user1.second[user] > 0){
                  cout<<user1.first.name<<" owes "<<user.name<<": "<<user1.second[user]<<endl;
                }else{
                  cout<<user.name<<" owes "<<user1.first.name<<": "<<abs(user1.second[user])<<endl;
                }
                noBalance = false;
              }
            }
          }
        }
        
        
        if(noBalance){
          cout<<"No balances"<<endl;
        }
      }
};

// Split Class
class Split{
   public:
   vector<double> split(string type, User payer, vector<User> participants, vector<double> amount, double Fee){
     vector<double> answer;
     if(type == "EQUAL"){
       int noOfparticipants = participants.size();
       double eachHave = Fee/noOfparticipants;
       for(int i=0;i<noOfparticipants;i++){
         answer.push_back(eachHave);
       }
     }else if(type == "EXACT"){
       for(int i=0;i<participants.size();i++){
         answer.push_back(amount[i]);
       }
     }else{
       for(int i=0;i<participants.size();i++){
         double getVal = (amount[i]*Fee)/100;
         answer.push_back(getVal);
       }
     }
     return answer;
   }
};

int main(){
  User u1(1, "User1", "u1.@gmail.com", "81XXX");
  User u2(2, "User2", "u2.@gmail.com", "82XXX");
  User u3(3, "User3", "u3.@gmail.com", "83XXX");
  User u4(4, "User4", "u4.@gmail.com", "84XXX");

  BalanceSheet balance;
  Split spl;

  cout<<"SHOW"<<endl;
  balance.showBalance();

  cout<<"SHOW u1"<<endl;
  balance.showUserBalance(u1);
  
  cout<<"EXPENSE u1 1000 4 u1 u2 u3 u4 EQUAL"<<endl;
  vector<double> amounts = spl.split("EQUAL", u1, {u1, u2, u3, u4}, {}, 1000.0);
  balance.addBalance(u1, {u1, u2, u3, u4}, amounts);

  cout<<"SHOW u4"<<endl;
  balance.showUserBalance(u4);

  cout<<"SHOW u1"<<endl;
  balance.showUserBalance(u1);
  
  cout<<"EXPENSE u1 1250 2 u2 u3 EXACT 370 880"<<endl;
  amounts = spl.split("EXACT", u1, {u2, u3}, {370, 880}, 1250);
  balance.addBalance(u1, {u2, u3}, amounts);

  cout<<"SHOW"<<endl;
  balance.showBalance();
  cout<<"EXPENSE u4 1200 4 u1 u2 u3 u4 PERCENT 40 20 20 20"<<endl;
  amounts = spl.split("PERCENT", u4, {u1, u2, u3, u4}, {40, 20, 20, 20}, 1200);
  balance.addBalance(u4, {u1, u2, u3, u4}, amounts);

  cout<<"SHOW u1"<<endl;
  balance.showUserBalance(u1);

  cout<<"SHOW"<<endl;
  balance.showBalance();
  
  
  return 0;
}
