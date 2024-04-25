//区间修改/查询
#include <bits/stdc++.h>
using namespace std;

template <typename T>
class SegTreeLazyRangeSet {
  vector<T> tree, lazy;
  vector<T> *arr;
  int n, root, n4, end;

  void maintain(int cl, int cr, int p) {
    int cm = cl + (cr - cl) / 2;
    if (cl != cr && lazy[p]) {
      lazy[p * 2] = lazy[p];
      lazy[p * 2 + 1] = lazy[p];
      tree[p * 2] = lazy[p] * (cm - cl + 1);
      tree[p * 2 + 1] = lazy[p] * (cr - cm);
      lazy[p] = 0;
    }
  }

  T range_sum(int l, int r, int cl, int cr, int p) {
    if (l <= cl && cr <= r) return tree[p];
    int m = cl + (cr - cl) / 2;
    T sum = 0;
    maintain(cl, cr, p);
    if (l <= m) sum += range_sum(l, r, cl, m, p * 2);
    if (r > m) sum += range_sum(l, r, m + 1, cr, p * 2 + 1);
    return sum;
  }

  void range_set(int l, int r, T val, int cl, int cr, int p) {
    if (l <= cl && cr <= r) {
      lazy[p] = val;
      tree[p] = (cr - cl + 1) * val;
      return;
    }
    int m = cl + (cr - cl) / 2;
    maintain(cl, cr, p);
    if (l <= m) range_set(l, r, val, cl, m, p * 2);
    if (r > m) range_set(l, r, val, m + 1, cr, p * 2 + 1);
    tree[p] = tree[p * 2] + tree[p * 2 + 1];
  }

  void build(int s, int t, int p) {
    if (s == t) {
      tree[p] = (*arr)[s];
      return;
    }
    int m = s + (t - s) / 2;
    build(s, m, p * 2);
    build(m + 1, t, p * 2 + 1);
    tree[p] = tree[p * 2] + tree[p * 2 + 1];
  }

 public:
  explicit SegTreeLazyRangeSet<T>(vector<T> v) {
    n = v.size();
    n4 = n * 4;
    tree = vector<T>(n4, 0);
    lazy = vector<T>(n4, 0);
    arr = &v;
    end = n - 1;
    root = 1;
    build(0, end, 1);
    arr = nullptr;
  }

  void show(int p, int depth = 0) {
    if (p > n4 || tree[p] == 0) return;
    show(p * 2, depth + 1);
    for (int i = 0; i < depth; ++i) putchar('\t');
    printf("%d:%d\n", tree[p], lazy[p]);
    show(p * 2 + 1, depth + 1);
  }

  T range_sum(int l, int r) { return range_sum(l, r, 0, end, root); }

  void range_set(int l, int r, int val) { range_set(l, r, val, 0, end, root); }
};
//用法
#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<int> arr = {1, 3, 5, 7, 9}; // 要建立线段树的初始数组
    SegTreeLazyRangeSet<int> seg_tree(arr); // 创建线段树对象

    // 输出初始线段树结构
    cout << "初始线段树结构：" << endl;
    seg_tree.show(1); // 从根节点开始遍历输出线段树

    // 查询区间 [1, 3] 的和
    int sum = seg_tree.range_sum(1, 3);
    cout << "区间 [1, 3] 的和为：" << sum << endl;

    // 将区间 [2, 4] 的所有元素设置为 4
    seg_tree.range_set(2, 4, 4);

    // 输出更新后的线段树结构
    cout << "更新后的线段树结构：" << endl;
    seg_tree.show(1);

    // 再次查询区间 [1, 3] 的和，此时应该是更新后的值
    sum = seg_tree.range_sum(1, 3);
    cout << "更新后，区间 [1, 3] 的和为：" << sum << endl;

    return 0;
}

//区间增加
#include <bits/stdc++.h>
using namespace std;

template <typename T>
class SegTreeLazyRangeAdd {
  vector<T> tree, lazy;
  vector<T> *arr;
  int n, root, n4, end;

