#include <bits/stdc++.h>

using namespace std;

int binarySearch(vector<int> arr, int n, int target)
{

  int low = 0, high = n - 1;
  while (low <= high)
  {
    int mid = (low) + (high - low) / 2;

    if (arr[mid] < target)
    {
      low = mid + 1;
    }
    else if (arr[mid] > target)
    {
      high = mid - 1;
    }
    else
    {
      return mid;
    }
  }

  return -1;
}

int main()
{

  vector<int> arr{12, 43, 56, 67, 87, 98, 123, 456, 787};

  cout << binarySearch(arr, arr.size(), 456);
  return 0;
}