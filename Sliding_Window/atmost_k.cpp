#include <bits/stdc++.h>

using namespace std;

int longestOnes(vector<int> &nums, int k)
{

  int l = 0, zero = 0;
  int maxlength = 0;
  for (int r = 0; r < nums.size(); r++)
  {

    if (nums[r] == 0)
    {
      zero++;
    }

    while (zero > k)
    {
      if (nums[l] == 0)
      {
        zero--;
      }
      l++;
    }
    maxlength = max(maxlength, r - l + 1);
  }

  return maxlength;
}

int main()
{

  vector<int> nums = {0, 0, 1, 1, 0, 0, 1, 1, 1, 0, 1, 1, 0, 0, 0, 1, 1, 1, 1};
  vector<int> case2 = {1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 0};

  int k = 3;
  cout << longestOnes(nums, k);

  return 0;
}