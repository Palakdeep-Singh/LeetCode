#include <bits/stdc++.h>

using namespace std;

// main function is of checking if pages can be distributed to all students such that all student have atleast one book.
int pages(vector<int> &arr, int m, int maxPagesAllowed)
{

  int students = 1;
  int page = 0;

  for (int i = 0; i < arr.size(); i++)
  {

    page += arr[i];
    if (page > maxPagesAllowed)
    {
      students++;
      page = arr[i];
    }
  }

  return students;
}

// binary search for pages if we can allocate pages to all students .
int binary_search(vector<int> &nums, int m)
{

  int high = accumulate(nums.begin(), nums.end(), 0);
  int low = *max_element(nums.begin(), nums.end());

  if (nums.size() < m)
    return -1;
  if (m == 1)
    return high;

  while (low <= high)
  {

    int mid = low + (high - low) / 2;

    if (pages(nums, m, mid) > m)
    {
      low = mid + 1;
    }
    else
    {
      high = mid - 1;
    }
  }

  return low;
}

// brute force me kya h students nikaal lo and linear search lgao.
int brute(vector<int> &nums, int m)
{

  int h = accumulate(nums.begin(), nums.end(), 0);
  int l = *max_element(nums.begin(), nums.end());

  for (int i = l; i <= h; i++)
  {

    int studentCount = pages(nums, m, i);

    if (studentCount == m)
      return i;
  }

  return -1;
}

int main()
{

  vector<int> pages = {25, 46, 28, 49, 24};

  cout << binary_search(pages, 4) << endl;
  cout << brute(pages, 4) << endl;
  return 0;
}