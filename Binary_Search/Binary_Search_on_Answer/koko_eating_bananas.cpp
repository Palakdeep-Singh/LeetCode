#include <bits/stdc++.h>

using namespace std;

int requireTime(vector<int> &bananas, int hour)
{

  int total = 0;

  for (int i = 0; i < bananas.size(); i++)
  {
    total += ceil(bananas[i] / (float)hour);
  }

  return total;
}

int eat_bananas(vector<int> &bananas, int hour)
{

  int high = *max_element(bananas.begin(), bananas.end()), low = 1;

  // for O(n) use for(i=1 to i=max_element) and pass bananas and i in requireTime if <= hour return require.

  while (low <= high)
  {

    int mid = low + (high - low) / 2;
    int require = requireTime(bananas, mid);

    if (require <= hour)
    {
      high = mid - 1;
    }
    else
    {
      low = mid + 1;
    }
  }
  return low;
}

int main()
{

  vector<int> bananas = {3, 6, 7, 11};

  cout << eat_bananas(bananas, 8) << endl;
  return 0;
}