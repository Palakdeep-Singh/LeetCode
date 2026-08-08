#include <bits/stdc++.h>

using namespace std;

int bs(vector<int> &nums)
{

  int l = 0, h = nums.size() - 1;

  int ans = INT_MAX;
  int index = -1;

  while (l <= h)
  {

    int mid = l + (h - l) / 2;

    if (nums[mid] == nums[l] && nums[mid] == nums[h])
    {
      if (ans > nums[l])
      {
        index = l;
        ans = nums[l];
      }
      l++;
      h--;

      continue;
    }

    if (nums[l] <= nums[mid])
    {
      if (ans > nums[l])
      {
        index = l;
        ans = nums[l];
      }
      l = mid + 1;
    }
    else
    {
      h = mid - 1;
      if (nums[mid] < ans)
      {
        index = mid;
        ans = nums[mid];
      }
    }
  }

  return index;
}

int main()
{

  vector<int> nums = {3, 3, 3, 3, 1, 2, 3};

  cout << bs(nums) << endl;

  return 0;
}