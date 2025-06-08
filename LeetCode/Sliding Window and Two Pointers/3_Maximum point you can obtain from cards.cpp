//Maximum point you can obtain from cards
//https://leetcode.com/problems/maximum-points-you-can-obtain-from-cards/description/

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
      int l= 0;
      int r= cardPoints.size() -1;
      int n = cardPoints.size();

      int sum=0;

      for(int i=0; i<k ; i++){
        sum+= cardPoints[i];
      }
      int maxi = sum;
      for(int i=1; i<=k ; i++){
        maxi= max(maxi , sum + cardPoints[n-i] - cardPoints[k-i]);
        sum = sum + cardPoints[n-i] - cardPoints[k-i];
      }
      return maxi;
    }
};