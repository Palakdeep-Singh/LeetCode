#include <iostream>
#include <vector>
#include <algorithm>
#define vii vector<vector<int>>
#define vi vector<int>
#define rep(i, m) for (int i = 0; i < m; i++)
#define sort(a) sort(a.begin(), a.end())

#define M 1e9

using namespace std;
class Solution
{
public:
  int findMin(vector<int> &nums)
  {

    int l = 0, h = nums.size() - 1;
    while (l < h)
    {

      int mid = l + (h - l) / 2;

      if (nums[h] == nums[mid])
      {
        h--;
      }
      else if (nums[mid] > nums[h])
      {
        l = mid + 1;
        ;
      }
      else
      {
        h = mid;
      }
    }
    return nums[l];
  }
};

int main()
{

  Solution s;

  vector<int> arr = {1, 1, 4, 6, 6, 6, 6, 7, 7, 0};

  cout << s.findMin(arr) << endl;

  return 0;
}