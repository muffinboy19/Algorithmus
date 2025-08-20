// #include <bits/stdc++.h>
// using namespace std;

// class HitCounter{
//   private:
//     queue<int> q;
//     void clear(int timestamp){
//       int prevTime = timestamp - 300;
//       while(!q.empty() && q.front() <= prevTime){
//         q.pop();
//       }
//     }
//   public:
//     HitCounter(){
      
//     }
//     void hit(int timestamp){
//       clear(timestamp);
//       q.push(timestamp);
//     }
//     int getHits(int timestamp){
//       clear(timestamp);
//       return q.size();
//     }
// };

// int main(){
//   return 0;
// }