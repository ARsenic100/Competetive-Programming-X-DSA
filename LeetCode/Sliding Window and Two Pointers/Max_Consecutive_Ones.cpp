//https://leetcode.com/problems/max-consecutive-ones-iii/
//Max Consecutive Ones III

#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int longestOnes(vector<int>& nums, int k) {
            //Sliding Window
            int l = 0, r = 0;
            int maxLen = 0, zeros = 0;
    
            while (r < nums.size()) {
                if (nums[r] == 0) zeros++;
    
                while (zeros > k) {
                    if (nums[l] == 0) zeros--;
                    l++;
                }
    
                maxLen = max(maxLen, r - l + 1);
                r++;
            }
    
            return maxLen;
        }
    };
    