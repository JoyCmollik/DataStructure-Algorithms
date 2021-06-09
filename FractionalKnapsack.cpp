#include <bits/stdc++.h>

using namespace std;

struct item
{
 double price;
 double weight;
 double ppw;

 item(double p, double w)
 {
  price = p;
  weight = w;
  ppw = p / w;
 }
};

class FracKnapsack
{
private:
 int _size;
 double maxWeight;
 vector<item> objArray;

public:
 void takeInput();
 double calMaxProfit();
 void printArray();
};

void FracKnapsack::takeInput()
{
 cout << "Number of objects:";
 cin >> _size;

 cout << "Input price and weight:" << endl;

 for (int i = 0; i < _size; i++) // taking all the inputs
 {
  int p, w;
  cin >> p >> w;

  objArray.emplace_back(item(p, w));
 }

 cout << "Max Weight:";
 cin >> maxWeight;
}

bool compPpw(item a, item b)
{
 if (a.ppw == b.ppw) // if ppw is matched, we want one with greater weight between them
  return a.weight > b.weight;
 return a.ppw > b.ppw;
}

double FracKnapsack::calMaxProfit()
{
 sort(objArray.begin(), objArray.end(), compPpw); // sorting the array according to ppw of all items

 double remWeight = maxWeight, maxProfit = 0;

 for (auto v : objArray)
 {
  if (v.weight <= remWeight) // full weight is takeable as remaining weight is greater
  {
   remWeight -= v.weight;
   maxProfit += v.price;
  }
  else
  {
   maxProfit += remWeight * v.ppw; // we are taking fraction of the item, because remaining weight is not enough
   break;
  }
 }

 return maxProfit;
}

void FracKnapsack::printArray()
{
 for (auto v : objArray)
 {
  cout << v.price << "->" << v.weight << "->" << v.ppw << "->taken frac:" << v.frac << endl;
 }
}

int main()
{
 FracKnapsack *demo1 = new FracKnapsack();
 demo1->takeInput();
 cout << demo1->calMaxProfit() << endl;
 demo1->printArray();

 return 0;
}