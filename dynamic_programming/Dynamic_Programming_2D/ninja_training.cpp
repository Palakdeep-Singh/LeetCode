#include <iostream>
#include <vector>

using namespace std;

// recursive approach in O(2^N) because T(N) = 2*T(N-1) + O(1). Space : O(N)
int rec(vector<vector<int>> &task, int days, int last)
{

  if (days == 0)
  {
    int max_ = 0;
    for (int i = 0; i < 3; i++)
    {
      if (i != last)
      {
        max_ = max(max_, task[days][i]);
      }
    }
    return max_;
  }

  int max_ = 0;

  for (int i = 0; i < 3; i++)
  {
    if (i != last)
    {
      max_ = max(max_, task[days][i] + rec(task, days - 1, i));
    }
  }

  return max_;
}

// memoization approach.. Time: state*transition -> N*4*3 , Space Complexity: O(N*4) + O(N) = O(5N)
int memoization(vector<vector<int>> &dp, vector<vector<int>> &task, int day, int last)
{

  if (day == 0)
  {
    int max_ = 0;

    for (int i = 0; i < 3; i++)
    {
      if (i != last)
      {
        max_ = max(max_, task[day][i]);
      }
    }

    return max_;
  }

  if (dp[day][last] != -1)
  {
    return dp[day][last];
  }

  int max_ = 0;
  for (int i = 0; i < 3; i++)
  {
    if (i != last)
    {
      max_ = max(max_, task[day][i] + memoization(dp, task, day - 1, i));
    }
  }

  dp[day][last] = max_;
  return dp[day][last];
}

// tabulation approach. Time Complexity: O(N), Space Comlexity: O(N)
int optimized(vector<vector<int>> &dp, vector<vector<int>> &task)
{

  dp[0][0] = max(task[0][1], task[0][2]);
  dp[0][1] = max(task[0][0], task[0][2]);
  dp[0][2] = max(task[0][0], task[0][1]);
  dp[0][3] = max(task[0][0], max(task[0][1], task[0][2]));

  for (int day = 1; day < task.size(); day++)
  {
    for (int last = 0; last < 4; last++)
    {
      int max_ = 0;
      for (int task_ = 0; task_ < 3; task_++)
      {
        if (task_ != last)
        {
          int points = dp[day - 1][task_] + task[day][task_];
          max_ = max(max_, points);
          dp[day][last] = max_;
        }
      }
    }
  }

  return dp[task.size() - 1][3];
}

int ninjaTraining(vector<vector<int>> &matrix)
{

  // return rec(matrix,matrix.size()-1,3);

  vector<vector<int>> dp(matrix.size(), vector<int>(4, 0));

  // return memoization(dp,matrix,matrix.size()-1,3);
  return optimized(dp, matrix);
}

int main()
{

  int n;
  cin >> n;

  vector<vector<int>> matrix(n, vector<int>(3, 0));

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < 3; j++)
    {
      cin >> matrix[i][j];
    }
  }

  cout << ninjaTraining(matrix) << endl;

  return 0;
}