#include <bits/stdc++.h>

using namespace std;

int condition(vector<int> &stations, double mid)
{

  int count_stations = 0;

  for (int i = 0; i < stations.size() - 1; i++)
  {

    // we are counting that we can put mid stations between two consecutive stations.
    int gap = (stations[i + 1] - stations[i]);

    // therefore we can insert gap/mid -1 stations in a gap.
    count_stations += ceil(gap / mid) - 1;
  }

  return count_stations;
}

// distance can be non integer.
double knewStations(vector<int> &stations, int k)
{

  double l = 0;
  double h = 0;
  for (int i = 1; i < stations.size(); i++)
  {
    if (stations[i] - stations[i - 1] > h)
    {
      h = stations[i] - stations[i - 1];
    }
  }

  // we didnt used low <high because it is not an integer binary search problem here the low and high
  // never becomes equal therefore it will run forever because low and high keep getting narrowed.
  // therefore we decide that if range is less than .000001 then we will stop.

  while (h - l > 1e-6)
  {
    double mid = l + (h - l) / 2.0;

    if (condition(stations, mid) > k)
    {
      l = mid;
    }
    else
    {
      h = mid;
    }
  }

  return h;
}

int main()
{

  vector<int> stations = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  int k = 10;

  cout << knewStations(stations, k) << endl;
  return 0;
}