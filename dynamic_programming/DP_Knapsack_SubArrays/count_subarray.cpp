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
public:
  int perfectSum(vector<int> &arr, int K)
  {

    vector<vector<int>> dp(arr.size() + 1, vector<int>(K + 1, 0));

    dp[0][0] = 1;

    for (int i = 1; i < arr.size() + 1; i++)
    {
      for (int j = 0; j < K + 1; j++)
      {

        if (arr[i - 1] <= j)
        {
          dp[i][j] = dp[i - 1][j - arr[i - 1]] + dp[i - 1][j];
        }
        else
        {
          dp[i][j] = dp[i - 1][j];
        }
      }
    }

    return dp[arr.size()][K];
  }
};

int main()
{

  Solution s;

  vi arr = {2, 3, 5, 16, 8, 10};
  int K = 10;

  cout << s.perfectSum(arr, K) << endl;
  return 0;
}