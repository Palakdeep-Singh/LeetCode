#include <bits/stdc++.h>

using namespace std;

int singleNonDuplicate(vector<int> &nums)
{
  int n = nums.size();

  // if size is 1 means non duplicate element is already there.
  // else check at start and end index of array.
  if (n == 1)
    return nums[0];

  if (nums[0] != nums[1])
    return nums[0];

  if (nums[n - 1] != nums[n - 2])
    return nums[n - 1];

  // we already checked the first and last indexes so start searching from 2 to n-2.
  int low = 1, high = n - 2;

  while (low <= high)
  {

    int mid = low + (high - low) / 2;

    if (nums[mid - 1] != nums[mid] && nums[mid] != nums[mid + 1])
    {
      return nums[mid]; // return the element if it is found.
    }

    // observe the pattern..
    // left side of non duplicate comes in order of even odd and the right side of non duplicate is odd even.
    // se just make sure if you got even odd and both values equal means the non duplicate element is on right side move low to mid+1.

    // else it is in left side move high to mid-1.

    if (((mid - 1) % 2 == 0 && (nums[mid - 1] == nums[mid]) || (mid % 2 == 0 && (nums[mid] == nums[mid + 1]))))
    {
      low = mid + 1;
    }
    else
    {
      high = mid - 1;
    }
  }

  return -1;
}

int main()
{

  vector<int> nums = {1, 1, 2, 3, 3, 4, 4, 8, 8};

  cout << singleNonDuplicate(nums) << endl;
  return 0;
}