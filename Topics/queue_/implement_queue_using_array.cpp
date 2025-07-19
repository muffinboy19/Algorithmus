#include<bits/stdc++.h>
using namespace std;

class Queue{


    int *arr ; // our arrya
    int start;
    int end;
    int currsize;
    int maxsize;



    Queue(){
        arr = new int[16];
        start = -1;
        end = -1;
        currsize = 0;
    }
    // by deaffult of 16 size 

    Queue(int maxsize){
        this->maxsize  = maxsize;
        arr = new  int[maxsize];
        start = -1;
        end = -1;
        currsize = 0;
    }


    /// implemetnikg the fuciotns of it 

    void push(int x){

        if(currsize == maxsize){
            cout<<"queue is full cant push"<<endl;
            return;
        }
        if(end==-1){
            start=0;
            end=0;
        }
        else{

            // this portion is the make the end 
            // go round around teh corner 
            end = (end+1)%maxsize;
        }
        arr[end] = x;
        currsize++;
    }

    int pop(){
        if(start==-1){
            cout<<"queue is empty bro"<<endl;
            return 0;
        }

        int popped = arr[start];
        if(currsize==1){
            start=-1;
            end=-1;
        }
        else{
            // bcz teh start is also moving 
            // fforward not bckwrad we ar not doign start--;
            start = (start+1)%maxsize;
        }
        currsize--;
        return popped;
    }

    int top(){
        if(start==-1){
            cout<<"the list is empty"<<endl;
            return 0;
        }
        return arr[start];
    }
    int size(){
        return currsize;
    }



};