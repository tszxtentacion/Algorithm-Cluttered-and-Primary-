#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>
#define a first
#define b second
using namespace std;
const int N = 304;
typedef pair<int, int> PII;
typedef long long ll;
//#define x first
//#define y second
int ans = 1e9, n, m;
int dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1}, dist[N][N];
char g[N][N];
bool st[N][N];
int bfs()
{
    queue<PII> q;
    PII start;
    start.a = 0, start.b = 0;
    q.push(start);
    st[0][0] = true;
    while (q.size())
    {
        PII t = q.front();
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int x = t.a + dx[i], y = t.b + dy[i];
            if (st[x][y] || x < 0 || x >= n || y < 0 || y >= m)
                continue;
            if (g[x][y] == '2' && g[t.a][t.b] == '2')
                continue;
            if (g[x][y] == '2')
                dist[x][y] = dist[t.a][t.b] + 1;
            else
                dist[x][y] = dist[t.a][t.b];
            st[x][y] = true;
            cout << t.a << ',' << t.b << "-->" << x << "," << y << ": " << dist[t.a][t.b] << endl;
            q.push(make_pair(x, y));
            if (x == n - 1 && y == m - 1)
                return dist[x][y];
        }
    }
    return -1;
}

int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> g[i];
    memset(dist, 0, sizeof dist);
    cout << bfs() << endl;
    return 0;
}