#include <bits/stdc++.h>

using namespace std;

// int jump(vector <int> heights,int i,int k){

//     if(i == heights.size()-1) return 0;

//         int min_val = INT_MAX;

//     for(int j = i+1;j<=min(i+k,heihgts.size()-1);j++){
//         min_val = min(abs(heights[i]-heights[j]) + jump(heights,j,k),min_val);
//     }

//     return min_val;
// }

int jumpDP(vector<int> &dp, vector<int> &heights, int i, int k)
{

  if (i == heights.size() - 1)
    return 0;

  if (dp[i] != -1)
    return dp[i];

  int min_val = INT_MAX;

  for (int j = i + 1; j <= min(static_cast<int>(heights.size()) - 1, i + k); j++)
  {
    min_val = min(min_val, abs(heights[j] - heights[i]) + jumpDP(dp, heights, j, k));
  }

  dp[i] = min_val;
  return dp[i];
}

int frogJump(vector<int> &heights, int k)
{

  int n = heights.size();
  vector<int> dp(n, -1);

  dp[n - 1] = 0;
  // return jumpDP(DP,heights,0,k);
  for (int i = n - 2; i >= 0; i--)
  {
    int min_ = INT_MAX;
    for (int j = i + 1; j <= min(n - 1, i + k); j++)
    {
      min_ = min(min_, abs(heights[i] - heights[j]) + dp[j]);
    }
    dp[i] = min_;
  }

  return dp[0];
  // return jump(heights,0,k);
}

int main()
{

  vector<int> heights = {10, 5, 20, 0, 15};

  cout << frogJump(heights, 2) << endl;
  return 0;
}