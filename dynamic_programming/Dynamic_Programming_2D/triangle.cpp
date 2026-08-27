#include <bits/stdc++.h>

#define vii vector<vector<int>>
#define vi vector<int>

using namespace std;

class Solution
{
private:
  // TLE.. O(2^(m)) Space Complexity: O(m)

  int rec(vector<vector<int>> &triangle, int i, int j)
  {
    int m = triangle.size();
    int n = triangle[i].size();

    if (i == m - 1)
      return triangle[i][j];

    int up = triangle[i][j] + rec(triangle, i + 1, j);
    int left = triangle[i][j] + rec(triangle, i + 1, j + 1);

    return min(up, left);
  }

  // TLE.. Time Complexity: O(m*m), Space Complexity: O(m*m + m)
  int memo(vector<vector<int>> &dp, vector<vector<int>> &tr, int i, int j)
  {

    int m = tr.size();
    if (i == m - 1)
    {
      return tr[i][j];
    }

    if (dp[i][j] != -1)
      return dp[i][j];

    int down = tr[i][j] + memo(dp, tr, i + 1, j);
    int diag = tr[i][j] + memo(dp, tr, i + 1, j + 1);

    return dp[i][j] = min(down, diag);
  }

  // Time Complexity: O(m*m) Space Complexity: O(m*m)
  int tabulation(vector<vector<int>> &dp, vector<vector<int>> &tr)
  {

    int m = tr.size();

    dp[0][0] = tr[0][0];

    for (int i = 1; i < m; i++)
    {
      for (int j = 0; j < i + 1; j++)
      {

        int down = INT_MAX, diag = INT_MAX;

        if (j <= i - 1)
        {
          down = dp[i - 1][j];
        }

        if (j > 0)
        {
          diag = dp[i - 1][j - 1];
        }
        dp[i][j] = tr[i][j] + min(down, diag);
      }
    }
    return *min_element(dp[m - 1].begin(), dp[m - 1].end() - 1);
  }

public:
  int minimumTotal(vector<vector<int>> &triangle)
  {

    int m = triangle.size();

    vector<vector<int>> dp(m, vector<int>(m + 1, -1));
    // return rec(triangle,0,0);

    // return memo(dp, triangle, 0, 0);
    return tabulation(dp, triangle);
  }
};

int main()
{

  Solution res;

  int m;
  cin >> m;
  vii triangle(m);

  for (int i = 0; i < m; i++)
  {
    for (int j = 0; j < i + 1; j++)
    {
      int data;
      cin >> data;
      triangle[i].push_back(data);
    }
  }

  cout << res.minimumTotal(triangle);
  return 0;
}