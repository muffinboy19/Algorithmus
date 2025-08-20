/*
In this algo we will leanr how to manipulate the max element or hte min elent in a window throught the arary 

^ min max elment in a window 
^ here we used deque for a poping and entering system 

also called monotonically decresing queue 


*/  


/*
Algorithim : 
step  1 : if we have a windows and if we see a value taht is greater than its prevous values 
then we can elminates the use of those prevous values 
step 2: keep pushing untill u get a greater value then empty the que and push the large value 
step 3 : if you encouter any small value then the larger value in the deque then you just smiply push 
it in the dquee
step 4: we would add teh leftmost value of the deque to the output array 


tc : we aded every value and crossed out also but they are o(1) 
 */
#include<bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    

    return 0;
}