//https://leetcode.com/problems/house-robber/

#include <bits/stdc++.h>
using namespace std;

// Memorization Approach
class Solution {
    public:
        
        int rob(vector<int>& nums) {
            int n= nums.size();
            vector<int> dp(n , -1);
            return f(nums , n-1 , dp);
        }
        int f(vector<int> & nums , int ind , vector<int> & dp){
            if(nums.size()==0) return 0;
            if(nums.size()==1) return nums[0];
            if(ind<0) return 0;
            if(dp[ind] != -1) return dp[ind];
    
            int pick = nums[ind] + f(nums , ind -2, dp);
            int nonpick = f(nums, ind-1 , dp);
    
            return dp[ind] =max(pick , nonpick);
            
        }
    };

// Tabulation Approach
class Solution {
    public:
        int rob(vector<int>& nums) {
            int n = nums.size();
            if(n == 0) return 0;
            if(n == 1) return nums[0];
            
            vector<int> dp(n, 0);
            dp[0] = nums[0];
            dp[1] = max(nums[0], nums[1]);
    
            for(int ind = 2; ind < n; ind++) {
                int pick = nums[ind] + dp[ind - 2];
                int nonpick = dp[ind - 1];
                dp[ind] = max(pick, nonpick);
            }
            return dp[n - 1];
        }
    };
// Space Optimized Approach
class Solution {
    public:
        int rob(vector<int>& nums) {
            int n = nums.size();
            if(n == 0) return 0;
            if(n == 1) return nums[0];

            int prev2 = nums[0];
            int prev1 = max(nums[0], nums[1]);

            for(int ind = 2; ind < n; ind++) {
                int pick = nums[ind] + prev2;
                int nonpick = prev1;
                int curr = max(pick, nonpick);
                prev2= prev1;
                prev1= curr;
                
            }
            return prev1;
        }
    };

