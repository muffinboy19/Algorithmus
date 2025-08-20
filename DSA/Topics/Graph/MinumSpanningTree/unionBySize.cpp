/*
in this code we will perfrom uinion by size*/


#include<bits/stdc++.h>
using namespace std;


vector<int> size,parent;

class DisjointSet{
public:
 disjoinset(int n){
    size.resize(n+1,1);
    parent.reisze(n+1);

    for(int i=0;i<=n;i++){
        parent[i] = i;
    }
 }
 
}

