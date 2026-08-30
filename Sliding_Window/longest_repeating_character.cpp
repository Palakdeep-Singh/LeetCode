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

class Solution
{
public:
  int characterReplacement(string s, int k)
  {

    // FIND THE MAXIMUM REPEATED Character.
    unordered_map<char, int> freq;

    int maxlen = -1;
    int l = 0, r = 0;
    int max_ = -1;

    while (r < s.size())
    {

      freq[s[r]]++;

      max_ = max(max_, freq[s[r]]);

      if (r - l + 1 - max_ > k)
      {
        freq[s[l]]--;
        l++;
      }

      maxlen = max(maxlen, r - l + 1);
      r++;
    }

    return maxlen;
  }
};

int main()
{

  string s;
  cin >> s;

  int k;
  cin >> k;

  Solution res;
  cout << res.characterReplacement(s, k) << endl;
  return 0;
}