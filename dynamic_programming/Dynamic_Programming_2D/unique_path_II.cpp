#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
  // Recursion Time Complexity: O(2^(m*n))
  // Space Complexity: O((m-1) + (n-1))

  int rec(vector<vector<int>> &ob, int i, int j)
  {

    if (i == 0 && j == 0 && ob[i][j] != 1)
      return 1;

    if (i < 0 || j < 0)
      return 0;

    if (ob[i][j] == 1)
      return 0;

    int up = rec(ob, i - 1, j);
    int left = rec(ob, i, j - 1);

    return up + left;
  }

  // Solve overlapping sub problems.
  // Time Complexity: O(m*n), Space Complexity: O(m*n + (m-1 + (n-1)))
  int memoization(vector<vector<int>> &dp, vector<vector<int>> &ob, int i, int j)
  {

    if (i == 0 && j == 0 && ob[i][j] != 1)
      return 1;
    else if (i == 0 && j == 0 && ob[i][j] == 1)
      return 0;

    if (i < 0 || j < 0)
      return 0;
    if (ob[i][j] == 1)
      return 0;

    if (dp[i][j] != -1)
      return dp[i][j];

    int up = memoization(dp, ob, i - 1, j);
    int left = memoization(dp, ob, i, j - 1);

    dp[i][j] = up + left;

    return dp[i][j];
  }

  // tabulation just 3 steps, derive base case
  // express states in for loop
  // copy recurence and write.

  // Time Complexity: O(m*n), Space Complexity: O(m*n)
  int tabulation(vector<vector<int>> &dp, vector<vector<int>> &obstacleGrid)
  {

    int m = obstacleGrid.size();
    int n = obstacleGrid[0].size();
    if (obstacleGrid[0][0] == 1 || obstacleGrid[m - 1][n - 1] == 1)
      return 0;

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
          {
            up = dp[i - 1][j];
            if (obstacleGrid[i - 1][j] == 1)
            {
              up = 0;
            }
          }
          if (j > 0)
          {
            left = dp[i][j - 1];
            if (obstacleGrid[i][j - 1] == 1)
            {
              left = 0;
            }
          }

          dp[i][j] = up + left;
        }
      }
    }

    return dp[m - 1][n - 1];
  }

  int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid)
  {

    int i = obstacleGrid.size();
    int j = obstacleGrid[0].size();
    vector<vector<int>> dp(i, vector<int>(j, 0));

    return tabulation(dp, obstacleGrid);
  }
};

int main()
{

  Solution obj;

  int m, n;
  cin >> m >> n;

  vector<vector<int>> grid(m, vector<int>(n, 0));

  for (int i = 0; i < m; i++)
  {
    for (int j = 0; j < n; j++)
    {
      cin >> grid[i][j];
    }
  }

  cout << obj.uniquePathsWithObstacles(grid) << endl;
  return 0;
}