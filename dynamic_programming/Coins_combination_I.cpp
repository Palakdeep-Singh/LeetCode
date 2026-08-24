#include <iostream>
#include <vector>

using namespace std;

const int M = 1e9 + 7;

int coins_(int n, vector<int> &coins, int target)
{

  // mujhe target = 0 banane ke liye kitne coins lgenge -> 0.
  if (target == 0)
  {
    return 1;
  }

  // agar target banana possible hi nhi h toh just result Infinity because hum minimum coins nikaal rhe h so min fun() isko choose hi nhi krega.

  if (target < 0)
    return 0;

  int total = 0;

  // loop ki agar me target pe pahunch geya toh kaise aya hu ? target me corresponding coin add krke bas waise hi me agar target se backward approach use kru and previous wala dekhu toh woh target-current_coin j add krke hi target bna hoga.

  for (int j = 0; j < n; j++)
  {
    int curr = coins[j];

    // min lelo agar path exists krta h and min use kro ki coins km use ho target banane me.
    total += coins_(n, coins, target - curr) % M;
  }

  // last me total minimum coins used return krdo.
  return total;
}

// Optimize code
int optimized(vector<int> &dp, vector<int> &coins, int target)
{

  if (target == 0)
    return 1;

  if (target < 0)
    return 0;

  if (dp[target] != -1)
    return dp[target];

  int coin_val = 0;

  for (int i = 0; i < coins.size(); i++)
  {
    coin_val = (coin_val + optimized(dp, coins, target - coins[i])) % M;
  }

  dp[target] = coin_val;

  return dp[target];
}

long long tabulation(vector<long long> &dp, vector<int> &coins, int target)
{

  dp[0] = 1;

  for (int i = 1; i <= target; i++)
  {
    for (int j = 0; j < coins.size(); j++)
    {

      if (i >= coins[j])
      {
        dp[i] = (dp[i] + dp[i - coins[j]]) % M;
      }
    }
  }

  return dp[target];
}

int main()
{

  int n;
  cin >> n;

  int target;
  cin >> target;

  vector<int> coins(n, 0);
  vector<long long> dp(target + 1, 0);

  for (int i = 0; i < n; i++)
    cin >> coins[i];

  // cout << coins_(n, coins, target) << endl;

  cout << tabulation(dp, coins, target) << endl;
  return 0;
}