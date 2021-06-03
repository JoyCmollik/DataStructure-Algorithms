#include <bits/stdc++.h>

using namespace std;

//this code is for sorting an array using heap sort algorithm

class Heap
{
private:
  vector<int> ar = {2, 7, 4, 10};
  int _size = ar.size();
  int left(int i) const { return (i << 1) + 1; };  // i*2+1
  int right(int i) const { return (i << 1) + 2; }; // i*2+2

public:
  void Heapify(int s, int i);
  void HeapSort();
  void maxHeap();
  void displayHeapSort();
};

void Heap::Heapify(int s, int i)
{
  int root = i;

  if (left(i) < s && ar[left(i)] > ar[root])
    root = left(i);
  if (right(i) < s && ar[right(i)] > ar[root])
    root = right(i);

  if (root != i)
  {
    swap(ar[root], ar[i]);
    Heapify(s, root);
  }
}

void Heap::HeapSort()
{
  if (_size - 1 == 0)
    return;

  swap(ar[_size - 1], ar[0]);
  _size--;

  Heapify(_size, 0);
  HeapSort();
}

void Heap::maxHeap()
{
  //we will be considering size/2 - 1 to start because we start from that last parent who contains at least one child, say 10(0-9) nodes are there, so 10/2 - 1 is equal to 4 and it's child is 4*2+1=9. then after heapifying this subtree, 4 gets decremented and becomes 3 who bears 7 and 8 as child and they get heapified as well and continues. this way whole array gets heapified.
  for (int i = _size / 2 - 1; i > -1; i--)
    Heapify(_size, i);
}

void Heap::displayHeapSort()
{
  for (auto x : ar)
    cout << x << " ";
  cout << endl;
}

int main()
{
  Heap *heap = new Heap();

  heap->maxHeap();         // to make the array maxHeap
  heap->HeapSort();        // to sort the full maxHeap
  heap->displayHeapSort(); // to get the sorted array

  return 0;
}