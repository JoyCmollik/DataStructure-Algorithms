#include <bits/stdc++.h>

using namespace std;

class MergeSort
{
private:
  vector<int> dataArray = {5, 3, 2, 1};
  int _size = dataArray.size();

public:
  int getSize() const { return _size; };
  void Merge(int l, int mid, int h);
  void MergeSorting(int l, int h);
  void printArray();
};

void MergeSort::Merge(int l, int mid, int h)
{
  vector<int> mergedList;
  int h1 = mid, i1 = l, j2 = mid + 1, h2 = h; //i1 to h1(first list) j2 to h2(second list)

  //comparing two sorted lists
  while (i1 <= h1 && j2 <= h2) // while i1 or j2 reaches to the end of the list
  {
    if (dataArray[i1] < dataArray[j2]) // if i1th element is smaller, it gets into new list, and index increases
      mergedList.push_back(dataArray[i1++]);
    else
      mergedList.push_back(dataArray[j2++]); // on the other hand j2th element is smaller, so it gets into list
  }

  //only one list above will be fully enlisted, other will have left elements
  for (; i1 <= h1; i1++) // checking the first list, if remainings are there
    mergedList.push_back(dataArray[i1]);
  for (; j2 <= h; j2++) // as well checking the second list
    mergedList.push_back(dataArray[j2]);

  int d = 0;
  for (int z = l; z <= h; z++) // now from l to h, all data are sorted, pushing them back to main list from temp one
    dataArray[z] = mergedList[d++];
}

void MergeSort::MergeSorting(int l, int h)
{
  if (l < h) // this condition will be true until l becomes h
  {
    int mid = l + (h - l) / 2;
    MergeSorting(l, mid);     // applying recursion and sending first half until l == h
    MergeSorting(mid + 1, h); // applying recursion and sending second half until l == h
    Merge(l, mid, h);         // after l == h, it returns to this point and sends divided parts into this to merge them
  }
}

void MergeSort::printArray()
{
  for (auto v : dataArray)
    cout << v << " ";
}

int main()
{
  MergeSort *mergesort = new MergeSort();
  int h = mergesort->getSize();
  mergesort->MergeSorting(0, h - 1);
  mergesort->printArray();

  return 0;
}