// #include <bits/stdc++.h>
// using namespace std;

// class FoodRatings {
// public:
//     map<string, pair<int, string>>t1;
//     map<string, set<pair<int, string>>>t2;

//     FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
//         for(int i=0;i<foods.size();i++){
//             t2[cuisines[i]].insert({-1*ratings[i], foods[i]});
//             t1[foods[i]] = {ratings[i], cuisines[i]};
//         }
//     }

//     void changeRating(string food, int newRating) {
//         pair<int, string> p1 = t1[food];
//         t1[food].first = newRating;
//         t2[p1.second].erase({-1*p1.first, food});
//         t2[p1.second].insert({-1*newRating, food});
//     }

//     string highestRated(string cuisine) {
//         auto it = t2[cuisine].begin()->second;
//         return it;
//     }
// };

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */