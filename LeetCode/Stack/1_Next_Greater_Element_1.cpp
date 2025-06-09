//Next Greater Element I
//https://leetcode.com/problems/next-greater-element-i/
// Given two arrays nums1 and nums2, return an array of the same length as nums1 where each element is the next greater element of the corresponding element in nums1 from nums2.
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> mp;
        stack<int> st;

        for (int i = 0; i < nums2.size(); i++) {
            while (!st.empty() && st.top() < nums2[i]) {
                mp[st.top()] = nums2[i];
                st.pop();
            }
            st.push(nums2[i]);
        }

        while (!st.empty()) {
            mp[st.top()] = -1;
            st.pop();
        }

        for (int i = 0; i < nums1.size(); i++) {
            nums1[i] = mp[nums1[i]];
        }

        return nums1;
    }
};
