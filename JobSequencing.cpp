#include <bits/stdc++.h>

using namespace std;

struct job
{
 char id;
 int deadline;
 int profit;

 job(char i, int d, int p)
 {
  id = i;
  deadline = d;
  profit = p;
 }
};

class JobSequencing
{
private:
 vector<job> jobList;
 int jobSlot;
 int maxProfit = 0;

public:
 int getProfit() const { return maxProfit; };
 void takeInput();
 vector<char> finJobSeq();
 void printArray();
};

void JobSequencing::takeInput()
{
 int _size;
 cout << "Enter number of jobs:";
 cin >> _size;

 char a;
 int d, p;

 while (_size--)
 {
  cin >> a >> d >> p;
  jobList.emplace_back(job(a, d, p));
 }

 cout << "Please input available jobSlot:";
 cin >> jobSlot;
}

bool comProfit(job p, job q)
{
 return p.profit > q.profit;
}

vector<char> JobSequencing::finJobSeq()
{
 sort(jobList.begin(), jobList.end(), comProfit);

 vector<char> finJobList;

 unordered_set<int> slot;

 for (int i = 0; i < jobList.size(); i++)
 {
  int limit = jobList[i].deadline;

  while (limit != 0)
  {
   if (slot.count(limit) <= 0)
   {
    finJobList.emplace_back(jobList[i].id);
    slot.insert(limit);
    maxProfit += jobList[i].profit;
    break;
   }
   else
    limit--;
  }
 }
 return finJobList;
}

void JobSequencing::printArray()
{
 for (auto v : jobList)
 {
  cout << v.id << "->" << v.deadline << "->" << v.profit << endl;
 }
}

int main()
{
 JobSequencing *demo1 = new JobSequencing();
 demo1->takeInput();
 vector<char> rslt = demo1->finJobSeq();
 for (auto i : rslt)
  cout << i << "->";
 cout << " profit:" << demo1->getProfit();

 return 0;
}

// a 2 20
// b 2 15
// c 1 10
// d 3 5
// e 3 1