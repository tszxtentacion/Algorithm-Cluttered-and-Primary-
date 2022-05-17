// 线段树templa
#include <iostream>
#include <algorithm>
using namespace std;
const int N = 101;
int ans;
int x, y;
int a, b;
void down(int);
// 建立结点的结构体
struct node
{
    int l, r, w;   // 左右端点，区间和
    int f;         //
} tree[4 * N + 1]; // 开四倍空间别忘了

// 建树
void build(int l, int r, int k)
{
    tree[k].l = l, tree[k].r = r;
    if (l == r) // 叶子结点
    {
        cin >> tree[k].w;
        return;
    }
    int mid = (l + r) / 2;
    // 建立左右子树
    build(l, mid, k * 2);
    build(mid + 1, r, k * 2 + 1);
    // 状态合并
    tree[k].w = tree[k * 2].w + tree[k * 2 + 1].w;
}

// 单点查询 (查找x位置上的值)
void query(int k)
{
    if (tree[k].l == tree[k].r) // 左右端点相等，则是叶子结点，找到
    {
        ans = tree[k].w;
        return;
    }
    // 此处引入懒标记
    if (tree[k].f)
        down(k);
    int mid = (tree[k].l + tree[k].r) / 2;
    if (x <= mid) // 如果目标位置在左侧,查询左儿子
        query(k * 2);
    else
        query(k * 2 + 1);
}

// 单点修改 (在第x个数上加y)
void add(int k)
{
    if (tree[k].l == tree[k].r) //找到目标位置
    {
        tree[k].w += y;
        return;
    }
    int mid = (tree[k].l + tree[k].r) / 2;
    if (x <= mid)
        add(k * 2);
    else
        add(k * 2 + 1);
    tree[k].w = tree[k * 2].w + tree[k * 2 + 1].w;
}

// 区间查询 (查找区间[x,y]上的和)
void interval_query(int k)
{
    if (tree[k].l >= x && tree[k].r <= y)
    {
        ans += tree[k].w;
        return;
    }
    if (tree[k].f)
        down(k);
    int mid = (tree[k].l + tree[k].r) / 2;
    if (x <= mid)
        interval_query(k * 2);
    if (y > mid)
        interval_query(k * 2 + 1);
}

// 区间修改 (为[a,b]上每一个数都加上x
// 前导: 懒标记下传
void down(int k)
{
    // 结点的左右子结点继承结点的懒标记
    tree[k * 2].f += tree[k].f;
    tree[k * 2 + 1].f = tree[k].f;
    // 依据懒标记，更新结点值(每个懒标记都算次数)
    tree[k * 2].w += tree[k].f * (tree[k * 2].r - tree[k * 2 + 1].l + 1);
    tree[k * 2 + 1].w += tree[k].f * (tree[k * 2 + 1].r - tree[k * 2 + 1].l + 1);
    // 清空该结点的懒标记
    tree[k].f = 0;
}
void interval_add(int k)
{
    // 当前区间全部对要修改的区间有用
    if (tree[k].l >= a && tree[k].r <= b)
    {
        tree[k].w += (tree[k].r - tree[k].l + 1) * x;
        tree[k].f += x; // 先打上懒标记
        return;
    }
    // 当上述条件不满足时，懒标记下传，且一定会用到当前结点的子结点
    int mid = (tree[k].l + tree[k].r) / 2;
    if (a <= mid)
        interval_add(k * 2);
    if (b > mid)
        interval_add(k * 2 + 1);
    // 更改区间状态
    tree[k].w += tree[k * 2].w + tree[k * 2 + 1].w;
}