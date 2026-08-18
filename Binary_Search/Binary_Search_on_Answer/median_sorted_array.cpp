#include <bits/stdc++.h>

using namespace std;

double median_of_array(vector<int> &nums1, vector<int> &nums2)
{

  int n1 = nums1.size();
  int m = nums2.size();

  int n = (n1 + m);
  int i = 0, j = 0, index = 0;
  int index1 = n / 2;
  int index2 = index1 - 1;
  int ind1ele = -1, ind2ele = -1;

  while (i < n1 && j < m)
  {
    if (nums1[i] < nums2[j])
    {
      if (index == index1)
      {
        ind1ele = nums1[i];
      }
      if (index == index2)
      {
        ind2ele = nums1[i];
      }
      index++;
      i++;
    }
    else
    {
      if (index == index1)
      {
        ind1ele = nums2[j];
      }
      if (index == index2)
      {
        ind2ele = nums2[j];
      }
      index++;
      j++;
    }
  }

  while (i < n1)
  {
    if (index == index1)
    {
      ind1ele = nums1[i];
    }
    if (index == index2)
    {
      ind2ele = nums1[i];
    }
    i++;
    index++;
  }

  while (j < m)
  {
    if (index == index1)
    {
      ind1ele = nums2[j];
    }
    if (index == index2)
    {
      ind2ele = nums2[j];
    }
    index++;
    j++;
  }

  if (n % 2 == 0)
  {
    return (ind1ele + ind2ele) / 2.0;
  }

  return ind1ele;
}

// in log(n+m) time complexity:
double median(vector<int> &num1, vector<int> &num2)
{

  int n1 = num1.size();
  int n2 = num2.size();
  int n = n1 + n2;

  // we will do binary search on smaller array,
  if (n1 > n2)
    return median(num2, num1);

  int low = 0, high = n1;

  // no. of elements in left half.
  int left_half = (n1 + n2 + 1) / 2;

  while (low <= high)
  {

    // get the no. of elements from first array.
    int mid1 = low + (high - low) / 2;

    // no. of elements from array 2.
    int mid2 = left_half - mid1;

    int l1 = INT_MIN, l2 = INT_MIN;

    int r1 = INT_MAX, r2 = INT_MAX;

    // now initialize l1,l2 and r1,r2
    if (mid1 < n1)
    {
      r1 = num1[mid1];
    }

    if (mid2 < n2)
    {
      r2 = num2[mid2];
    }

    if (mid1 - 1 >= 0)
      l1 = num1[mid1 - 1];
    if (mid2 - 1 >= 0)
      l2 = num2[mid2 - 1];

    if (l1 <= r2 && l2 <= r1)
    {
      if (n % 2 == 0)
      {
        return (max(l1, l2) + min(r1, r2)) / 2.0;
      }
      else
      {
        return max(l1, l2);
      }
    }
    else if (l1 > r2)
    {
      high = mid1 - 1;
    }
    else
    {
      low = mid1 + 1;
    }
  }

  return -1;
}

int main()
{

  vector<int> nums1 = {1, 3, 9, 12, 45, 67};
  vector<int> nums2 = {5, 6};

  cout << median_of_array(nums1, nums2) << endl;
  cout << median(nums1, nums2) << endl;
  return 0;
}