  void maintain(int cl, int cr, int p) {
    int cm = cl + (cr - cl) / 2;
    if (cl != cr && lazy[p]) {
      lazy[p * 2] += lazy[p];
      lazy[p * 2 + 1] += lazy[p];
      tree[p * 2] += lazy[p] * (cm - cl + 1);
      tree[p * 2 + 1] += lazy[p] * (cr - cm);
      lazy[p] = 0;
    }
  }

  T range_sum(int l, int r, int cl, int cr, int p) {
    if (l <= cl && cr <= r) return tree[p];
    int m = cl + (cr - cl) / 2;
    T sum = 0;
    maintain(cl, cr, p);
    if (l <= m) sum += range_sum(l, r, cl, m, p * 2);
    if (r > m) sum += range_sum(l, r, m + 1, cr, p * 2 + 1);
    return sum;
  }

  void range_add(int l, int r, T val, int cl, int cr, int p) {
    if (l <= cl && cr <= r) {
      lazy[p] += val;
      tree[p] += (cr - cl + 1) * val;
      return;
    }
    int m = cl + (cr - cl) / 2;
    maintain(cl, cr, p);
    if (l <= m) range_add(l, r, val, cl, m, p * 2);
    if (r > m) range_add(l, r, val, m + 1, cr, p * 2 + 1);
    tree[p] = tree[p * 2] + tree[p * 2 + 1];
  }

  void build(int s, int t, int p) {
    if (s == t) {
      tree[p] = (*arr)[s];
      return;
    }
    int m = s + (t - s) / 2;
    build(s, m, p * 2);
    build(m + 1, t, p * 2 + 1);
    tree[p] = tree[p * 2] + tree[p * 2 + 1];
  }

 public:
  explicit SegTreeLazyRangeAdd<T>(vector<T> v) {
    n = v.size();
    n4 = n * 4;
    tree = vector<T>(n4, 0);
    lazy = vector<T>(n4, 0);
    arr = &v;
    end = n - 1;
    root = 1;
    build(0, end, 1);
    arr = nullptr;
  }

  void show(int p, int depth = 0) {
    if (p > n4 || tree[p] == 0) return;
    show(p * 2, depth + 1);
    for (int i = 0; i < depth; ++i) putchar('\t');
    printf("%d:%d\n", tree[p], lazy[p]);
    show(p * 2 + 1, depth + 1);
  }

  T range_sum(int l, int r) { return range_sum(l, r, 0, end, root); }

  void range_add(int l, int r, int val) { range_add(l, r, val, 0, end, root); }
};

//用法
#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<int> arr = {1, 3, 5, 7, 9}; // 要建立线段树的初始数组
    SegTreeLazyRangeAdd<int> seg_tree(arr); // 创建线段树对象

    // 输出初始线段树结构
    cout << "初始线段树结构：" << endl;
    seg_tree.show(1); // 从根节点开始遍历输出线段树

    // 查询区间 [1, 3] 的和
    int sum = seg_tree.range_sum(1, 3);
    cout << "区间 [1, 3] 的和为：" << sum << endl;

    // 将区间 [2, 4] 的所有元素加上 2
    seg_tree.range_add(2, 4, 2);

    // 输出更新后的线段树结构
    cout << "更新后的线段树结构：" << endl;
    seg_tree.show(1);

    // 再次查询区间 [1, 3] 的和，此时应该是更新后的值
    sum = seg_tree.range_sum(1, 3);
    cout << "更新后，区间 [1, 3] 的和为：" << sum << endl;

    return 0;
}


//区间最大/最小值
#include <iostream>
#include <vector>
#include <climits> // For INT_MIN and INT_MAX
using namespace std;

struct Node {
    int max_value;
    int min_value;
    int lazy_add; // 懒惰标记：延迟增加的值
};

template <typename T>
class SegTreeMinMaxLazy {
    vector<Node> tree;
    vector<T> *arr;
    int n, root, n4, end;

