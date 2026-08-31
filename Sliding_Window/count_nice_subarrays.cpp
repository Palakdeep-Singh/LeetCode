#include <iostream>
#include <vector>
#include <algorithm>
#define vii vector<vector<int>>
#define vi vector<int>
#define rep(i, m) for (int i = 0; i < m; i++)
#define sort(a) sort(a.begin(), a.end())

#define M 1e9

using namespace std;

// Count Number of Nice Subarrays ( Subarrays which contain exactly k odd elements).
// brute force is to find all subarrays and count the odd element in each subarray and check if the odd==k then add it in ans.  Time Complexity: O (n^2), Space Complexity: O(1)

// better is to find the positions of odd elements and then take differnece and check start and end points then calculate
// the subarrays. O(n), O(1)

// optimal is to use two pointers and sliding window approach.
//  O(n), O(1)
int numberOfSubarrays(vi &nums, int k)
{

  int l = 0, r = 0;
  int ans = 0;
  int odds = 0;

  while (r < nums.size())
  {

    if (nums[r] % 2 != 0)
      odds++;

    // if window is invalid then make it valid .
    // condition to use sliding window is that it must be monotonic..
    while (odds > k)
    {
      if (nums[l] % 2 != 0)
        odds--;
      l++;
    }

    ans += r - l + 1;
    r++;
  }

  return ans;
}

int main()
{

  int n;
  cin >> n;

  int k;
  cin >> k;

  vi nums(n);

  rep(i, n) cin >> nums[i];

  // we need to find exactly k, so we find atMost(k) and then subtract atMost(k-1) from it.
  cout << numberOfSubarrays(nums, k) - numberOfSubarrays(nums, k - 1);

  return 0;
}