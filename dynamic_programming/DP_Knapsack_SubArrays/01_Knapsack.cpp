#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>

#define vii vector<vector<int>>
#define vi vector<int>
#define rep(i, m) for (int i = 0; i < m; i++)
#define sort(a) sort(a.begin(), a.end())

#define M 1e9

using namespace std;

// Time Complexity: O(2^n), Space Complexity: O(n)
int knapsack(vi &weights, vi &val, int n, int capacity)
{

  if (capacity <= 0 || n == 0)
    return 0;

  if (weights[n - 1] <= capacity)
  {

    // two choices.. take or not take.
    int take = val[n - 1] + knapsack(weights, val, n - 1, capacity - weights[n - 1]);
    int not_take = knapsack(weights, val, n - 1, capacity);

    return max(take, not_take);
  }

  return knapsack(weights, val, n - 1, capacity);
}

// Time Complexity: O(n*m), Space Complexity: O(n*m + n)
int knapsack_memoization(vii &dp, vi &wt, vi &val, int capacity, int n)
{

  if (n == 0 || capacity <= 0)
  {
    return 0;
  }

  if (dp[n][capacity] != -1)
    return dp[n][capacity];

  if (wt[n - 1] <= capacity)
  {
    int take = val[n - 1] + knapsack_memoization(dp, wt, val, capacity - wt[n - 1], n - 1);
    int not_take = knapsack_memoization(dp, wt, val, capacity, n - 1);

    return dp[n][capacity] = max(take, not_take);
  }

  else
    return dp[n][capacity] = knapsack_memoization(dp, wt, val, capacity, n - 1);
}

// Tabulation,
int tabulation(vi &weights, vi &val, int w)
{

  int n = weights.size();

  vii t(n + 1, vi(w + 1, 0));

  for (int i = 1; i < n + 1; i++)
  {
    for (int j = 1; j < w + 1; j++)
    {

      if (weights[i - 1] <= j)
      {
        t[i][j] = max(val[i - 1] + t[i - 1][j - weights[i - 1]], t[i - 1][j]);
      }
      else
      {
        t[i][j] = t[i - 1][j];
      }
    }
  }

  return t[n][w];
}

int main()
{

  int n;
  cin >> n;

  vi weight(n, 0);

  rep(i, n) cin >> weight[i];

  vi valarray(n, 0);

  rep(i, n) cin >> valarray[i];

  int capacity;
  cin >> capacity;

  vii dp(n + 1, vi(capacity + 1, -1));

  auto start1 = chrono::high_resolution_clock::now();
  for (int i = 0; i < 10000; i++)
    int ans1 = knapsack(weight, valarray, n, capacity);
  auto stop1 = chrono::high_resolution_clock::now();

  auto start2 = chrono::high_resolution_clock::now();
  for (int i = 0; i < 10000; i++)
    int ans2 = knapsack_memoization(dp, weight, valarray, capacity, n);
  auto stop2 = chrono::high_resolution_clock::now();

  auto start3 = chrono::high_resolution_clock::now();
  for (int i = 0; i < 10000; i++)
    int ans3 = tabulation(weight, valarray, capacity);
  auto stop3 = chrono::high_resolution_clock::now();

  cout << "Recursive: "
       << chrono::duration_cast<chrono::microseconds>(stop1 - start1).count()
       << " us\n";

  cout << "Memoization: "
       << chrono::duration_cast<chrono::microseconds>(stop2 - start2).count()
       << " us\n";

  cout << "Tabulation: "
       << chrono::duration_cast<chrono::microseconds>(stop3 - start3).count()
       << " us\n";

  return 0;
}