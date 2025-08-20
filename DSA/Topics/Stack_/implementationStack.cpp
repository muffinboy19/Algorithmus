// firset we are gioign to implmement stack using  aan 
//& array 


#include<bits/stdc++.h>
using namespace std;


class Stack {
    int size;
    int *arr; /// this is the array pointer a point atht would point to the 
    // arya 
    int top;


    public:
    Stack(){
        top = -1; // curentl its housld empty 

        size = 1000;

        arr = new int[size]; // normal method to decalere a new aray 
        // nothign wrong int it 
    }

    void push(int x){
        top++; // top is the couner pointeer onl 
        arr[top]  = x;
    }

    int pop(){
        // okay here it is also returing also

        int x = arr[top];
        top--;
        return x;
    }

    int top(){
        return arr[top];
    }
    
    int size(){
        return top+1;
    }
};




// a clas needs a semicolon at the last.

int main(){

    return 0;
}