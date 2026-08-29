#include <iostream>
#include <vector>
#include <algorithm>
#define vii vector<vector<int>>
#define vi vector<int>
#define rep(i, m) for (int i = 0; i < m; i++)
#define sort(a) sort(a.begin(), a.end())

#define M 1e9

using namespace std;

class Solution
{
private:
  int binary_search_(vector<vector<int>> &mat, int i)
  {

    int l = 0, h = mat[i].size() - 1;
    int ans = -1;
    while (l <= h)
    {

      int mid = l + (h - l) / 2;
      if (mat[i][mid] == 1)
      {
        h = mid - 1;
        ans = mid;
      }
      else
      {
        l = mid + 1;
      }
    }

    return ans;
  }

public:
  // Time Complexity: O(nlogm), Space Complexity: O(1)
  int rowWithMax1s(vector<vector<int>> &mat)
  {

    int max_val = -1;

    int n = mat.size();
    int m = mat[0].size();

    for (int i = 0; i < n; i++)
    {
      int val = binary_search_(mat, i);

      if (val != -1)
      {
        if (m - val - 1 > max_val)
        {
          max_val = max(max_val, i);
        }
      }
    }

    return max_val;
  }

  // Time Complexity: O(n+m), Space Complexity: O(1)
  int top_right_approach(vector<vector<int>> &mat)
  {
    // top-right corner approch
    int n = mat.size();
    int m = mat[0].size();

    int row = 0;
    int col = m - 1;
    int ans = -1;

    while (row < n && col >= 0)
    {
      if (mat[row][col] == 1)
      {
        ans = row;
        col--;
      }
      else
      {
        row++;
      }
    }
    return ans;
  }
};

int main()
{

  int n;
  cin >> n;

  vii mat(n, vi(n, 0));

  rep(i, n)
  {
    rep(j, n)
    {
      cin >> mat[i][j];
    }
  }

  Solution res;

  cout << res.rowWithMax1s(mat) << endl;
  cout << res.top_right_approach(mat) << endl;

  return 0;
}