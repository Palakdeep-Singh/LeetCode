#include <bits/stdc++.h>

using namespace std;

// recursion.. O(2^N) and O(N)
int Jump(vector<int> &nums, int index)
{

  // base case kya hoga ??
  // agar koi ghar hi nhi bacha lootne ke liye..
  if (index < 0)
    return 0;

  // if robber loot in 1st house then he must left the next one due to security reasons.
  // so he will loot index-2 and if he decided not to loot the current house he will simply go to next one.
  return max(Jump(nums, index - 2) + nums[index], Jump(nums, index - 1));
}

// memoization in DP format. O(N) and O(2N)
int dp_memoization(vector<int> &dp, vector<int> &nums, int index)
{

  if (index < 0)
    return 0;

  if (dp[index] != -1)
    return dp[index];

  dp[index] = max(dp_memoization(dp, nums, index - 2) + nums[index], dp_memoization(dp, nums, index - 1));

  return dp[index];
}

// Time complexity: O(N) and Space complexity: O(N)

int tabulation(vector<int> &dp, vector<int> &nums)
{

  // start first ghar se krega lootna.
  dp[0] = nums[0];

  if (nums.size() == 1)
    return dp[0];

  // first loot hogi toh 1st ya second ghar se.
  dp[1] = max(nums[1], nums[0]);

  // now baaki ke ghar looto..
  for (int i = 2; i < nums.size(); i++)
  {
    dp[i] = max(dp[i - 2] + nums[i], dp[i - 1]);
  }

  return dp[nums.size() - 1];
}

// Time complexity: O(N) and space complexity: O(1)
int space_optimal(vector<int> &nums)
{

  // space optimality using 2 variables.
  int prev2 = nums[0];
  if (nums.size() == 1)
    return prev2;

  int prev1 = max(nums[1], nums[0]);

  for (int i = 2; i < nums.size(); i++)
  {
    int current = max(nums[i] + prev2, prev1);
    prev2 = prev1;
    prev1 = current;
  }

  return prev1;
}

int main()
{

  vector<int> nums = {-1, 34, 56, 23, -23, -55, 12};
  vector<int> dp(nums.size(), -1);

  cout << Jump(nums, nums.size() - 1) << endl;
  cout << dp_memoization(dp, nums, nums.size() - 1) << endl;

  cout << tabulation(dp, nums) << endl;
  cout << space_optimal(nums) << endl;

  return 0;
}