#include<bits/stdc++.h>
using namespace std;

class Stack{
    queue<int> q;
    // only using queue thats why 

    void push(int x){
        int s = q.size();
        q.push(x);
        for(int i=0;i<s;i++){
            q.push(q.front());
            q.pop();
        }
    }

    int pop(){
        int n = q.front();
        q.pop();
        return n;
    }
    int top(){
        return q.front();
    }
    int size(){
        return q.size();
    }
};
