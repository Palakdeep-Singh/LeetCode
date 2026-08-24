#include <bits/stdc++.h>

using namespace std;
const int INF = 1e9;
int coins_(int n, vector<int> &coins, int target)
{

  // mujhe target = 0 banane ke liye kitne coins lgenge -> 0.
  if (target == 0)
  {
    return 0;
  }

  // agar target banana possible hi nhi h toh just result Infinity because hum minimum coins nikaal rhe h so min fun() isko choose hi nhi krega.

  if (target < 0)
    return INF;

  int total = INF;

  // loop ki agar me target pe pahunch geya toh kaise aya hu ? target me corresponding coin add krke bas waise hi me agar target se backward approach use kru and previous wala dekhu toh woh target-current_coin j add krke hi target bna hoga.

  for (int j = 0; j < n; j++)
  {
    int curr = coins[j];

    // min lelo agar path exists krta h and min use kro ki coins km use ho target banane me.
    total = min(coins_(n, coins, target - curr) + 1, total);
  }

  // last me total minimum coins used return krdo.
  return total;
}

// Optimize code
int optimized(vector<int> &dp, vector<int> &coins, int target)
{

  if (target == 0)
    return 0;

  if (target < 0)
    return INF;

  if (dp[target] != -1)
    return dp[target];

  int coin_val = INF;

  for (int i = 0; i < coins.size(); i++)
  {
    coin_val = min(optimized(dp, coins, target - coins[i]) + 1, coin_val);
  }

  dp[target] = coin_val;

  return dp[target];
}

int main()
{

  int n;
  cin >> n;

  int target;
  cin >> target;

  vector<int> coins(n, 0);
  vector<int> dp(target + 1, -1);

  for (int i = 0; i < n; i++)
    cin >> coins[i];

  // cout << coins_(n, coins, target) << endl;
  if (optimized(dp, coins, target) != INF)
    cout << optimized(dp, coins, target) << endl;
  else
    cout << -1 << endl;

  return 0;
}