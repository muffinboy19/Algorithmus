// in this cod ewe will implent  a  priority queu using binary heap 



// in this code we will implemnet priority queu using 
// binary heap 

// here every imtem has a priority assciated with it
// an element whith heigh  priority is dequeued before an element iwth low priost 
//

/*
Binary heap is a binary tree 
1. complete tree 
2. it has such a proptery that enables it to 
   be stored in array
3. it is either a min heap or max heap 


MIN HEAP :
    root must be the minum at the bottom 
MAX HEAP :
    root must be teh maximum among all of hte other 
    
    
insert()
extractMax()
remove(i)
getMax()
changePriority(i,p)


*/

#include<bits/stdc++.h>
using namespace std;

int parent(int i){
    return (i-1)/2; 
}