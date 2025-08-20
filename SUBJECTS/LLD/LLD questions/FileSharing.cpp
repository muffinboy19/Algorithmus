#include <bits/stdc++.h>
using namespace std;

class FileSharing{
   private:
     int chunk, id;
     set<int> reused;
     map<int, unordered_set<int>> userChunks;
   public:
     FileSharing(int m){
       chunk = m;
       id = 0;
     }
     int join(vector<int> ownedchunks){
       int userId;
       if(reused.size()==0){
         id += 1;
         userId = id;
       }else{
         userId = *reused.begin();
         reused.erase(reused.begin());
       }
       userChunks[userId] = unordered_set<int>(ownedchunks.begin(), ownedchunks.end());
       return userId;
     }
     void leave(int userId){
       userChunks.erase(userId);
       reused.insert(userId);
     }
     vector<int> request(int userId, int chunkId){
       if(chunkId<1 || chunkId>chunk){
         return {};
       }
       vector<int> ans;
       for(auto &it: userChunks){
         if(it.second.find(chunkId) != it.second.end()){
           ans.push_back(it.first);
         }
       }
       if(ans.size()>0){
         userChunks[userId].insert(chunkId);
       }
       return ans;
     }
};