// #include <bits/stdc++.h>
// using namespace std;

// class PhoneDirectory{
//   private:
//     set<int> pool;
//   public:
//     PhoneDirectory(int maxNumber){
//       for(int i=1;i<=maxNumber;i++){
//         pool.insert(i);
//       }
//     }

//     int get(){
//       if(pool.empty()) return -1;
//       int ans = *pool.begin();
//       pool.erase(ans);
//       return ans;
//     }

//     bool check(int number){
//       if(pool.find(number) != pool.end()){
//         return true;
//       }
//       return false;
//     }

//     void release(int number){
//       if(check(number)) return;
//       pool.insert(number);
//     }
// };