#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;
const int N = 100010;
int n, a[N], b[N];
struct node
{
    int l, r, sum;
} tree[N * 4]; //个数是如何确定的？？？

typedef unordered_map<int, int> mp;
bool st[N];
void build(int u, int l, int r)
{
    tree[u].l = l, tree[u].r = r;
    tree[u].sum = 0;

    if (l == r)
        return;
    int mid = (l + r) >> 1;
    build(u << 1, l, mid);
    build(u << 1 | 1, mid + 1, r);
    return;
}

void pushup(int u)
{
    tree[u].sum = tree[u << 1].sum + tree[u << 1 | 1].sum;
}

void modify(int u, int pos, int x) // u从1开始，即最顶端开始
{
    if (tree[u].l == tree[u].r) //到达叶子
    {
        tree[u].sum = x;
        return;
    }
    int l = tree[u].l, r = tree[u].r;
    int mid = (l + r) >> 1;
    if (pos <= mid)
        modify(u << 1, pos, x);
    else
        modify(u << 1 | 1, pos, x);
    pushup(u);
}

int query(int u, int l, int r) //目标区间,u也一般从1开始
{
    int cl = tree[u].l, cr = tree[u].r;
    int cmid = (cl + cr) >> 1;
    if (cl >= l && cr <= r)
        return tree[u].sum;
    int ans = 0;
    if (cmid >= l)
        ans += query(u << 1, l, r);
    if (cmid < r)
        ans += query(u << 1 | 1, l, r);
    return ans;
}

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    build(1, 1, n);
    for (int i = 1; i <= n; i++)
    {
        if (mp.count(a[i]) == 0)
        {
            mp[a[i]] = i;
            b[i] = -a[i];
            st[i] = true;
            modify(1, i, 1);
        }
        else
        {
            int t = mp[a[i]];
            st[t] = false;
            st[i] = true;
            modify(1, t, 0);
            modify(1, i, 1);
            mp[a[i]] = i;
            b[i] = query(1, t + 1, i - 1);
        }
    }
    for (int i = 1; i <= n; i++)
        printf("%d ", b[i]);
    return 0;
}