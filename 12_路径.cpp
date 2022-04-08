#include <iostream>
#include <algorithm>
#include <cmath>
#define INF 1e8
using namespace std;
typedef long long ll;
const int N = 2023;
ll g[N][N], n = 2021;
bool st[2050];
ll dist[2050];
ll gcd(ll a, ll b)
{
    if (a % b == 0)
        return b;
    return gcd(b, a % b);
}

int main()
{
    for (ll i = 1; i <= n; i++)
        for (ll j = i; j <= n; j++)
            if (fabs(i - j) <= 21)
            {
                g[i][j] = i * j /gcd(fabs(i), fabs(j));
                g[j][i] = g[i][j];
            }
            else
            {
                g[i][j] = INF;
                g[j][i] = INF;
            }
    // dijkstra
    int s = 1, t = n;
    for (int i = 1; i <= n; i++)
        dist[i] = INF;
    dist[1] = 0;
    while (!st[t])
    {
        ll node, lowest = INF; //当前的最短的点及其最短距离
        for (ll i = 1; i <= n; i++)
        {
            for (ll j = 1; j <= 2021; j++)
                if (!st[j] && dist[j] < lowest)
                {
                    lowest = dist[j];
                    node = j;
                }
        }

        st[node] = true;
        for (ll i = 1; i <= 2021; i++)
            if (!st[i] && dist[i] > dist[node] + g[node][i])
                dist[i] = dist[node] + g[node][i];
    }
    cout << dist[2021] << endl;
    return 0;
}