#include <iostream>
#include <algorithm>
using namespace std;
const int N = 30, MOD = 1e9 + 7;
int n, m;
int f[N][N][N];
int st[N][N];  //  判断是否存在X(不喜欢的位置)
int sum[N][N]; // 左下角所有f[i][][]的和
int ans = 1;
// 更新第level层的前缀和数组
void get_FixSum(int level)
{
    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= m; j++)
            sum[i][j] = (sum[i][j - 1] + sum[i - 1][j] - sum[i - 1][j - 1] + f[level][i][j]) % MOD;
}

int main()
{
    cin >> n >> m;
    getchar();
    // 从左上到右下
    for (int i = n; i > 0; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            char tmp = getchar();
            st[i][j] = st[i][j - 1] + (tmp == 'X');
        }
        getchar();
    }
    // 第0层，长度从1到m的积木有一种可能
    f[0][1][m] = 1;
    get_FixSum(0);
    for (int i = 1; i <= n; i++)
    {
        for (int l = 1; l <= m; l++)
            for (int r = l; r <= m; r++)
            {
                // 若[l, r]中存在X
                if (st[i][r] - st[i][l])
                {
                    f[i][l][r] = 0;
                    continue;
                }
                f[i][l][r] = (sum[l][m] - sum[0][m] - sum[l][r - 1] + sum[0][r - 1]) % MOD;
                ans = (ans + f[i][l][r]) % MOD;
            }
        get_FixSum(i);
    }
    cout << (ans + MOD) % MOD;
    return 0;
}