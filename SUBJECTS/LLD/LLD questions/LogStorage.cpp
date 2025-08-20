// #include <bits/stdc++.h>
// using namespace std;

// class Log{
//   private:
//     vector<pair<int,string>> log;
//     map<string, int> d;
//   public:
//     Log(){
//       d["Year"]=4;
//       d["Month"]=7;
//       d["Day"]=10;
//       d["Hour"]=13;
//       d["Minute"]=16;
//       d["Second"]=19;
//     };
//     void put(int id, string timestamp){
//       log.push_back({id, timestamp});
//     }
//     vector<int> retrieve(string start, string end, string granularity){
//       vector<int> ans;
//       int len = d[granularity];
//       start = start.substr(0, len);
//       end = end.substr(0, len);
//       for(auto &it: log){
//         if(start<=it.second.substr(0, len) && it.second.substr(0, len)<=end){
//           ans.push_back(it.first);
//         }
//       }
//       return ans;
//     }
// };

// int main(){
//   Log *l = new Log();
//   l->put(1, "2017:01:01:23:59:59");
//   l->put(2, "2017:01:01:22:59:59");
//   l->put(3, "2016:01:01:00:00:00");
//   vector<int> v = l->retrieve("2016:01:01:01:01:01", "2017:01:01:23:00:00", "Year");
//   for(auto &it: v) cout<<it<<" ";
//   cout<<endl;
//   v = l->retrieve("2016:01:01:01:01:01", "2017:01:01:23:00:00", "Hour");
//   for(auto &it: v) cout<<it<<" ";
//   cout<<endl;
//   return 0;
// }