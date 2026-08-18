#include <bits/stdc++.h>

using namespace std;

// // recursive approach.. Time Complexity is O(2^n), Space Complexity: O(N). why 2^n ? because of recursion tree
// int fibonacii_number(int n)
// {

//   if (n == 1 || n == 0)
//   {
//     return n;
//   }

//   return fibonacii_number(n - 2) + fibonacii_number(n - 1);
// }

// memoization approach.. Time Complexity: O(N), Space Complexity: O(N) + O(N)
int fib_number(vector<int> &hash, int n)
{

  if (n == 1 || n == 0)
  {
    return n;
  }

  if (hash[n] != -1)
    return hash[n];

  else
    hash[n] = fib_number(hash, n - 1) + fib_number(hash, n - 2);

  return hash[n];
}

int main()
{

  int n;
  cin >> n;

  vector<int> dp(n + 1, -1);

  // cout << fibonacii_number(n) << endl;

  // cout << fib_number(dp, n) << endl;

  // Tabulation Approach.. Time Complexity: O(N) :: Space Complexity: O(N).
  dp[0] = 0, dp[1] = 1;

  for (int i = 2; i <= n; i++)
  {
    dp[i] = dp[i - 1] + dp[i - 2];
  }

  cout << dp[n] << endl;

    return 0;
}