#include <bits/stdc++.h>

using namespace std;

bool condition(vector<int> nums, int threshold, int divisor)
{

  int sum = 0;
  for (int i = 0; i < nums.size(); i++)
  {
    sum += ceil((double)nums[i] / (double)divisor);
  }

  return sum <= threshold;
}

int smallestDivisor(vector<int> &nums, int threshold)
{

  int l = 1;
  int h = *max_element(nums.begin(), nums.end());
  while (l < h)
  {
    int mid = l + (h - l) / 2;

    if (condition(nums, threshold, mid))
    {
      h = mid;
    }
    else
    {
      l = mid + 1;
    }
  }

  return l;
}

int main()
{

  vector<int> nums = {1, 2, 5, 9};
  cout << smallestDivisor(nums, 6) << endl;
  return 0;
}