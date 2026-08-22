#include <bits/stdc++.h>

using namespace std;

const int M = 1e9 + 7;
// Time Complexity: O(2^N) and Space Complexity: O(N)

// int rec(int n)
// {

//   if (n == 0)
//     return 1;

//   if (n < 0)
//     return 0;

//   return rec(n - 1) + rec(n - 2) + rec(n - 3) + rec(n - 4) + rec(n - 5) + rec(n - 6);
// }

// optimized soln using dp.

// Time Complexity: O(6N) ~ O(N) and Space Complexity: O(N).
int optimized(vector<int> &dp, int n)
{

  dp[0] = 1;

  for (int i = 1; i <= n; i++)
  {
    for (int j = 1; j <= 6; j++)
    {
      if (i - j >= 0)
      {
        dp[i] = (dp[i] + dp[i - j]) % M;
      }
    }
  }
  return dp[n];
}
int main()
{

  int n;
  cin >> n;

  vector<int> dp(n + 1, 0);
  // cout << rec(n) << endl;

  cout << optimized(dp, n) << endl;

  return 0;
}