// #include <bits/stdc++.h>
// using namespace std;

// class Trie{
//   private:
//     int val;
//     map<string, Trie*> file;
//     vector<string> split(string t, char delimeter){
//       stringstream str(t);
//       vector<string> ans;
//       while(getline(str, t, delimeter)){
//         ans.push_back(t);
//       }
//       return ans;
//     }
//   public:
//     Trie(int val){
//       this->val = val;
//     }
//     bool insert(string &path, int val){
//       Trie* node = this;
//       auto ps = split(path, '/');
//       for(int i=1;i<ps.size()-1;i++){
//         if(node->file.find(ps[i])==node->file.end()){
//           return false;
//         }
//         node = node->file[ps[i]];
//       }

//       if(node->file.find(ps.back())!=node->file.end()) return false;
//       node->file[ps.back()] = new Trie(val);
//       return true;
//     }
//     int search(string &path){
//       Trie* node = this;
//       auto ps = split(path, '/');
//       for(int i=1;i<ps.size();i++){
//         if(node->file.find(ps[i])==node->file.end()){
//           return -1;
//         }
//         node = node->file[ps[i]];
//       }
//       return node->val;
//     }
// };

// class FileSystem{
//   private:
//     Trie* trie;
//   public:
//     FileSystem(){
//       trie = new Trie(-1);
//     }
//     bool createPath(string path, int value){
//       return trie->insert(path, value);
//     }
//     int getStringPath(string path){
//       return trie->search(path);
//     }
// };


// int main(){
//   FileSystem *fs = new FileSystem();
//   cout<<fs->createPath("/leet", 1)<<endl;
//   cout<<fs->createPath("/leet/code", 2)<<endl;
//   cout<<fs->getStringPath("/leet/code")<<endl;
//   cout<<fs->createPath("/c/d", 1)<<endl;
//   cout<<fs->getStringPath("/c")<<endl;
//   return 0;
// }