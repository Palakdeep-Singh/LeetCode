#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

#define vii vector<vector<int>>
#define vi vector<int>
#define rep(i, m) for (int i = 0; i < m; i++)
#define sort(a) sort(a.begin(), a.end())

#define M 1e9

using namespace std;

// Time Complexity: O(N), Space Complexity: O(m)
int subArrays(vector<int> &nums, int k)
{

  unordered_map<int, int> freq;

  int l = 0, r = 0;
  int maxSum = 0;

  while (r < nums.size())
  {

    freq[nums[r]]++;

    while (freq.size() > k)
    {
      freq[nums[l]]--;
      if (freq[nums[l]] == 0)
        freq.erase(nums[l]);
      l++;
    }

    maxSum += r - l + 1;
    r++;
  }

  return maxSum;
}

int subarraysWithKDistinct(vector<int> &nums, int k)
{

  return subArrays(nums, k) - subArrays(nums, k - 1);
}

int main()
{

  int n;
  cin >> n;

  vi nums(n);

  rep(i, n) cin >> nums[i];

  int k;
  cin >> k;

  cout << subarraysWithKDistinct(nums, k) << endl;
  return 0;
}