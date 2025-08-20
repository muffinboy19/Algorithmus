/*
this file is going to containt the heap and binar yimplmetiona of hte minmium distance maximum of the gas station qu4etiwon */ 

 

 #include<bits/stdc++.h>
 using namespace std;
double minimiseMaxDistance(vector<int> &arr, int k){
	// Write your code here.	
	long long int n = arr.size();
    vector<int> howmany(n - 1, 0);
    priority_queue<pair<long double, int>> pq;
    for (int i = 0; i < n - 1; i++) {
        pq.push({(arr[i + 1] - arr[i]), i}); // Fixed syntax error here
    }
	for(int i = 1;i<=k;i++){
		auto toppp = pq.top();pq.pop();
		int currentSectionINdex = toppp.second;
		howmany[currentSectionINdex]++;
		long long int currentDiff = arr[currentSectionINdex+1]-arr[currentSectionINdex];
		long double  newsectionlegnth = currentDiff/(long double)(howmany[currentSectionINdex]+1);
		pq.push({newsectionlegnth,currentSectionINdex});
	}

	return pq.top().first;
}

 int main(){
     ios_base::sync_with_stdio(false);
     cin.tie(nullptr);
     
 
     return 0;
 }