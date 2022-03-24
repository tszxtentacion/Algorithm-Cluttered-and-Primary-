#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
const int N = 53, MOD = 1000000007;
int n, m, k;
int a[N][N];
int ans, f[N][N][14][14]; //存放的是方案数量
int main()
{
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
        {
            scanf("%d", &a[i][j]);
            a[i][j]++;
        }
    // 起点！！！
    f[1][1][0][0] = 1, f[1][1][1][a[1][1]] = 1;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
        {
            if (i == 1 && j == 1)
                continue;
            for (int c = 0; c <= k; c++)
                for (int maxv = 0; maxv <= 13; maxv++)
                {
                    f[i][j][c][maxv] = (f[i][j][c][maxv] + f[i - 1][j][c][maxv]) % MOD;
                    f[i][j][c][maxv] = (f[i][j][c][maxv] + f[i][j - 1][c][maxv]) % MOD;
                    if (c > 0 && a[i][j] == maxv)
                    {
                        for (int last_max = 0; last_max < maxv; last_max++)
                        {
                            f[i][j][c][maxv] = (f[i][j][c][maxv] + f[i - 1][j][c - 1][last_max]) % MOD;
                            f[i][j][c][maxv] = (f[i][j][c][maxv] + f[i][j - 1][c - 1][last_max]) % MOD;
                        }
                    }
                }
        }
    for (int i = 0; i <= 13; i++)
        ans = (ans + f[n][m][k][i]) % MOD;
    cout << ans << endl;
    return 0;
}