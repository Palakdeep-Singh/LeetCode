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

int kDistinctChar(string &s, int k)
{

  unordered_map<char, int> freq;

  int l = 0, r = 0;
  int maxlen = 0;

  while (r < s.size())
  {
    freq[s[r]]++;

    if (freq.size() > k)
    {
      freq[s[l]]--;

      if (freq[s[l]] == 0)
        freq.erase(s[l]);
      l++;
    }

    maxlen = max(maxlen, r - l + 1);
    r++;
  }

  return maxlen;
}

int main()
{

  string s;
  cin >> s;

  int k;
  cin >> k;

  cout << kDistinctChar(s, k) << endl;

  return 0;
}