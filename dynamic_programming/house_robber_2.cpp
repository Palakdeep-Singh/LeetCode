#include <bits/stdc++.h>

using namespace std;

// Time Complexity: O(N), Space Complexity: O(N) -> Dp + O(N) -> recursion stack.
long long int rob(vector<int> &dp, vector<int> &H, int l, int i)
{

  // if no house is left then we cannot loot that's why return 0.
  if (i < l)
  {
    return 0;
  }

  // if we already know the value then just return the value no need to repeat.
  // reduces time complexity.
  if (dp[i] != -1)
    return dp[i];

  dp[i] = max(rob(dp, H, l, i - 2) + H[i], rob(dp, H, l, i - 1));

  return dp[i];
}

// tabulation to optimize space. O(n), O(n)
int tabulation(vector<int> &dp, vector<int> &H, int l, int r)
{

  dp[l] = H[l];

  for (int i = l + 1; i <= r; i++)
  {
    int not_take = dp[i - 1];

    int take = -1;
    take = H[i];

    if (i > l + 1)
      take += dp[i - 2];

    dp[i] = max(not_take, take);
  }

  return dp[r];
}

// further optimization can be done by replacing dp[i-2] with prev2 and dp[i-1] with prev and a current which store max
// then just make prev2 = prev and prev = current.
// O(n), O(1)

int main()
{

  vector<int> H = {1, 2, 3, 4, 5, 5, 7, 54, 10, 2, 0};

  vector<int> dp1(H.size(), -1);
  vector<int> dp2(H.size(), -1);

  // case1 when 1st house is not robbed .
  int case1 = rob(dp1, H, 0, H.size() - 2);

  // case2 when 1st
  int case2 = rob(dp2, H, 1, H.size() - 1);

  cout << max(case1, case2) << endl;

  fill(dp1.begin(), dp1.end(), 0);
  fill(dp2.begin(), dp2.end(), 0);

  // similarly do for tabulation check for both including 1st house or including last house only.
  cout << max(tabulation(dp1, H, 0, H.size() - 2), tabulation(dp2, H, 1, H.size() - 1)) << endl;
  return 0;
}