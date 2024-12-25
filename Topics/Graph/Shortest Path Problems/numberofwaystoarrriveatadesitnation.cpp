/*
In this coded we will adress what are the number of ways se can reach the destination
on the sohtreted amount of time 
*/


class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {

        vector<vector<pair<long long,long long>>> adjList(n);
        for(auto it:roads){
            adjList[it[0]].push_back({it[1],it[2]});
            adjList[it[1]].push_back({it[0],it[2]});
        }
        vector<long long >dis(n,1e12);
        vector<long long>way(n,0);
        long long mod = (long long)(1e9+7);
        dis[0] = 0;
        way[0]  = 1;
        priority_queue<pair<long long,long long>,vector<pair<long long,long long>>,greater<pair<long long,long long>>> pq;
        pq.push({0,0});
        while(!pq.empty()){
            long long node = pq.top().second;
            long long time = pq.top().first;
            pq.pop();
            for(auto it:adjList[node]){
                long long next = it.first;
                long long newtime = it.second;
                if(time + newtime < dis[next]){
                    dis[next] = time + newtime;
                    way[next]= way[node]%mod;
                    pq.push({dis[next],next});
                }
                else if( time + newtime == dis[next]){
                    way[next] = (way[node] + way[next])%mod;
                    // way[next] = ((way[node])%(1000000007) + (way[next])%(1000000007))%(1000000007);
                }
            }
        }
        cout<<dis[n-1]<<endl;
        return way[n-1];
        
    }
};