#include <iostream>
#include <vector>

using namespace std;

int lower_bound(vector<int> &nums, int target)
{

  int n = nums.size();

  int low = 0, high = n - 1;
  int ans = n;
  while (low <= high)
  {

    int mid = low + (high - low) / 2;

    if (nums[mid] < target)
    {
      low = mid + 1;
    }
    else if (nums[mid] >= target)
    {
      high = mid - 1;
      ans = mid;
    }
  }

  return ans;
}
int main()
{

  vector<int> nums = {1, 2, 3, 56, 56, 56, 78, 89, 90, 111, 122};

  int target = 5776;
  cout << lower_bound(nums, target) << endl;

  return 0;
}