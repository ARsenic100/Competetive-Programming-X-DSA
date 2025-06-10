//https://leetcode.com/problems/maximum-difference-between-even-and-odd-frequency-i/description/?envType=daily-question&envId=2025-06-10
//Maximum Difference Between Even and Odd Frequency I
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxDifference(string s) {
        int cnt=1;
        int maxodd =0;
        int mineven = 1e9;
        sort(s.begin(), s.end());
        int n = s.size();
        for(int i=1; i<= n; i++){
            if( s[i] != s[i-1] ){
                if(cnt%2==0){
                    mineven = min(mineven , cnt);
                }
                else{ 
                    maxodd = max(maxodd , cnt);
                }
                cnt=1;
            }
            else{
                cnt++;
            }
        }
        return maxodd - mineven ;
    }
};