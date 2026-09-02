#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

#define vii vector<vector<int>>
#define vi vector<int>
#define rep(i, m) for (int i = 0; i < m; i++)
#define sort(a) sort(a.begin(), a.end())

#define M 1e9

using namespace std;

string minWindow(string s, string t)
{

  vector<int> hashMap(256, 0);
  int l = 0, r = 0;
  int count = 0;
  int minlen = 1e9, sIndex = -1;

  int n = s.size(), m = t.size();

  for (int i = 0; i < m; i++)
  {
    char ch = t[i];
    hashMap[ch]++;
  }

  while (r < n)
  {

    char ch = s[r];
    if (hashMap[ch] > 0)
      count++;
    hashMap[ch]--;

    while (count == m)
    {
      if (r - l + 1 < minlen)
      {
        minlen = r - l + 1;
        sIndex = l;
      }

      hashMap[s[l]]++;

      if (hashMap[s[l]] > 0)
        count--;
      l++;
    }

    r++;
  }

  return sIndex == -1 ? "" : s.substr(sIndex, minlen);
}

int main()
{

  string s, t;
  cin >> s >> t;

  cout << minWindow(s, t) << endl;
  return 0;
}