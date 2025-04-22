// Count and say
// https://leetcode.com/problems/count-and-say/description/?envType=daily-question&envId=2025-04-18

#include <bits/stdc++.h>
using namespace std;

class Solution {  
    public:  
        string countAndSay(int n) {  
            string s = "1";  
            
            for (int i = 1; i < n; i++) {  
                string v = "";  
                int cnt = 1;  
                
                for (int j = 1; j < s.size(); j++) {  
                    if (s[j] == s[j - 1]) {  
                        cnt += 1;  
                    } 
                    else {  
                        v += to_string(cnt) + s[j - 1];   
                        cnt = 1;  
                    }  
                }  
                v += to_string(cnt) + s[s.size() - 1];   
                s = v;   
            }  
            
            return s;   
        }  
    };  