class MyHashMap
{

 vector<vector<pair<int, int>>> mainList;
 int MAXI = 100000;

 int hash_i(int key)
 {
  return key % MAXI;
 }

public:
 /** Initialize your data structure here. */
 MyHashMap()
 {
  mainList.resize(MAXI);
 }

 /** value will always be non-negative. */
 void put(int key, int value)
 {
  int i = hash_i(key);

  auto &rowList = mainList[i];

  for (auto &it : rowList)
  {
   if (it.first == key)
   {
    it.second = value;
    return;
   }
  }
  mainList[i].push_back({key, value});
 }

 /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
 int get(int key)
 {
  int i = hash_i(key);

  auto &rowList = mainList[i];

  for (auto &it : rowList)
  {
   if (it.first == key)
    return it.second;
  }
  return -1;
 }

 /** Removes the mapping of the specified value key if this map contains a mapping for the key */
 void remove(int key)
 {
  int i = hash_i(key);

  auto &rowList = mainList[i];

  for (auto it = rowList.begin(); it != rowList.end(); it++)
  {
   if (it->first == key)
    rowList.erase(it);
   return;
  }
 }
};

int main()
{
 MyHashMap *obj = new MyHashMap();
 obj->put(key, value);
 int param_2 = obj->get(key);
 obj->remove(key);
}