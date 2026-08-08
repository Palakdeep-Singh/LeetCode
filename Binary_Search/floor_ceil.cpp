#include <iostream>
#include <vector>

using namespace std;

int ceil(vector<int> &nums, int x)
{

  int l = 0, h = nums.size() - 1;
  int ans = -1;

  while (l <= h)
  {

    int mid = l + (h - l) / 2;

    if (nums[mid] >= x)
    {
      h = mid - 1;
      ans = nums[mid];
    }
    else
    {
      l = mid + 1;
    }
  }

  return ans;
}

int floor(vector<int> &nums, int x)
{

  int l = 0, h = nums.size() - 1;
  int ans = -1;

  while (l <= h)
  {

    int mid = l + (h - l) / 2;

    if (nums[mid] <= x)
    {
      ans = nums[mid];
      l = mid + 1;
    }
    else
    {
      h = mid - 1;
    }
  }

  return ans;
}

vector<int> getFloorAndCeil(vector<int> nums, int x)
{

  return {floor(nums, x), ceil(nums, x)};
}

int main()
{

  vector<int> arr = {2, 4, 6, 8, 10, 12, 14};

  int target = 1;

  cout << getFloorAndCeil(arr, target)[0] << " " << getFloorAndCeil(arr, target)[1] << endl;
  return 0;
}