// https://leetcode.com/problems/climbing-stairs/

#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int climbStairs(int n) {
              vector<int> dp(n+1, -1);
              return climb(n, dp);
        }
        int climb(int n , vector<int> &dp){
           if(n==1 ) return 1;
           if(n==2) return 2;
           if(dp[n]!=-1) return dp[n];
    
           return dp[n]= climb(n-1 , dp) + climb(n-2 , dp);
        }
    };