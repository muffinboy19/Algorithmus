#include <bits/stdc++.h>
using namespace std;

class WhatsappPoll{
  string pollId;
  string question;
  vector<string> options;
  bool isAllowMultipleAnswer;
  unordered_map<int, int> response;
  unordered_map<string, vector<int>> userResponse;

  string generateId(){
    return to_string(rand()%1000000007+1);
  }

  public:
    WhatsappPoll(string question, vector<string>option, bool isAllowMultipleAnswer = false){
      pollId = generateId();
      this->question = question;
      this->options = option;
      this->isAllowMultipleAnswer = isAllowMultipleAnswer;
      for(int i=0;i<option.size();i++){
        response[i]=0;
      }
      userResponse.clear();
    }

    string getPollId(){ return pollId;}
    string getQuestion(){ return question;}
    vector<string> getOption(){ return options;}
    unordered_map<int,int> getresult(){ return response;}
    unordered_map<string, vector<int>> getuserResponse(){ return userResponse;}

    bool castVote(string userId, int optionIdx){
      if(optionIdx<0 || optionIdx>=options.size()) return false;
      if(userResponse.find(userId) == userResponse.end()){
        userResponse[userId].push_back(optionIdx);
        response[optionIdx]+=1;
        return true;
      }
      for(auto it: userResponse[userId]){
        if(it==optionIdx){
          return false;
        }
      }
      userResponse[userId].push_back(optionIdx);
      response[optionIdx]+=1;
      return true;
    }

    void displayPoll(){
      cout<<"PollId: "<<this->pollId<<" "<<"Question: "<<this->question<<endl;
      for(int i=0;i<options.size();i++){
        cout<<i+1<<". "<<options[i]<<endl;
      }
    }
};


class User {
  private:
      string userId;
      string name;
  
  public:
      User(string id, string n) : userId(id), name(n) {}
  
      string getUserId() { return userId; }
      string getName() { return name; }
  
      bool createPoll(WhatsappPoll& poll) {
          poll.displayPoll();
          return true;
      }
  
      bool voteInPoll(WhatsappPoll& poll, int optionIndex) {
          return poll.castVote(userId, optionIndex);
      }
};

class MessageHandler {
  public:
    static void sendPoll(WhatsappPoll& poll, User& user) {
        cout << "Sending poll to " << user.getName() << "\n";
    }

    static void receiveResponse(WhatsappPoll& poll, User& user, int optionIndex) {
        if (poll.castVote(user.getUserId(), optionIndex)) {
            cout << "Vote registered successfully for " << user.getName() << "\n";
        } else {
            cout << "Vote failed for " << user.getName() << "\n";
        }
    }
};



int main() {
    User user1("001", "Alice");
    User user2("002", "Bob");

    vector<string> options = {"Option 1", "Option 2", "Option 3"};
    WhatsappPoll poll("What is your favorite option?", options);

    user1.createPoll(poll);
    MessageHandler::sendPoll(poll, user2);

    MessageHandler::receiveResponse(poll, user2, 1);

    // Display results
    auto results = poll.getresult();
    for (const auto& result : results) {
        std::cout << "Option " << result.first + 1 << ": " << result.second << " votes\n";
    }

    return 0;
}
