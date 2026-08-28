#include <bits/stdc++.h>

using namespace std;

// bruteforce we can do is to find all the possible subarrays and then check for the unique string of max length.

// Time Complexity: O(N^3)
// Space Complexity: O(256)

// Time Complexity: O(N),
// Space Complexity: O(256).

int main()
{

  string s;
  cin >> s;

  unordered_map<char, int> seen_val;

  int maxlen = 0;
  int l = 0, r = 0;

  for (char i : s)
  {
    seen_val[i] = -1;
  }

  while (r < s.size())
  {
    int index = seen_val[s[r]];
    if (index == -1)
    {
      seen_val[s[r]] = r;
    }
    else
    {
      if (index != -1 && index >= l)
      {
        l = index + 1;
      }
      seen_val[s[r]] = r;
    }
    maxlen = max(maxlen, r - l + 1);
    r++;
  }

  cout << maxlen << endl;

  return 0;
}