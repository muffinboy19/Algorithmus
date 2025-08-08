#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    Node* cont[2];
    bool end  = false;

    bool isthere(int val){
        return cont[val]!=NULL;
    }

    void put(int val , Node* node){
        cont[val] = node;
    }

    Node* get(int val){
        return cont[val];
    }

    bool isEnd(){
        return end==true;
    }

    void makeEnd(){
        end = true;
    }

};

class Trie{
    Node* root;
    public:
    Trie(){
        root = new Node();
    }
    
    void insert(int val){
        Node* curr = root;

        for(int i=31;i>=0;i--){
            int bit = val>>i & 1;
            if(!curr->isthere(bit)){
                curr->put(bit,new Node());
            }
            curr = curr->get(bit);
        }
        curr->makeEnd();
    }

    int getMaxXorWithConstraint(int val, int constraint){

        Node* curr  = root;
        int maxXor = 0;
        for(int i=31;i>=0;i--){
            int bit = val>>i & 1;

            if(curr->isthere(1-bit)){
                if(maxXor>constraint)return -1;
                maxXor = maxXor | 1<<i;
                curr= curr->get(1-bit);

            }
            else {
                curr = curr->get(bit);
            }
        }
        return maxXor;
    }

};
