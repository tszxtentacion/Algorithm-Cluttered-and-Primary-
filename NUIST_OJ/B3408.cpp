#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#define INF 1e9
using namespace std;
const int N = 2509, M = 6209;
int dist[N];
int n, m, s, t;
// 用vector来存图
vector<pair<int, int> > g[N];
// Dijkstra - priority_queue
void pro_dijkstra(int s)
{
    for (int i = 1; i <= n; i++)
        dist[i] = INF;
    dist[s] = 0;
    priority_queue<pair<int, int> > q;
    q.push(make_pair(0, s));

    // 可以视为，用优先队列来优化原来的遍历找最小值
    while (q.size())
    {
        int u = q.top().second;
        q.pop();
        //遍历该点的邻接点
        for (int i = 0; i < g[u].size(); i++)
        {
            int v = g[u][i].first;  //邻接点
            int w = g[u][i].second; //权重
            if (dist[v] > dist[u] + w)
            {
                dist[v] = dist[u] + w;
                q.push(make_pair(-dist[v], v));
            }
        }
    }
}

int main()
{
    cin >> n >> m >> s >> t;
    //朴素Floyd算法，过70%
    // for (int i = 1; i <= n; i++)
    //     for (int j = 1; j <= n; j++)
    //         if (i == j)
    //             dist[i][j] = 0;
    //         else
    //             dist[i][j] = 1e9;
    // for (int i = 1; i <= m; i++)
    // {
    //     int u, v, w;
    //     cin >> u >> v >> w;
    //     dist[u][v] = w;
    //     dist[v][u] = w;
    // }
    // for (int k = 1; k <= n; k++)
    //     for (int i = 1; i <= n; i++)
    //         for (int j = 1; j <= n; j++)
    //             if (dist[i][j] > dist[i][k] + dist[k][j])
    //                 dist[i][j] = dist[i][k] + dist[k][j];
    for (int i = 1; i <= m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        g[u].push_back(make_pair(v, w));
        g[v].push_back(make_pair(u, w));
    }
    pro_dijkstra(s);
    cout << dist[t] << endl;
    return 0;
}