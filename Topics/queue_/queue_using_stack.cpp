#include<bits/stdc++.h>
using namespace std;
struct queue {
    stack<int> input,output;
    // we are gooing to need two 
    // stack to reverse the behvoir or 
    // lifo into FIFO 


    void push(int data){
        // makung output stack such atht whenever we take so

        // someting from it behAVES IN fifo

        while(!input.empty()){
            output.push(input.top());
            input.pop();
        }
        input.push(data);


        while(!output.empty()){
            input.push(output.top());
            output.pop();
        }
    }

    int pop(){

        if(input.empty()){
            cout<<"stack is empty"<<endl;
            exit(0);
        }

        int val = input.top();
        input.pop();
        return val;
    }

    int top(){
        if(input.empty()){
            cout<<"stack is empty"<<endl;
            return 0;
        }
        return input.top();
    }
    int size(){
        return input.size();
    }

    
};