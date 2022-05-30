#include <iostream>
#include <algorithm>
using namespace std;
#define INFO 0x3f3f3f3f
const int C = 104, S = 1010, Q = 10010;

int g[C][C];
int c, s, q, case_, ans;

int main()
{
    while (cin >> c >> s >> q)
    {
        // 初始化
        for (int i = 1; i <= c; i++)
            for (int j = 1; j <= c; j++)
                if (i == j)
                    g[i][j] = 0;
                else
                    g[i][j] = INFO;
        for (int i = 1; i <= s; i++)
        {
            int u, v, w;
            cin >> u >> v >> w;
            if (g[u][v] != 0)
                g[u][v] = w,
                g[v][u] = w;
        }
        // 修改的floyd实现“最大中的最小”
        for (int k = 1; k <= c; k++)
            for (int i = 1; i <= c; i++)
                for (int j = 1; j <= c; j++)
                    if (g[i][k] != INFO && g[k][j] != INFO)
                        g[i][j] = min(g[i][j], max(g[i][k], g[k][j]));
        case_ += 1;
        cout << "Case #" << case_ << endl;
        for (int i = 1; i <= q; i++)
        {
            int u, v;
            cin >> u >> v;
            if (g[u][v] == INFO)
                cout << "no path" << endl;
            else
                cout << g[u][v] << endl;
        }
    }
    return 0;
}