// 并查集
#include <bits/stdc++.h>
// #include <iostream>
// #include <vector>
// #include <numeric> // Include this header for the iota function
using namespace std;

struct dsu
{
  vector<size_t> pa, size;

  explicit dsu(size_t size_) : pa(size_), size(size_, 1)
  {
    iota(pa.begin(), pa.end(), size_t(0));
  }

  size_t find(size_t x)
  {
    return pa[x] == x ? x : (pa[x] = find(pa[x]));
  }

  void unite(size_t x, size_t y)
  {
    x = find(x), y = find(y);
    if (x == y)
      return;
    if (size[x] < size[y])
      swap(x, y);
    pa[y] = x;
    size[x] += size[y];
  }

  void erase(size_t x)
  {
    --size[find(x)];
    pa[x] = x;
  }

  void move(size_t x, size_t y)
  {
    auto fx = find(x), fy = find(y);
    if (fx == fy)
      return;
    pa[x] = fy;
    --size[fx], ++size[fy];
  }
};

int main()
{
  // 创建一个大小为 10 的并查集
  dsu ds(10);

  // 合并一些元素
  ds.unite(1, 2);

  // 查询一个元素的根
  cout << "The leader of element 3 is: " << ds.find(3) << endl;

  // 移动元素 3 到元素集合 5
  ds.move(3, 5);
  cout << "After moving 3 to the set of 5, leader of 3 is now: " << ds.find(3) << endl;

  // 检查元素 3 和 5 是否在同一集合
  if (ds.find(3) == ds.find(5))
  {
    cout << "Element 3 and 5 are now in the same set." << endl;
  }

  // 打印当前集合的大小
  cout << "Size of the set containing 1: " << ds.size[ds.find(1)] << endl;
  cout << "Size of the set containing 5: " << ds.size[ds.find(5)] << endl;

  return 0;
}
