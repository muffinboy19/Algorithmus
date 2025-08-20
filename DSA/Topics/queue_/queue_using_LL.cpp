#include<bits/stdc++.h>
using namespace std;

class queueNode{
    public:
    int val;
    queueNode* next;

    queueNode(int data){
        val  = data;
        next = nullptr;
    }


};

class queue{
private:
    queueNode* front = nullptr;
    queueNode* end = nullptr;
    int size;


public:
    queue(){
        front = nullptr;    
        end  = nullptr; 
        size  =0;// dok why is ther her?
    }

    bool isempty(){
        return front==nullptr;
    }

    void push(int newval){
        queueNode* newnode = new queueNode(newval);

        // is equal to push 

        if(isempty()){
            front = end = newnode;
        }
        else{

            end->next = newnode;
            end = newnode;

            size++;
        }

    }

    int pop(){

        if(isempty()){
            cout<<"this queue is mepty "<<endl;
            return -1;
        }

        queueNode* temp = front;
        int n = temp->val;
        front = front->next;
        delete temp;
        size--;

        if(front==nullptr){
            end =nullptr; // maeyge not necssar y
        }
        return n;
    }

    int peek(){
        return front->val;
    }

    int size(){
        return size;
    }

    void print(){

        queueNode* temp  = front;

        while(temp!=nullptr){
            cout<<temp->val<<" ";
            temp = temp->next;
        }
        cout<<endl;
    }

};