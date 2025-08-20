// #include <bits/stdc++.h>
// using namespace std;

// class UndergroundSystem {
// public:
//     unordered_map<int, pair<string,int>> idToStation;
//     unordered_map<string, pair<int,int>> outTo;
//     UndergroundSystem() {

//     }

//     void checkIn(int id, string stationName, int t) {
//         idToStation[id] = {stationName, t};
//     }

//     void checkOut(int id, string stationName, int t) {
//         auto [station, time] = idToStation[id];
//         auto path = station+'-'+stationName;
//         auto [totalLen, cnt] = outTo[path];
//         outTo[path] = {totalLen+t-time, cnt+1};
//     }

//     double getAverageTime(string startStation, string endStation) {
//         return (double)outTo[startStation+'-'+endStation].first/outTo[startStation+'-'+endStation].second;
//     }
// };

// /**
//  * Your UndergroundSystem object will be instantiated and called as such:
//  * UndergroundSystem* obj = new UndergroundSystem();
//  * obj->checkIn(id,stationName,t);
//  * obj->checkOut(id,stationName,t);
//  * double param_3 = obj->getAverageTime(startStation,endStation);
//  */