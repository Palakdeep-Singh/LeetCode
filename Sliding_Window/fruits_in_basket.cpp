#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <unordered_map>

#define vii vector<vector<int>>
#define vi vector<int>
#define rep(i, m) for (int i = 0; i < m; i++)
#define sort(a) sort(a.begin(), a.end())

#define M 1e9

using namespace std;

// approach 1:
// generate all the subarrays and figure out the subarray with distinct elments only 2 and calculate the maxsize .

// approach 2:
// brute force on set, store fruit in set till its size is <= 2. else start from next element with new set.
// Time Complexity: O(n^2) and Space Complexity: O(3);
int bruteForce(vi &fruits)
{

  int maxlen = 0;
  for (int i = 0; i < fruits.size(); i++)
  {
    set<int> st;
    for (int j = i; j < fruits.size(); j++)
    {
      st.insert(fruits[j]);

      if (st.size() <= 2)
      {
        maxlen = max(maxlen, j - i + 1);
      }
      else
      {
        break;
      }
    }
  }

  return maxlen;
}

// better approach is ki map use kro and jb tk map ki size >2 h tb tk element ka freq decrease krte jao
// jaise hi freq 0 hoga toh element remove krdo map se.
// Time Complexity: O(2n)
// Space Complexity: O(3)

int better(vi &fruits)
{

  unordered_map<int, int> freq;
  int maxlen = 0;
  int l = 0, r = 0;

  while (r < fruits.size())
  {

    freq[fruits[r]]++;

    while (freq.size() > 2)
    {
      freq[fruits[l]]--;
      if (freq[fruits[l]] == 0)
        freq.erase(fruits[l]);
      l++;
    }

    maxlen = max(maxlen, r - l + 1);
    r++;
  }

  return maxlen;
}

// Optimized Approach: window size maintain rkho jo bhi valid h why unnecessarily l ko itna move krna.
// l ko just 1 time aage move kro and r ko kyuki minimum valid window toh already h.
// Time Complexity: O(n), Space Complexty: O(3)
int optimized(vi &fruits)
{

  unordered_map<int, int> freq;

  int l = 0, r = 0;
  int maxlen = 0;

  while (r < fruits.size())
  {

    freq[fruits[r]]++;

    if (freq.size() > 2)
    {
      freq[fruits[l]]--;

      if (freq[fruits[l]] == 0)
        freq.erase(fruits[l]);
      l++;
    }

    maxlen = max(maxlen, r - l + 1);
    r++;
  }

  return maxlen;
}

int main()
{

  vi fruits = {3, 3, 3, 1, 2, 1, 1, 2, 3, 1, 1};

  // cout << bruteForce(fruits) << "\n";
  // cout << better(fruits) << "\n";
  cout << optimized(fruits) << "\n";

  return 0;
}