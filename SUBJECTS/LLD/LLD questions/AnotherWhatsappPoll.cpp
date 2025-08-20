#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Poll{
public:
    string pollid;
    string question;
    vector<string>options;
    unordered_map<string,int>countvotes;
    set<string>voters;
    string createdat;
    set<string>ids;

    Poll() = default;

    Poll(string id,string ques,vector<string>opt,string timestamp){
        pollid=id;
        question=ques;
        options=opt;
        createdat=timestamp;
        for(auto &x:opt){
            countvotes[x]=0;
        }
        ids.insert(id);
    }


    void update(string pollidn,string ques,vector<string>ops){
        if(ids.find(pollidn)==ids.end()){
            throw runtime_error("Not valid id");
        }
        question=ques;
        options=ops;
        countvotes.clear();
         for(auto &x:ops){
            countvotes[x]=0;
        }

        voters.clear();  
       // cout<<"poll updated sucessfully"<<endl;
    }


    void castvote(string pollid,string userid,string option){
        if(voters.find(userid)!=voters.end()){
            throw runtime_error("User already casted vote");

        }
        if(ids.find(pollid)==ids.end()){
            throw runtime_error("Not valid pollid");
        }
        if(countvotes.find(option)==countvotes.end()){
             throw runtime_error("Not valid option");
        }
        countvotes[option]++;
        voters.insert(userid);
        ids.insert(pollid);


    }


    void viewResult(){
        cout<<pollid<<" "<<question<<endl;
        for(auto x:countvotes){
            cout<<x.first<<" "<<x.second<<endl;
        }
    }



};


class System{
private:
    map<string,Poll>mp;
public:
    string createpoll(string q,vector<string>ops,string timestamp){
        string id= to_string(mp.size()+1);
        Poll newPoll(id,q,ops,timestamp);
        mp[id]=newPoll;
        return id;

    }

    string updatepoll(string pollid,string ques,vector<string>ops){
        if(mp.find(pollid)==mp.end()){
            throw runtime_error("Invalid pollid");
        }
        mp[pollid].update(pollid,ques,ops);
        return "Polls updated";
    }

    string deletepoll(string pollid){
        if(mp.find(pollid)==mp.end()){
            throw runtime_error("Invalid pollid");
        }
        mp.erase(pollid);
        return "Succesfully deleted";
    }

    string voteInpoll(string pollid,string userid,string ops){
        if(mp.find(pollid)==mp.end()){
            throw runtime_error("Invalid pollid");
        }
        mp[pollid].castvote(pollid,userid,ops);
        return "Succesfully casted vote";
    }

    void Pollresults(string pollid){
        if(mp.find(pollid)==mp.end()){
            throw runtime_error("Invalid pollid");
        } 
        mp[pollid].viewResult();

    }



};

int main(){
//     Poll: { "pollId": "123", "question": "What is your favorite color?", "options": ["Red", "Blue", "Green", "Yellow"], "createdAt": "2024-07-11T00:00:00Z" }
// Vote: { "pollId": "123", "userId": "user1", "option": "Red", "timestamp": "2024-07-11T01:00:00Z" }
    try{
        System ps;


        string pid1=ps.createpoll(  "What is your favorite color?",{"Red", "Blue", "Green", "Yellow"},  "2024-07-11T00:00:00Z");

        cout<<"Polls created succesfully with ID"<<" "<<pid1<<endl;

            string pid2=ps.createpoll(  "What is your favorite animal?",{"Dog", "cat"},  "2024-07-11T00:00:00Z");

      cout<<"Polls created succesfully with ID"<<" "<<pid2<<endl;


     cout<<pid2<<" "<<endl;


     ps.Pollresults(pid2);  
     ps.voteInpoll(pid2,"manish","cat");
     ps.voteInpoll(pid1,"manish","Blue");
      ps.voteInpoll(pid1,"Kumar","Red");
    // ps.voteInpoll(pid1,"Kumar","Green");
      ps.Pollresults(pid1);
      ps.Pollresults(pid2); 
        ps.updatepoll(pid2,"Updated Ques",{"op1","op2","op3"});
         ps.Pollresults(pid2);
       string ouput= ps.deletepoll(pid2);
        cout<<ouput<<endl;
       ps.Pollresults(pid2);




    }catch(const exception&e){
        cout<<"error"<<" "<<e.what()<<endl;

    }
}