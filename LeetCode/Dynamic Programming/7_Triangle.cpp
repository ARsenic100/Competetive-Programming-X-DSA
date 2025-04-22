// https://leetcode.com/problems/triangle/

#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int minimumTotal(vector<vector<int>>& triangle) {
           int m= triangle.size();
            
           vector<vector<int>> dp(m);
            for(int j = 0; j < m; j++) {
                int n = triangle[j].size();
                dp[j] = vector<int>(n, -1);  
            }
           int mini=1e9;
           for(int i= 0; i< triangle.size() ; i++){
               mini = min(mini , f(triangle , dp , m-1 , i));
           }
           return mini;
        }
    
        int f(vector<vector<int>>& triangle , vector<vector<int>>& dp , int m , int n){
              if(m==0 && n==0) return dp[0][0]= triangle[0][0];
              if(m<0 || n<0 || n>m ) return 1e9;
    
              if(dp[m][n] != -1) return dp[m][n];
    
              int left = triangle[m][n] + f(triangle , dp , m-1 , n-1);
              int up=  triangle[m][n] + f(triangle , dp ,  m-1 , n);
    
              return dp[m][n]= min(left , up);
        }
    };
    