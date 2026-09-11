#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <climits>

#define vii vector<vector<int>>
#define vi vector<int>
#define rep(i, m) for (int i = 0; i < m; i++)
#define sort(a) sort(a.begin(), a.end())

#define M 1e9

using namespace std;

class Solution
{

public:
  int knapsack(vector<int> &arr, int target)
  {

    vector<vector<int>> dp(arr.size() + 1, vector<int>(target + 1, 0));

    for (int i = 1; i < arr.size() + 1; i++)
    {
      for (int j = 1; j < target + 1; j++)
      {

        if (arr[i - 1] <= j)
        {
          dp[i][j] = max(arr[i - 1] + dp[i - 1][j - arr[i - 1]], dp[i - 1][j]);
        }
        else
        {
          dp[i][j] = dp[i - 1][j];
        }
      }
    }

    return dp[arr.size()][target];
  }

  int minDifference(vector<int> &arr, int n)
  {

    int sum = accumulate(arr.begin(), arr.end(), 0);

    int minVal = INT_MAX;
    int sum2 = knapsack(arr, sum / 2);
    minVal = min(abs(2 * sum2 - sum), sum2);

    return minVal;
  }
};

int main()
{

  Solution s;

  vi arr = {3, 1, 6, 2, 2};

  cout << s.minDifference(arr, arr.size()) << endl;
  return 0;
}