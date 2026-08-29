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

  int space_optimized(vii &tr)
  {

    int m = tr.size();

    // last row ko store krke rkho.
    vi dp = tr[m - 1];

    for (int row = m - 2; row >= 0; row--)
    {
      for (int col = 0; col <= row; col++)
      {

        // jo previous row humne store rkhi thi usko update kro, row hmare pass h hi so row wala index ht jayega just.
        dp[col] = tr[row][col] + min(dp[col], dp[col + 1]);
      }
    }

    return dp[0];
  }

  int input_manipulation(vii &tr)
  {

    int m = tr.size();

    // agar me observe kru toh hum i se i+1 and col ya i se i+1 and col+1 jaa rhe h.
    // wahi chiz hum same hi triangle me krde bina dusra triangle bnaye.
    for (int row = 1; row < m; row++)
    {
      for (int col = 0; col <= row; col++)
      {

        // check if the indexes are in bound or not.
        // if an index is going <0 after doing col-1 than we will make it 0. -> max(col-1,0);
        // if it is going beyound length of previous, we keep it as last index of previous row so it remain in bound.

        int col2 = min(col, (int)tr[row - 1].size() - 1);
        int col1 = max(col - 1, 0);

        tr[row][col] = tr[row][col] + min(tr[row - 1][col1], tr[row - 1][col2]);
      }
    }

    return *min_element(tr[m - 1].begin(), tr[m - 1].end());
  }

public:
  int minimumTotal(vector<vector<int>> &triangle)
  {

    int m = triangle.size();

    vector<vector<int>> dp(m, vector<int>(m + 1, -1));
    // return rec(triangle,0,0);

    // return memo(dp, triangle, 0, 0);
    // return tabulation(dp, triangle);

    // return space_optimized(triangle);
    return input_manipulation(triangle);
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