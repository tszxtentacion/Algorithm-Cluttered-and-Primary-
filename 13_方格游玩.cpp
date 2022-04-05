#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
const int N = 304;
typedef pair<int, int> PII;
typedef long long ll;
//#define x first
//#define y second
int ans = 1e9, n, m;
int dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1};
char g[N][N];
bool st[N][N];
void dfs(int a, int b, int cnt)
{
    if (a == n - 1 && b == m - 1)
    {
        ans = min(ans, cnt);
        return;
    }
    st[a][b] = true;
    for (int i = 0; i < 4; i++)
    {
        int x = a + dx[i], y = b + dy[i];
        if (st[x][y] || x < 0 || x >= n || y < 0 || y >= m)
            continue;
        if (g[x][y] == '2' && g[a][b] == '2')
            continue;
        if (g[x][y] == '2')
            dfs(x, y, cnt + 1);
        else
            dfs(x, y, cnt);
    }
    st[a][b] = false;
}

int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> g[i];
    dfs(0, 0, 0);
    cout << ans << endl;
    return 0;
}