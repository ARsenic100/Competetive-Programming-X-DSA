//Count Symmetric Integers
// https://leetcode.com/problems/count-symmetric-integers/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int countSymmetricIntegers(int low, int high) {
            int res=0;
            
            for(int i=low; i<=high; i++){
               int num=i;
               string s= to_string(num);
               int n= s.size();
               if(n%2!=0) continue;
               int sum1=0;
               int sum2=0;
               for(int k=0; k<n/2; k++){
                     sum1+= num%10;
                     num= num/10;
               }
               for(int k=0; k<n/2; k++){
                     sum2+= num%10;
                     num= num/10;
               }
               if(sum1==sum2) res++;
               
            }
            return res;
        }
    };