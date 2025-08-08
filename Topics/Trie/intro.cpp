#include<bits/stdc++.h>
using namespace std;


struct Node{
    Node* links[26];// as there are 26 alphabets

    bool flag = false;
    /// to mark the end of the word

    // now to check if the curet node contaisn the letter or not 

    bool containskey(char ch){
        return links[ch-'a']!=NULL;
    }


    void put(char ch,Node* node){
        links[ch-'a'] = node;
    }

    Node* get(char ch){
        return links[ch-'a'];
    }

    void setEnd(){
        flag = true;
    }

    bool isEnd(){
        return flag;
    }



};


class Trie{
private:
    Node* root;
public:

    Trie(){
        root = new Node();
    }

    void insert(string word){
        Node* curr = root;
        for(int i=0;i<word.size();i++){
            if(!curr->containskey(word[i])){
                curr->put(word[i],new Node());
            }
            curr = curr->get(word[i]);
        }
        curr->setEnd();

    }

    bool search(string word){

        Node* node = root;
        for(int i=0;i<word.size();i++){
            if(!node->containskey(word[i])){
                
                return false;
            }
            node= node->get(word[i]);
        }

        return node->isEnd();
    }


    bool startsWith(string prefix){
        Node* node = root;
        for(int i=0;i<prefix.size();i++){
            if(!node->containskey(prefix[i])){
                return false;
            }
            node = node->get(prefix[i]);
        }
        return true;
    }



};
