#include <bits/stdc++.h>

using namespace std;

// Time complexity is O(2^N), Space Complexity is O(N).

// frog will reach from initial to last in minimum distance but
// for recursion we can say it goes from last to initial.
int frog_jump(vector<int> &heights, int index)
{

  // base condition : if frog reaches intial state: then no distance left it is already at the required state so return 0.
  if (index == 0)
    return 0;

  // suppose frog reached some index with minimum jump then the jump required is:
  int one_step = frog_jump(heights, index - 1) + abs(heights[index] - heights[index - 1]);

  // now if frog reached some index via 2 jumps and we consider that it reached in minimum distance then the
  // distance required between it and its next is.. but but condition is frog must take 2 jumps.
  int two_steps = INT_MAX;
  if (index > 1)
    two_steps = frog_jump(heights, index - 2) + abs(heights[index] - heights[index - 2]);

  // now whats the condition that frog reached in minimum steps is :
  return min(one_step, two_steps);
}

// Time Complexity: O(N), Space Complexity: O(N+N). -> O(2N)
// Using dp approach..
int frog_jump2(vector<int> dp, vector<int> &heights, int index)
{

  // base condition : if frog return to 0 means no ditance is need to cover return 0.
  if (index == 0)
    return 0;

  // now if we already have distance stored for some jump from index i to j then directly return it.
  if (dp[index] != -1)
    return dp[index];

  // else we will compute the min distance for jump from i to j.
  int one_step_jump = frog_jump2(dp, heights, index - 1) + abs(heights[index] - heights[index - 1]);

  int two_step_jump = INT_MAX;
  if (index > 1)
    two_step_jump = frog_jump2(dp, heights, index - 2) + abs(heights[index] - heights[index - 2]);

  // store result in dp so that we can use in future if required. save time.
  dp[index] = min(two_step_jump, one_step_jump);

  return dp[index];
}

// Time Complexity: O(N), Space Complexity: O(N).
// Use the tabulation method for more optimization.
int frog_jump3(vector<int> &dp, vector<int> &heights)
{

  int two_step = INT_MAX;
  dp[0] = 0;

  // in tabulation we use iterative method means using loops.
  for (int i = 1; i < heights.size(); i++)
  {

    // conditions remain similar to recursion.
    int one_step = dp[i - 1] + abs(heights[i] - heights[i - 1]);

    if (i > 1)
      two_step = dp[i - 2] + abs(heights[i] - heights[i - 2]);

    dp[i] = min(one_step, two_step);
  }

  return dp[heights.size() - 1];
}

int main()
{

  vector<int> heights = {7, 5, 1, 2, 6};
  cout << frog_jump(heights, heights.size() - 1) << endl;

  vector<int> dp(heights.size(), -1);

  cout << frog_jump2(dp, heights, heights.size() - 1) << endl;

  cout << frog_jump3(dp, heights) << endl;

  return 0;
}