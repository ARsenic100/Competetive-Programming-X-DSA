//https://www.geeksforgeeks.org/problems/minimal-cost/0?ref=gcse_ind

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int minimizeCost(int k, vector<int>& arr) {
        // Code here
        int n= arr.size();
        vector<int> dp(n, -1);
        return f(arr ,  n-1 , dp , k);
        
    }
    int f(vector<int>& arr ,int ind , vector<int> &dp , int k){
        if(ind==0) return 0;
        if(dp[ind] != -1) return dp[ind];
        
        int mini = 1e9;
        for(int i=1 ; i<=k ; i++){
            if(ind-i>=0){
              mini = min( mini ,   f(arr ,ind -i , dp , k) + abs(arr[ind]- arr[ind-i]));
            }
        }
        return dp[ind] = mini;
    }

};
