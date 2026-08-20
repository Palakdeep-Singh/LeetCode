#include <bits/stdc++.h>

using namespace std;

// Time Complexity: O(2*N) and  Space Complexity: O(N)
int climb_stairs(int n)
{

  if (n <= 1)
  {
    return 1;
  }

  // hypothesis and intution.
  return climb_stairs(n - 1) + climb_stairs(n - 2);
}

// using dp approach. Time Complexity: O(N) and Space Complexity: O(N).
int climb_stairs_method2(vector<int> &dp, int n)
{

  if (n <= 1)
  {
    return 1;
  }

  if (dp[n] != -1)
  {
    return dp[n];
  }

  dp[n] = climb_stairs_method2(dp, n - 1) + climb_stairs_method2(dp, n - 2);

  return dp[n];
}

int main()
{

  int n;
  cin >> n;

  cout << climb_stairs(n) << endl;

  vector<int> dp(n + 1, -1);

  cout << climb_stairs_method2(dp, n);
  return 0;
}