#include <bits/stdc++.h>

using namespace std;

//this code is for predefined array in program

vector<int> ar = {2, 7, 4, 10};

class Solution
{
public:
 void Heapify(int s, int i)
 {
  int root = i;

  int leftChi = 2 * i + 1;
  int rightChi = 2 * i + 2;

  if (leftChi < s && ar[leftChi] > ar[root])
   root = leftChi;
  if (rightChi < s && ar[rightChi] > ar[root])
   root = rightChi;

  if (root != i)
  {
   swap(ar[root], ar[i]);
   Heapify(s, root);
  }
 }
};

int main()
{
 Solution solution;
 for (int i = ar.size() / 2 - 1; i > -1; i--)
  solution.Heapify(ar.size(), i);

 for (auto x : ar)
  cout << x << " ";
 cout << endl;

 return 0;
}