#include <bits/stdc++.h>

using namespace std;

vector<int> dataArray;

void Merge(int l, int mid, int h)
{
 vector<int> mergedList;
 int h1 = mid, i = l, j = mid + 1;

 while (i <= h1 && j <= h)
 {
  if (dataArray[i] < dataArray[j])
   mergedList.push_back(dataArray[i++]);
  else
   mergedList.push_back(dataArray[j++]);
 }

 for (; i <= h1; i++)
  mergedList.push_back(dataArray[i]);
 for (; j <= h; j++)
  mergedList.push_back(dataArray[j]);

 int d = 0;
 for (int z = l; z <= h; z++)
  dataArray[z] = mergedList[d++];
}

void MergeSort(int l, int h)
{
 if (l < h)
 {
  int mid = l + (h - l) / 2;
  MergeSort(l, mid);
  MergeSort(mid + 1, h);
  Merge(l, mid, h);
 }
}

int main()
{
 int n;
 cout << "Length: ";

 cin >> n;

 int h = n;

 while (n--)
 {
  int x;
  cin >> x;

  dataArray.push_back(x);
 }

 MergeSort(0, h - 1);

 for (auto v : dataArray)
  cout << v << " ";

 return 0;
}