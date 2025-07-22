#include<bits/stdc++.h>
using namespace std;

struct node{

    int data ;
    node* left;
    node* right;

    node(int val){
        data = val;

        left=right=nullptr;
    }
};



int main(){


    node* head = new node(2);

    head->left= new node(3);
    head->right = new node(4);
    head->right->right = new node(5);



    // TRAVERSSAl

    // dfs ( stack)
    // preorder 
    // inroder 
    // postorrder 


    // bfs   =( queue) 

    // level order traversl






}