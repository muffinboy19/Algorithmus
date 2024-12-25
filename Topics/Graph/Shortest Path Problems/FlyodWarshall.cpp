/*
This is the Flyod Warshall algo 

this algo is not restricted to a single source 
from every node to every other node 

multisource shortrest path algo
    - can also detc the  negative cycle
    here we do use precomputed results 

    store the data in a cost matrix 


this graphs is basically a brute force only having genral time complexity as n^3


here what we do is we got thoght each of node to all of hte nodes so that we can 
compute value of each of them 

example of via 0 
    [3][2] = [3][0] + [0][2];

example of via 1 
    [3][2] = [3][1] + [1][2];



how to detect a negative cycle 

    if the self costing of any cycle comes out to be negative then 
    we can wsay that a negtive cycle exits there
    
*/