#include <iostream>
#include <vector>
#include <algorithm>
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

  int n;
  cin >> n;

  vector<int> nums(n, 0);

  for (int i = 0; i < n; i++)
    cin >> nums[i];

  int target;
  cin >> target;

  int first = -1, last = -1;

  for (int i = 0; i < n; i++)
  {

    if (nums[i] == target)
    {
      if (first == -1)
      {
        first = i;
      }
      last = i;
    }
  }

  cout << first << " " << last << endl;

  cout << "Method 2: Binary Search ( only for ordered array )" << endl;

  int lb = *lower_bound(nums.begin(), nums.end(), target);
  int up = *upper_bound(nums.begin(), nums.end(), target);

  cout << lb << " " << up << endl;

  if (lb < 0 || nums[lb] != target)
  {
    cout << -1 << " " << -1 << endl;
  }
  else
  {
    cout << lb << " " << up - 1 << endl;
  }
  return 0;
}