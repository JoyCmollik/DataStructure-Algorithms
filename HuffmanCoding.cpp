#include <bits/stdc++.h>

using namespace std;

struct node
{
 char ch;
 int fr;
 node *left, *right;

 node(char c, int f)
 {
  fr = f;
  ch = c;
  left = right = nullptr;
 }
};

struct comp
{
 bool operator()(node *a, node *b)
 {
  return a->fr > b->fr;
 }
};

class HuffmanCoding
{
private:
 priority_queue<node *, vector<node *>, comp> minHeap; // min-heap priority queue
 void printHuffmanCodes(node *root, string s);

public:
 void takeInput();
 void huffmanTree();
};

void HuffmanCoding::takeInput()
{
 int _size;
 cout << "Enter number of characters:";
 cin >> _size;

 char a;
 int freq;

 while (_size--)
 {
  cin >> a >> freq;
  minHeap.push(new node(a, freq));
 }
 node *newNode = minHeap.top();
}

void HuffmanCoding::printHuffmanCodes(node *root, string s)
{
 if (!root)
 {
  return;
 }

 if (root->ch != '$')
 {
  cout << root->ch << " ->" << s << endl;
 }

 printHuffmanCodes(root->left, s + "0");
 printHuffmanCodes(root->right, s + "1");
}

void HuffmanCoding::huffmanTree()
{
 while (minHeap.size() > 1)
 {
  node *left = minHeap.top();  // taking top most element which is having less frequency
  minHeap.pop();               // deleting from the queue
  node *right = minHeap.top(); // taking another min freqeuncy holder
  minHeap.pop();               // deleted this one too

  node *newNode = new node('$', left->fr + right->fr); // storing a new node with freq set to extracted two nodes freq
  newNode->left = left;                                // now new node's left child is first most extracted element
  newNode->right = right;                              // new node's right child is last most extracted element
  minHeap.push(newNode);                               // assigning this sub tree to the min-heap
 }

 printHuffmanCodes(minHeap.top(), "");
}

int main()
{
 HuffmanCoding *demo1 = new HuffmanCoding();
 demo1->takeInput();
 demo1->huffmanTree();

 return 0;
}