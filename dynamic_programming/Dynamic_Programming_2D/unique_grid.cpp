#include <bits/stdc++.h>

using namespace std;

// Time Complexity: O(2^(M*N)),
// Space Complexity: O((m-1) + (n-1))

int recursion(int m, int n)
{

  if (m == 0 && n == 0)
    return 1;

  if (m < 0 || n < 0)
    return 0;

  // if i start from bottom right i will go to 0,0 as the destination so we have
  // one 2 moves, either go up or go left.
  int up = recursion(m - 1, n);
  int left = recursion(m, n - 1);

  // return all the possible paths.
  return up + left;
}

// Now we see there are overlapping subproblems hence we will use memoization.
// Time Complexity: O (m*n)
// Space Complexity: O(m*n + (m-1) + (n-1))
int memo(vector<vector<int>> &dp, int m, int n)
{

  if (m == 0 && n == 0)
    return 1;

  if (m < 0 || n < 0)
    return 0;

  if (dp[m][n] != -1)
    return dp[m][n];

  dp[m][n] = memo(dp, m - 1, n) + memo(dp, m, n - 1);

  return dp[m][n];
}

// tabulation
int tabu(int m, int n)
{

  vector<vector<int>> dp(m, vector<int>(n, 0));

  // only 2 valid moves up and left.
  // for i = 0 j can be 0,1,2,3,4,5...,n-1
  // for i = 1 j can be 0,1,2,3,4,5....,n-1
  for (int i = 0; i < m; i++)
  {
    for (int j = 0; j < n; j++)
    {
      if (i == 0 && j == 0)
      {
        dp[0][0] = 1;
      }
      else
      {
        int up = 0, left = 0;
        if (i > 0)
          up = dp[i - 1][j];

        if (j > 0)
        {
          left = dp[i][j - 1];
        }

        dp[i][j] = up + left;
      }
    }
  }

  return dp[m - 1][n - 1];
}

int main()
{

  int m = 3, n = 7;

  // passing the last index, assuming indexing from 0 to m-1 and n-1.
  // cout << recursion(2, 6) << endl;

  vector<vector<int>> dp(m, vector<int>(n, -1));
  cout << memo(dp, m - 1, n - 1) << endl;

  cout << tabu(m, n);
  return 0;
}