#include <bits/stdc++.h>
using namespace std;

class MovieRentingSystem {
    map<int, set<pair<int,int>>> unrented;
    set<tuple<int,int,int>> rented;
    map<pair<int,int>,int> pr;
public:
    MovieRentingSystem(int n, vector<vector<int>>& entries) {
        for(auto &it: entries){
            unrented[it[1]].insert({it[2], it[0]});
            pr[{it[1], it[0]}] = it[2];
        }
    }

    vector<int> search(int movie) {
        vector<int> ans;
        for(auto &it: unrented[movie]){
            ans.push_back(it.second);
            if(ans.size()==5) break;
        }
        return ans;
    }

    void rent(int shop, int movie) {
        int price = pr[{movie, shop}];
        unrented[movie].erase({price, shop});
        rented.emplace(price, shop, movie);
    }

    void drop(int shop, int movie) {
        int price = pr[{movie, shop}];
        unrented[movie].insert({price, shop});
        rented.erase({price, shop, movie});
    }

    vector<vector<int>> report() {
        vector<vector<int>> ans;
        for(auto it = rented.begin(); it != rented.end(); it++){
            auto [p, s, m] = *it;
            ans.push_back({s, m});
            if(ans.size()==5) break;
        }
        return ans;
    }
};

/**
 * Your MovieRentingSystem object will be instantiated and called as such:
 * MovieRentingSystem* obj = new MovieRentingSystem(n, entries);
 * vector<int> param_1 = obj->search(movie);
 * obj->rent(shop,movie);
 * obj->drop(shop,movie);
 * vector<vector<int>> param_4 = obj->report();
 */