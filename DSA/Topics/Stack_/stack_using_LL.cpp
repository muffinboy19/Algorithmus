#include<bits/stdc++.h>
using namespace std;

struct stackNode{
    int data;
    stackNode* next;
    int size;

    // to declare it 

    stackNode(int d){
        data = d;
        next = nullptr;
    }

    struct stack{
        stackNode * top;
        int size;



        stack(){
            top = nullptr;
            size=0;
        }

        void push(int x){
            stackNode* newele = new stackNode(x);
            newele->next = top;

            top = newele;
            size++;
        }

        int pop(){
            if(top==nullptr){
                cout<<"htis means the stack is empty"<<endl;
                return -1;
            }
            int data = top->data;
            stackNode* temp = top;
            top = top->next;
            delete temp;
            size--;
            return data;


        }

        int size(){
            return size;
        }

        int top(){
            return top->data;
        }

        void print(){
            stackNode* curr = top;
            while( curr!=nullptr){
                cout<<curr->data<<" ";
                curr = curr->next;
            }
        }
    }
};