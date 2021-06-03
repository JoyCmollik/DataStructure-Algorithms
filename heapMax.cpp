#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long int ulli;

//this code is for such conditions where user gives the input array

void insertHeap(vector<int> &heapArray, int inseKey)
{
 if (heapArray.size() == 1)
  heapArray.push_back(inseKey);
 else
 {
  heapArray.push_back(inseKey);
  int posi = heapArray.size() - 1;

  while (heapArray[posi / 2] < heapArray[posi])
  {
   swap(heapArray[posi], heapArray[posi / 2]);
   posi = posi / 2;
  }
 }
}

int main()
{
 int len;
 cout << "Write the length of the Heap:";
 cin >> len;

 vector<int> heapList;

 while (len--)
 {
  int temp;
  cin >> temp;

  insertHeap(heapList, temp);
 }

 for (auto q : heapList)
  cout << q << " ";

 return 0;
}