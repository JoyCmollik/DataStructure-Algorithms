#include <bits/stdc++.h>

using namespace std;

class MyLinkedList
{
 struct node
 {
  int val;
  node *next;

  node(int x) : val(x), next(NULL) {}
 };

 node *head;
 node *tail;
 int size;

public:
 MyLinkedList()
 {
  head = NULL;
  tail = NULL;
  size = 0;
 }

 int get(int index)
 {
  if (index < 0 || index >= size) //checking if the index is valid
   return -1;

  if (index == 0) // if it calls for front value
   return head->val;

  if (index == size - 1) // if it calls for last value
   return tail->val;

  node *temp = head;
  for (int i = 1; i <= index; i++) // if i = 1 executes then temp stands at indx1
   temp = temp->next;
  return temp->val;
 }

 void addAtHead(int val)
 {
  node *newNode = new node(val);
  if (size == 0)
  {
   head = newNode;
   tail = newNode;
  }
  else
  {
   newNode->next = head;
   head = newNode;
  }
  size++;
 }

 void addAtTail(int val)
 {
  if (size == 0)
  {
   addAtHead(val);
   return;
  }

  node *newNode = new node(val);

  tail->next = newNode; // already tail is pointing the last node
  tail = newNode;       // now tail is our new input
  size++;               // size of the list increases
 }

 void addAtIndex(int index, int val)
 {
  if (index < 0 || index >= size) // checked invalid indexes
   return;

  if (index == 0) // means we want to add node in the head;
  {
   addAtHead(val);
   return;
  }

  if (index == size)
  {
   addAtTail(val);
   return;
  }

  node *temp = head;

  node *newNode = new node(val);

  //let us assume desired index is now three

  for (int i = 1; i < index; i++) // if i = 1 executes temp points indx[1],we need index 2 so that index 2 next points our new node
  {
   temp = temp->next;
  }

  newNode->next = temp->next; // connecting newNode with previous three indx node
  temp->next = newNode;       // indx two next is now pointing to new node
  size++;
 }

 void deleteAtIndex(int index)
 {
  if (index < 0 || index >= size) // checking invalid indexes
   return;

  node *temp = head; // storing the head in temp
  node *delNode;     // this node if for deleting node from memory which will point to the index that needs to be deleted by user

  if (index == 0) // if first node selected
  {
   delNode = head;
   head = head->next; // second node becomes head
   delete delNode;
  }
  else if (index == size - 1) // if last node selected
  {
   int i = 1;
   while (i < size - 1) // getting temp at the prev node of last node
   {
    temp = temp->next;
    i++;
   }
   temp->next = NULL; // last element got separated
   delNode = tail;    //storing last element
   tail = temp;       // making prev node tail
   delete delNode;    // deleting last node from memory
  }
  else
  {
   int i = 1;
   while (i < index) // getting temp at the prev node of target node
   {
    temp = temp->next;
    i++;
   }

   delNode = temp->next;
   temp->next = temp->next->next;
   delete delNode;
  }

  size--; // as index is valid we will decrease the size of linked list
 }

 void display()
 {
  node *temp = head;

  while (temp->next != NULL)
  {
   cout << temp->val << " -> ";
   temp = temp->next;
  }
  cout << temp->val << " -> ";

  cout << " NULL " << endl;
 }
};

int main()
{
 MyLinkedList mylinkedlist;
 mylinkedlist.addAtTail(1);
 mylinkedlist.display();
 cout << mylinkedlist.get(0) << endl;
}