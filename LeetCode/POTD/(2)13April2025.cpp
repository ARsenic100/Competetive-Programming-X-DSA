// Count Good Numbers
// https://leetcode.com/problems/count-good-numbers/description/?envType=daily-question&envId=2025-04-13

#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int modExp(long long base, long long exp, int mod) {
            long long result = 1;
            base = base % mod; 
    
            while (exp > 0) {
                if (exp % 2 == 1) {
                    result = (result * base) % mod;
                }
                base = (base * base) % mod;
                exp /= 2;
            }
            return result;
        }
    
        int countGoodNumbers(long long n) {
            int Mod = 1e9 + 7;
            
            long long first = modExp(5, (n + 1) / 2, Mod);
            long long second = modExp(4, n / 2, Mod);
    
            return (first * second) % Mod;
        }
    };
    