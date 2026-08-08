#include <iostream>
#include <vector>

using namespace std;

int upper_bound(vector<int> &nums, int target)
{

  int n = nums.size();
  int l = 0, h = n - 1;
  int ans = n;
  while (l <= h)
  {

    int mid = (l + h) / 2;

    if (nums[mid] <= target)
    {
      ans = mid;
      l = mid + 1;
    }
    else
    {
      h = mid - 1;
    }
  }

  return ans;
}

int main()
{

  vector<int> nums = {2, 3, 6, 7, 8, 8, 11, 11, 11, 12};

  int target = 9;

  cout << upper_bound(nums, target) << endl;

  return 0;
}