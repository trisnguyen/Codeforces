/* ---------------------------------------------------------------------------
** This software is under the MIT license (MIT)

** 544B_SeaAndIslands.cpp
** Problem: http://codeforces.com/problemset/problem/544/B
**
** Author: Tristan Nguyen
** Email: trismnguyen@gmail.com
** -------------------------------------------------------------------------*/

#include <iostream>
using namespace std;

const int N_MAX = 100;

bool SeaAndIsland(int pN, int pK)
{
  int n = pN;
  int kMax = (n / 2) * n + (n % 2) * ((n /2) + (n % 2));
  if (pN > N_MAX || pK > kMax)
  {
    cout << "NO" << endl;
    return false;
  }

  //initialize map
  char map[N_MAX][N_MAX];
  for (int i = 0; i < N_MAX; ++i)
    for (int j = 0; j < N_MAX; ++j)
      map[i][j] = 'S';

  //populate islands
  int i = 0, j = 0, k = 0;  //first row
  while (k < pK)
  {
    if (j >= n)
    {
      //something wrong the program should never reach here
      cout << "NO" << endl;
      return false;
    }

    map[i][j] = 'L';
    ++k;
    j += 2;
    if (j >= n)  // go to next row
    {
      i++;
      j = (j + 1) % 2;
    }
  }

  //print the result
  cout << "YES" << endl;
  for (int i = 0; i < n; ++i)
  {
    for (int j = 0; j < n; ++j)
      cout << map[i][j];
    cout << endl;
  }

  return true;
}

int main_544B()
{
  int n = 0;
  int k = 0;
  cin >> n;
  cin >> k;
  SeaAndIsland(n, k);
  return 0;
}