#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
int f[100][20010], m, n, a[32], b[32];
int main()
{
    while (scanf("%d", &n) != EOF)
    {
        memset(f, 0, sizeof f);
        scanf("%d", &m);
        for (int i = 1; i <= m; i++)
            scanf("%d %d", &a[i], &b[i]);
        for (int i = 1; i <= m; i++)
            for (int j = 0; j <= n; j++)
            {
                if (j < a[i])
                    f[i][j] = f[i - 1][j];
                else
                    f[i][j] = max(f[i][j], f[i - 1][j - a[i]] + b[i]);
            }
        cout << f[m][n] << endl;
    }
    return 0;
}