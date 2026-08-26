#include <bits/stdc++.h>

#define vii vector<vector<int>>
#define vi vector<int>

#define vll vector<vector<long>>
#define vl vector<long>

#define ll long long

#define for(i, b) for (int i = 0; i < b; i++)

#define M 1e9 + 7

using namespace std;

// recursion. T.C: O(2^(m*n)), Space Complexity: O((m-1) + (n-1))
int rec(vii &grid, int i, int j)
{

  if (i == 0 && j == 0)
  {
    return grid[0][0];
  }
  else if (i < 0 || j < 0)
    return M;

  int up = grid[i][j] + rec(grid, i - 1, j);
  int left = grid[i][j] + rec(grid, i, j - 1);

  return min(up, left);
}

// memoization Time Complexity: O(m*n), Space Complexity: O(m*n + (m-1) + (n-1))
int memo(vii &dp, vii &gd, int i, int j)
{

  if (i == 0 && j == 0)
    return gd[i][j];

  if (i < 0 || j < 0)
    return M;

  if (dp[i][j] != -1)
    return dp[i][j];

  int up = gd[i][j] + memo(dp, gd, i - 1, j);
  int left = gd[i][j] + memo(dp, gd, i, j - 1);

  return dp[i][j] = min(up, left);
}

// tabulation. Time Complexity: O(m*n), Space Complexity: O(m*n).
int tabulation(vii &dp, vii &gd)
{

  int m = gd.size();
  int n = gd[0].size();
  for (i, m)
  {
    for (j, n)
    {

      if (i == 0 && j == 0)
      {
        dp[0][0] = gd[0][0];
      }
      else
      {
        int up = INT_MAX, left = INT_MAX;
        if (i > 0)
        {
          up = gd[i][j] + dp[i - 1][j];
        }
        if (j > 0)
        {
          left = gd[i][j] + dp[i][j - 1];
        }

        dp[i][j] = min(up, left);
      }
    }
  }

  return dp[m - 1][n - 1];
}

int main()
{

  int m, n;
  cin >> m >> n;

  vii grid(m, vi(n, 0));
  vii dp(m, vi(n, -1));

  for (i, m)
  {
    for (j, n)
    {
      cin >> grid[i][j];
    }
  }

  // cout << rec(grid, m - 1, n - 1) << endl;
  cout << memo(dp, grid, m - 1, n - 1) << endl;
  vii dp2(m, vi(n, 0));
  cout << tabulation(dp2, grid);
  return 0;
}