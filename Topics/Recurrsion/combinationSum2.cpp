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
^ rember in such code u have to also make sure that the duplciates are not there 
^ hence alwasy right a code to 

for now its unclear why we have to recall the funciotn again in duplciate rewomval but we have to do that 

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
void findCombination(int ind, int target, vector < int > & arr, vector < vector < int >> & ans, vector < int > & ds) {
  if (target == 0) {
    ans.push_back(ds);
    return;
  }
  for (int i = ind; i < arr.size(); i++) {
    if (i > ind && arr[i] == arr[i - 1]) continue;
    if (arr[i] > target) break;
    ds.push_back(arr[i]);
    findCombination(i + 1, target - arr[i], arr, ans, ds);
    ds.pop_back();
  }
}
vector < vector < int >> combinationSum2(vector < int > & candidates, int target) {
  sort(candidates.begin(), candidates.end());
  vector < vector < int >> ans;
  vector < int > ds;
  findCombination(0, target, candidates, ans, ds);
  return ans;
}
int main() {
  vector<int> v{10,1,2,7,6,1,5};
  vector < vector < int >> comb = combinationSum2(v, 8);
  cout << "[ ";
  for (int i = 0; i < comb.size(); i++) {
    cout << "[ ";
    for (int j = 0; j < comb[i].size(); j++) {
      cout << comb[i][j] << " ";
    }
    cout << "]";
  }
  cout << " ]";
}


/*
working solution but wait there exits a better solution
*/
  while (i + 1 < nums.size() && nums[i] == nums[i + 1]) {
            i++;
        }

the above code is used to removeduplicates leatrn it propelrry 

/*
okay now understand me the diffrence her is that h */



