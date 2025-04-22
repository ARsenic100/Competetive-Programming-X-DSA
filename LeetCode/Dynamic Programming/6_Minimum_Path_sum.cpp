// https://leetcode.com/problems/minimum-path-sum/

#include <bits/stdc++.h>
using namespace std;

class Solution {  
    public:  
        int minPathSum(vector<vector<int>>& grid) {
           int m= grid.size();
           int n= grid[0].size();  
           vector<vector<int>> dp(m , vector<int>(n , -1));
           return f(grid , dp , m-1 , n-1);
        }
    
        int f(vector<vector<int>>& grid , vector<vector<int>>& dp , int m , int n){
              if(m==0 && n==0) return dp[0][0]= grid[0][0];
              if(m<0 || n<0) return 1e9;
    
              if(dp[m][n] != -1) return dp[m][n];
    
              int left = grid[m][n] + f(grid , dp , m , n-1);
              int up=  grid[m][n] + f(grid , dp ,  m-1 , n);
    
              return dp[m][n]= min(left , up);
        }
    };
    