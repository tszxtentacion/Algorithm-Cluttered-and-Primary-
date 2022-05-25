#include <iostream>
#include <algorithm>
using namespace std;
const int N = 23;
int g[N][N], color[N];
int n, k, m, u, v, ans;
// 判断顶点step是否与相邻点为相同的颜色
bool check(int step, int color_)
{
    for (int j = 1; j <= n; j++)
        if (g[step][j] == 1 && color_ == color[j])
            return false;
    return true;
}

void dfs(int step)
{
    // 递归出口
    if (step > n)
    {
        ans++;
        return;
    }
    // 尝试每一种颜色
    for (int c = 1; c <= m; c++)
    {
        if (check(step, c))
        {
            color[step] = c;
            dfs(step + 1);
            color[step] = 0;
        }
    }
}

int main()
{
    cin >> n >> k >> m;
    for (int i = 1; i <= k; i++)
    {
        cin >> u >> v;
        g[u][v] = 1;
        g[v][u] = 1;
    }
    dfs(1);
    cout << ans << endl;
    return 0;
}