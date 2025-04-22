// https://leetcode.com/problems/unique-paths/

#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int uniquePaths(int m, int n) {
            vector<vector<int>> dp(m, vector<int>(n, -1));
            return f(m - 1, n - 1, dp);
        }
    
        int f(int m, int n, vector<vector<int>>& dp) {
            // Base case: If we are at the starting cell, there is one unique path
            if (m == 0 || n == 0) {
                return 1;
            }
            
            // If already computed, return the cached value
            if (dp[m][n] != -1) {
                return dp[m][n];
            }
            // Compute the value and store it in dp
            dp[m][n] = f(m - 1, n, dp) + f(m, n - 1, dp);
            return dp[m][n];
        }
    };
    