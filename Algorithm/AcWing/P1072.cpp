#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
const int N = 10010;
int h[N], w[2 * N], ne[2 * N], e[2 * N], idx;
int ans;

void add(int a, int b, int c)
{
    w[idx] = c, e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

int dfs(int u, int father)
{
    int dist = 0;
    int d1 = 0, d2 = 0; // 表示子结点中最大和次大的长度
    for (int i = h[u]; i != -1; i = ne[i])
    {
        int j = e[i];
        if (j == father)
            continue;
        int d = dfs(j, u) + w[i];
        dist = max(dist, d);
        //求出最长和次长路径
        if (d >= d1)
            d2 = d1, d1 = d;
        else if (d > d2)
            d2 = d;
    }
    ans = max(ans, d1 + d2);
    return dist;
}

int main()
{
    memset(h, -1, sizeof h);
    int n;
    cin >> n;
    for (int i = 1; i < n; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        add(a, b, c);
        add(b, a, c);
    }
    dfs(1, -1);
    cout << ans << endl;
    return 0;
}
