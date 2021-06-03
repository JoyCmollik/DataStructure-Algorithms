#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long int ulli;

vector<int> takeInput() {
  vector<int> inputArray;
  int size;
  cin >> size;

  while (size--)
  {
    int v;
    cin >> v;

    inputArray.push_back(v);
  }

  return inputArray;
}

int binarySearch(vector<int> a, int l, int h, int s)
{
  if (l == h)
  {
    if (a[l] == s)
      return l + 1;
    else
      return 0;
  }
  else
  {
    int mid = (l + h) / 2;

    if (s == a[mid])
      return mid + 1;

    if (s > a[mid])
      return binarySearch(a, mid + 1, h, s);
    else
      return binarySearch(a, l, mid - 1, s);
  }
}

int main()
{
  vector<int> array = takeInput();

  cout << "Enter the value you want to find: ";

  int keyValue;
  cin >> keyValue;
  int rslt = binarySearch(array, 0, array.size() - 1, keyValue);
  
  if (rslt == 0)
    cout << "[WARNING] data not being found in the list!" << endl;
  else
    cout << "[SUCCESS] data being found in the posi: " << rslt << endl;

  return 0;
}