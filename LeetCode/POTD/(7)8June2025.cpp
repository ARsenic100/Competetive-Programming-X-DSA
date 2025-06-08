//Lexographical Numbers
//https://leetcode.com/problems/lexicographical-numbers/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<string> v;
        for(int i=1; i<=n ; i++){
            v.push_back(to_string(i));
        }
        sort(v.begin(), v.end());
        vector<int> vec;
        for(int i=0; i<n ; i++){
            vec.push_back(stoi(v[i]));
        }
        return vec;
    }
};