    void build(int s, int t, int p) {
        if (s == t) {
            tree[p].max_value = (*arr)[s];
            tree[p].min_value = (*arr)[s];
            tree[p].lazy_add = 0;
            return;
        }
        int m = s + (t - s) / 2;
        build(s, m, p * 2);
        build(m + 1, t, p * 2 + 1);
        tree[p].max_value = max(tree[p * 2].max_value, tree[p * 2 + 1].max_value);
        tree[p].min_value = min(tree[p * 2].min_value, tree[p * 2 + 1].min_value);
        tree[p].lazy_add = 0;
    }

    void push_lazy(int p, int cl, int cr) {
        if (tree[p].lazy_add != 0) {
            tree[p].max_value += tree[p].lazy_add;
            tree[p].min_value += tree[p].lazy_add;
            if (cl != cr) {
                tree[p * 2].lazy_add += tree[p].lazy_add;
                tree[p * 2 + 1].lazy_add += tree[p].lazy_add;
            }
            tree[p].lazy_add = 0;
        }
    }

    void range_add(int l, int r, int val, int cl, int cr, int p) {
        push_lazy(p, cl, cr);
        if (l <= cl && cr <= r) {
            tree[p].max_value += val;
            tree[p].min_value += val;
            if (cl != cr) {
                tree[p * 2].lazy_add += val;
                tree[p * 2 + 1].lazy_add += val;
            }
            return;
        }
        int m = cl + (cr - cl) / 2;
        if (l <= m) range_add(l, r, val, cl, m, p * 2);
        if (r > m) range_add(l, r, val, m + 1, cr, p * 2 + 1);
        tree[p].max_value = max(tree[p * 2].max_value, tree[p * 2 + 1].max_value);
        tree[p].min_value = min(tree[p * 2].min_value, tree[p * 2 + 1].min_value);
    }

    Node range_query(int l, int r, int cl, int cr, int p) {
        push_lazy(p, cl, cr);
        if (l <= cl && cr <= r) return tree[p];
        int m = cl + (cr - cl) / 2;
        Node result;
        result.max_value = INT_MIN;
        result.min_value = INT_MAX;
        if (l <= m) {
            Node left_result = range_query(l, r, cl, m, p * 2);
            result.max_value = max(result.max_value, left_result.max_value);
            result.min_value = min(result.min_value, left_result.min_value);
        }
        if (r > m) {
            Node right_result = range_query(l, r, m + 1, cr, p * 2 + 1);
            result.max_value = max(result.max_value, right_result.max_value);
            result.min_value = min(result.min_value, right_result.min_value);
        }
        return result;
    }

public:
    explicit SegTreeMinMaxLazy<T>(vector<T> v) {
        n = v.size();
        n4 = n * 4;
        tree.resize(n4);
        arr = &v;
        end = n - 1;
        root = 1;
        build(0, end, 1);
        arr = nullptr;
    }

    void range_add(int l, int r, int val) {
        range_add(l, r, val, 0, end, root);
    }

    Node range_query(int l, int r) {
        return range_query(l, r, 0, end, root);
    }
};

int main() {
    vector<int> arr = {1, 3, 5, 7, 9}; // 要建立线段树的初始数组
    SegTreeMinMaxLazy<int> seg_tree(arr); // 创建线段树对象

    // 查询区间 [1, 3] 的最大值和最小值
    Node result = seg_tree.range_query(1, 3);
    cout << "区间 [1, 3] 的最大值为：" << result.max_value << endl;
    cout << "区间 [1, 3] 的最小值为：" << result.min_value << endl;

    // 将区间 [2, 4] 的所有元素加上 2
    seg_tree.range_add(2, 4, 2);

    // 再次查询区间 [1, 3] 的最大值和最小值，此时应该是更新后的值
    result = seg_tree.range_query(1, 3);
    cout << "更新后，区间 [1, 3] 的最大值为：" << result.max_value << endl;
    cout << "更新后，区间 [1, 3] 的最小值为：" << result.min_value << endl;

    return 0;
}
