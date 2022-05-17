#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
const int N = 2e5 + 7;
int m, p;
struct node
{
    ll l, r, v; // 此处的v为区间最大值
} tree[N * 4 + 1];
// 建树
void build(int l, int r, int k)
{
    tree[k].l = l, tree[k].r = r;
    if (tree[k].l == tree[k].r)
        return;
    int mid = (l + r) / 2;
    build(l, mid, k * 2);
    build(mid + 1, r, k * 2 + 1);
}
// 查询以k为根结点，[l,r]中的最大值
ll query(int l, int r, int k)
{
    if (tree[k].l >= l && tree[k].r <= r)
        return tree[k].v;
    int mid = (tree[k].l + tree[k].r) / 2;
    ll v = 0;
    if (l <= mid)
        v = query(l, r, k * 2);
    if (r > mid)
        v = max(v, query(l, r, k * 2 + 1));
    return v;
}
// 更新区间最大值, x为修改的目标位置
void modify(int k, int x, int v)
{
    // 若是叶子结点，则结束递归
    if (tree[k].l == tree[k].r)
        tree[k].v = v;
    // 分治两端
    else
    {
        int mid = (tree[k].l + tree[k].r) / 2;
        if (x <= mid)
            modify(k * 2, x, v);
        else
            modify(x * 2 + 1, x, v);
        // 回溯，用子结点更新父结点最大值，pushup
        tree[k].v = max(tree[k * 2].v, tree[k * 2 + 1].v);
    }
}

int main()
{
    int n = 0, last = 0;
    cin >> m >> p;
    // 建树，结点数量最多为插入数值的数量
    build(1, m, 1);
    while (m--)
    {
        char op;
        cin >> op;
        if (op == 'A')
        {
            int t;
            cin >> t;
            // 在最后插入，而n（现有数量又初始为0），所以即在n+1处插入
            modify(1, n + 1, ((ll)t + last) % p);
            n++;
        }
        else
        {
            int L;
            cin >> L;
            // 查询[n-L+1, n]内的最大值，从根结点开始寻找
            last = query(n - L + 1, n, 1);
            cout << last << endl;
        }
    }
    return 0;
}
