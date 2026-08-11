#include <bits/stdc++.h>

using namespace std;

int binarySearch(vector<int> arr, int n)
{

  int low = 0, high = n - 1;
  while (low < high)
  {
    int mid = (low) + (high - low) / 2;

    if (arr[mid] < arr[mid + 1])
    {
      low = mid + 1;
    }
    else
    {
      high = mid;
    }
  }

  return high;
}

int main()
{

  vector<int> arr = {1, 2, 1, 1, 5, 4, 5, 5, 3, 5, 6, 4};
  cout << binarySearch(arr, arr.size()) << endl;

  return 0;
}