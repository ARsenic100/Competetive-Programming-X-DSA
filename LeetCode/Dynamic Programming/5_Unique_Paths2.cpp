// https://leetcode.com/problems/unique-paths-ii/

#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
            int m = obstacleGrid.size();
            int n = obstacleGrid[0].size();
    
            if (obstacleGrid[0][0] == 1 || obstacleGrid[m - 1][n - 1] == 1) {
                return 0;
            }
    
            vector<vector<int>> dp(m, vector<int>(n, -1));
            return f(m - 1, n - 1, obstacleGrid, dp);
        }
    
        int f(int m, int n, vector<vector<int>>& obstacleGrid, vector<vector<int>>& dp) {
            // Out of bounds
            if (m < 0 || n < 0) return 0;
    
            // Obstacle
            if (obstacleGrid[m][n] == 1) return 0;
    
            // Starting point
            if (m == 0 && n == 0) return 1;
    
            if (dp[m][n] != -1) return dp[m][n];
    
            return dp[m][n] = f(m - 1, n, obstacleGrid, dp) + f(m, n - 1, obstacleGrid, dp);
        }
    };
    