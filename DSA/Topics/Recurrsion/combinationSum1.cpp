/*
here the arary have to putput the subsequnce with the target sum 
use any index  any times 

i feel in this question there is one more type 
pic nopic repick 
as you can pick elments any number of times 

no stil the type here is pick and no pick 
the slight change in the pattern is that when you pick a elments 
the index does not change 
while when you does not pick and elmens you are sure that you do not want ot do anyting with it 
thus now you increase the index


*/

/*
dont get confused 
here the i is for index 
         target is for the tareget sum 
         arr is the array in which we are given the input
         ds is the array which we use to pick or not pick method
         
*/


#include<bits/stdc++.h>
using namespace std;
void ish(int i,int target,vector<int> &arr,vector<int> &ds){
    if(i==arr.size()){
        if(target==0){
            for(auto it:ds){cout<<it<<" ";}cout<<endl;
        }
        return;
    }

    /// pickUP the elemtne 
    if(arr[i]<=target){
        ds.push_back(arr[i]);
        ish(i,target-arr[i],arr,ds);
        ds.pop_back();
    }
    // do not pic this elment 
    ish(i+1,target,arr,ds);
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    vector<int> arr={1,2,3,4,5,6};
    vector<int> ds;
    int target=6
    ;
    ish(0,target,arr,ds);
    

    return 0;
}



/*
JUST BEAUTIFULL 
*/