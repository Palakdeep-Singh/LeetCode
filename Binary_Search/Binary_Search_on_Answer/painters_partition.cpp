#include <bits/stdc++.h>

using namespace std;

// problem states that minimize the largest sum of subarray where k non-zero subarray's can be made by splitting the array.

long long condition(vector<int> &a, int mid)
{

  long long total = 0;
  int count = 1;
  for (int i = 0; i < a.size(); i++)
  {
    total += a[i];

    if (total > mid)
    {
      total = a[i];
      count++;
    }
  }

  return count;
}

long long binary_search(vector<int> &arr, int k)
{

  if (k > arr.size())
    return -1;

  long long low = *max_element(arr.begin(), arr.end());
  long long high = accumulate(arr.begin(), arr.end(), 0);

  while (low <= high)
  {

    long long mid = low + (high - low) / 2;

    if (condition(arr, mid) <= k)
    {
      high = mid - 1;
    }
    else
    {
      low = mid + 1;
    }
  }

  return low;
}

int main()
{

  vector<int> arr = {1, 2, 3, 4, 5};
  int k = 3;

  cout << binary_search(arr, k) << endl;

  return 0;
}