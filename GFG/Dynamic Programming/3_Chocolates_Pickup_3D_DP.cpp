//Chocolates Pickup
// https://www.geeksforgeeks.org/problems/chocolates-pickup/1

#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
      int solve(int n, int m, vector<vector<int>>& grid) {
          vector<vector<vector<int>>> dp(n, vector<vector<int>>(m , vector<int>(m, -1)));
          
          return f(n , m , grid , dp , 0 , 0 , m-1 );
  
      }
      int f(int n, int m, vector<vector<int>>& grid , vector<vector<vector<int>>> & dp , int x , int y1 , int y2){
          
          if(x>= n || y1>=m || y2>=m || x< 0 || y1<0 || y2<0) return 0;
          if(x==n-1){
              if(y1==y2) return grid[x][y1];
              return grid[x][y1] + grid[x][y2];
          }
          
          if(dp[x][y1][y2] != -1) return dp[x][y1][y2];
          
          int maxi = max( {
                      f(n , m , grid , dp , x+1 , y1-1 , y2-1) ,
                      f(n , m , grid , dp , x+1 , y1-1 , y2) ,
                      f(n , m , grid , dp , x+1 , y1-1 , y2+1) ,
                      f(n , m , grid , dp , x+1 , y1 , y2-1) ,
                      f(n , m , grid , dp , x+1 , y1 , y2) ,
                      f(n , m , grid , dp , x+1 , y1 , y2+1) ,
                      f(n , m , grid , dp , x+1 , y1+1 , y2-1) ,
                      f(n , m , grid , dp , x+1 , y1+1 , y2) ,
                      f(n , m , grid , dp , x+1 , y1+1 , y2+1)   
                      
                     } );
          
          if(y1== y2) maxi+= grid[x][y1];
          else maxi += grid[x][y1] + grid[x][y2];
          
          return dp[x][y1][y2]= maxi;
          
          
      }
  };