#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;
const int N = 1009;
int n, m, a[N], b[N], g[N][N], dist[N], in[N], out[N], f[N], head[5 * N];
int ans, cnt;

void dfs(int x)
{
    for (int i = 1; i <= n; i++)
    {
        if (g[x][i] == 0)
            ans = max(ans, cnt);
        else
        {
            cnt++;
            dfs(i);
            cnt--;
        }
    }
}

int main()
{
    while (cin >> n >> m)
    {
        ans = 0, cnt = 0;
        memset(g, 0, sizeof g);
        memset(out, 0, sizeof out);
        memset(in, 0, sizeof in);
        for (int i = 1; i <= m; i++)
        {
            cin >> a[i] >> b[i];
            out[a[i]]++, in[b[i]]++;
            g[a[i]][b[i]] = 1;
        }
        // 从每个起点开始dfs
        for (int i = 1; i <= n; i++)
            if (in[i] == 0)
                dfs(i);
        ans++;
        cout << ans << endl;
    }
    return 0;
}