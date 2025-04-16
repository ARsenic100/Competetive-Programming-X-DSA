//https://www.geeksforgeeks.org/problems/geek-jump/0
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int minCost(vector<int>& height) {
        int n= height.size();
        vector<int> dp(n, -1);
        return f(height ,  n-1 , dp);
    }
    int f(vector<int>& height ,int ind , vector<int> &dp){
        if(ind==0) return 0;
        if(dp[ind] != -1) return dp[ind];
        
        int left = f(height ,ind -1 , dp) + abs(height[ind]- height[ind-1]);
        int right = 1e9;
        
        if(ind>1){
             right = f(height ,ind -2 , dp) + abs(height[ind]- height[ind-2]);
        }
        return dp[ind] = min(left , right);
    }


};

