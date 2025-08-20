// User function template for C++

// User function template for C++
class Node{
public:
    Node* cont[26];
    bool end = false;
    
    bool ist(char ch){
        return cont[ch-'a']!=NULL;
    }
    
    void put(char ch,Node* node){
        cont[ch-'a'] = node;
    }
    
    Node* get(char ch){
        return cont[ch-'a'];
    }
    void makeEnd(){
        end=true;
    }
    bool isEnd(){
        return end==true;
    }
};
class Trie {
    
  public:
    Node* root;
    Trie() {
        // implement Trie
        root = new Node();
    }

    void insert(string &word) {
        Node* curr = root;
        for(int i=0;i<word.size();i++){
            if(!curr->ist(word[i])){
                curr->put(word[i],new Node());
            }
            curr= curr->get(word[i]);
        }
        curr->makeEnd();
        // insert word into Trie
    }

    bool search(string &word) {
        // search word in the Trie
        Node* curr = root;
        for(int i=0;i<word.size();i++){
            if(!curr->ist(word[i])){
                return false;
            }
            curr= curr->get(word[i]);
        }
        return curr->isEnd();
    }

    bool isPrefix(string &word) {
        // search prefix word in the Trie
        Node* curr = root;
        for(int i=0;i<word.size();i++){
            if(!curr->ist(word[i])){
                return false;
            }
            curr = curr->get(word[i]);
        }
        return true;
    }
    string longestPrefix(string path,Node* root){
        Node* curr = root;
        int ct=0;
        char nextchar;
        Node*  next = NULL;
        for(int i=0;i<26;i++){
            if(curr->cont[i]!=NULL){
                ct++;
                next = curr->cont[i];
                nextchar = 'a' + i ;
            }
            
        }
        
        if(ct>1 || ct==0)return path;
        return longestPrefix(path+=nextchar,next);
        
    }
};
class Solution {
  public:
  
  
    string longestCommonPrefix(vector<string> arr) {
        // your code here
        
        Trie trie;
        for(auto it:arr){
            trie.insert(it);
        }
        
        string ans = "";
        ans = trie.longestPrefix(ans,trie.root);
        return ans;
        
        
        
    }
};