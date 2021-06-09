#include <bits/stdc++.h>

using namespace std;

class OpMergePattern
{
private:
 priority_queue<int, vector<int>, greater<int>> fileMin; // min-heap priority queue
 int jobSlot;
 int maxProfit = 0;

public:
 void takeInput();
 int getMinMergeCost();
 void printArray();
};

void OpMergePattern::takeInput()
{
 int _size;
 cout << "Enter number of files:";
 cin >> _size;

 int file_size;

 while (_size--)
 {
  cin >> file_size;
  fileMin.push(file_size);
 }
}

int OpMergePattern::getMinMergeCost()
{
 int count = 0;

 while (fileMin.size() > 1)
 {
  int newMerged = fileMin.top();
  fileMin.pop();
  newMerged += fileMin.top();
  fileMin.pop();

  count += newMerged;
  fileMin.push(newMerged);
 }
 return count;
}

int main()
{
 OpMergePattern *demo1 = new OpMergePattern();
 demo1->takeInput();
 cout << demo1->getMinMergeCost() << endl;

 return 0;
}