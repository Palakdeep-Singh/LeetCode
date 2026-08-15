#include <bits/stdc++.h>

using namespace std;

int sqrt_bs(int n)
{

  if (n == 0 || n == 1)
    return n;

  int l = 1, h = n / 2;

  while (l <= h)
  {

    int mid = (l + (h - l) / 2);

    if (mid == n / mid)
    {
      return mid;
    }
    else if (mid < n / mid)
    {
      l = mid + 1;
    }
    else
    {
      h = mid - 1;
    }
  }

  return h;
}

int func(int mid, int n, int m)
{

  long long ans = 1;

  for (int i = 1; i <= n; i++)
  {
    ans *= mid;

    if (ans > m)
    {
      return 2;
    }
  }

  if (ans == m)
  {
    return 1;
  }

  return 0;
}

// Nth Square Root of a Number M.

int nth_sqrt(int n, int m)
{

  int l = 1, h = m;

  while (l <= h)
  {

    int mid = l + (h - l) / 2;

    if (func(mid, n, m) == 1)
    {
      return mid;
    }
    else if (func(mid, n, m) == 0)
    {
      l = mid + 1;
    }
    else
    {
      h = mid - 1;
    }
  }

  return -1;
}
int main()
{

  int n = 2;
  cout << sqrt_bs(n) << endl;
  cout << nth_sqrt(4, 256);
  return 0;
}