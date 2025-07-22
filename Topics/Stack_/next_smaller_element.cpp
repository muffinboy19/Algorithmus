// User function template for C++
class Solution {
  public:
    void immediateSmaller(vector<int>& arr) {
        //  code here
        
        
        for(int i=0;i<arr.size()-1;i++){
            if(arr[i]>arr[i+1])arr[i]=arr[i+1];
            else arr[i] = -1;
        }
        arr[arr.size()-1] = -1;
        
        return;
    }
};

// checked the editorial to this was not a stack question to be optmiaed 
