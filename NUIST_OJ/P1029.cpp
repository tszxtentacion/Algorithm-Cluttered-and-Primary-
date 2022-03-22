#include <iostream>
#include <algorithm>
using namespace std;
const int N = 107;
int r, c, g[N][N];
int dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1};
int ans[N][N], ans_ = -1;
int dfs(int i, int j)
{
    if (ans[i][j])
        return ans[i][j];
    ans[i][j] = 1;
    for (int k = 0; k < 4; k++)
    {
        int x = i + dx[k], y = j + dy[k];
        if (x >= 0 && x < r && y >= 0 && y < c && g[x][y] < g[i][j])
        {
            dfs(x, y);
            ans[i][j] = max(ans[i][j], ans[x][y] + 1);
        }
    }
    return ans[i][j];
}

int main()
{
    while (scanf("%d %d", &r, &c) != EOF)
    {
        for (int i = 0; i < r; i++)
            for (int j = 0; j < c; j++)
                scanf("%d", &g[i][j]);
        for (int i = 0; i < r; i++)
            for (int j = 0; j < c; j++)
                ans_ = max(ans_, dfs(i, j));
        cout << ans_ << endl;
    }
    return 0;
}