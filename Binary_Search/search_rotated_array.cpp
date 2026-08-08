#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int bs(vector<int> &nums, int target)
{

  int l = 0, h = nums.size() - 1;

  while (l <= h)
  {
    int mid = l + (h - l) / 2;

    if (nums[mid] == target)
    {
      return 1;
    }

    // in case of duplicates we will just return true,false (1,0) if element is present or not.
    // we cannot return first occurence in log(n) for duplicates. for that we have to perform linear search

    if (nums[l] == nums[mid] && nums[mid] == nums[h])
    {
      l++;
      h--;
      continue;
    }
    // now check wether the first half is sorted or second half.
    if (nums[l] <= nums[mid]) // if first is sorted. nums[low] <= nums[mid].
    {
      // check wether the target lies in that sorted half or not
      if (nums[l] <= target && target <= nums[mid])
      {
        h = mid - 1;
      }
      else
      {
        l = mid + 1;
      }
    }
    else
    {

      // else check the second half if that is sorted or not and find target whether it is in second half or first half.
      if (nums[mid] <= target && target <= nums[h])
      {
        l = mid + 1;
      }
      else
      {
        h = mid - 1;
      }
    }
  }

  return -1; // in case of no element is found.
}

int main()
{

  vector<int> nums = {3, 1, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3};

  cout << bs(nums, 1) << endl;
  return 0;
}