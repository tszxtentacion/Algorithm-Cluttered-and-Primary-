#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
const int N = 1009, M = 100010;
int g[N][N];
int x, n, m;
int dist[N]; //源点到各个点的最短距离，初始化为最大值
bool vis[N];
int uu[M], vv[M], w[M], ans[N];
void dijkstra(int s)
{
    for (int i = 1; i <= n; i++)
        dist[i] = 0x3f3f3f3f;
    dist[s] = 0;                 //源点置为0
    for (int u = 1; u <= n; u++) //遍历所有点
    {
        int minv = 0x3f3f3f3f, k = 0; // k用来标记最短的点
        //找到当前来看最短的点
        for (int i = 1; i <= n; i++)
            if (!vis[i] && dist[i] < minv)
            {
                minv = dist[i];
                k = i;
            }
        if (k == 0)
            break;
        vis[k] = true; //目前最短的点标记已访问
        for (int v = 1; v <= n; v++)
        {
            if (vis[v])
                continue;
            if (dist[v] > dist[k] + g[k][v])
                dist[v] = dist[k] + g[k][v];
        }
    }
}

int main()
{
    cin >> n >> m >> x;
    memset(g, 0x3f3f3f3f, sizeof g);
    for (int i = 1; i <= m; i++)
    {
        cin >> uu[i] >> vv[i] >> w[i];
        g[uu[i]][vv[i]] = w[i];
    }
    dijkstra(x);
    for (int i = 1; i <= n; i++)
        ans[i] = dist[i];
    memset(dist, 0, sizeof dist);
    memset(vis, false, sizeof vis);
    memset(g, 0x3f3f3f3f, sizeof g);
    //反向建图，转化为单源最短路问题
    for (int i = 1; i <= m; i++)
        g[vv[i]][uu[i]] = w[i];
    dijkstra(x);
    for (int i = 1; i <= n; i++)
        ans[i] = ans[i] + dist[i];
    int maxv = -1;
    for (int i = 1; i <= n; i++)
        maxv = max(maxv, ans[i]);
    cout << maxv << endl;
    return 0;
}