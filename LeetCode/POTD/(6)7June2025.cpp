// Lexicographically Minimum String After Removing Stars
//https://leetcode.com/problems/lexicographically-minimum-string-after-removing-stars/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string clearStars(string s) {
        vector<char> v(s.begin(), s.end());
        deque<pair<char, int>> st; // Sorted deque

        for(int i = 0; i < s.size(); i++) {
            if(s[i] == '*') {
                if(!st.empty()) {
                    auto val_ind = st.front();
                    st.pop_front();
                    int ind = val_ind.second;
                    v[ind] = '0'; // Mark as removed
                }
            }
            else {
                // Create the pair to insert
                pair<char, int> p = {s[i], i};

                // Find insert position using lower_bound without lambda by defining a comparator beforehand
                auto comp = [](const pair<char,int>& a, const pair<char,int>& b) {
                    return a.first < b.first;
                };

                auto it = lower_bound(st.begin(), st.end(), p, comp);

                st.insert(it, p);
            }

        }

        string z = "";
        for(auto c : v){
            if(c != '*' && c != '0'){
                z += c;
            }
        }

        return z;
    }
};
