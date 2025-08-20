#include <bits/stdc++.h>
using namespace std;

// Function to solve the problem using dynamic programming
int solveUtil(int n, vector<int>& arr, vector<int>& dp, vector<vector<int>>& subseq) {
    // Base case: If there are no elements in the array, return 0
    dp[0] = arr[0];
    subseq[0].push_back(arr[0]);
    
    // Iterate through the elements of the array
    for (int i = 1; i < n; i++) {
        // Calculate the maximum value by either picking the current element
        // or not picking it (i.e., taking the maximum of dp[i-2] + arr[i] and dp[i-1])
        int pick = arr[i];
        if (i > 1) {
            pick += dp[i - 2];
        }
        int nonPick = dp[i - 1];
        
        // Store the maximum value in the dp array
        if (pick > nonPick) {
            dp[i] = pick;
            subseq[i] = subseq[i - 2];
            subseq[i].push_back(arr[i]);
        } else {
            dp[i] = nonPick;
            subseq[i] = subseq[i - 1];
        }
    }
    
    // The last element of the dp array will contain the maximum sum
    return dp[n - 1];
}

// Function to initiate the solving process
int solve(int n, vector<int>& arr) {
    vector<int> dp(n, 0); // Initialize dp array with 0
    vector<vector<int>> subseq(n); // To store subsequences
    int result = solveUtil(n, arr, dp, subseq);
    
    // Print all subsequences visited
    cout << "Visited Subsequences:\n";
    for (int i = 0; i < n; i++) {
        cout << "{ ";
        for (int num : subseq[i]) {
            cout << num << " ";
        }
        cout << "}\n";
    }
    
    return result;
}

int main() {
    vector<int> arr{2, 1, 1, 2};
    int n = arr.size();
    
    // Call the solve function and print the result
    cout << "Max Sum: " << solve(n, arr) << "\n";

    return 0;
}
