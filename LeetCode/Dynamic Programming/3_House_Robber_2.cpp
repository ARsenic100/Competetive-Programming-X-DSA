// https://leetcode.com/problems/house-robber-ii/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int rob(vector<int>& nums) {
            int n = nums.size();
            if(n == 0) return 0;
            if(n == 1) return nums[0];
             vector<int> nums1(nums.begin(), nums.end()-1);
             vector<int> nums2(nums.begin()+1, nums.end());
    
             return max(roblinear(nums1) , roblinear(nums2) );
    
        }
        int roblinear(vector<int>& nums) {
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
