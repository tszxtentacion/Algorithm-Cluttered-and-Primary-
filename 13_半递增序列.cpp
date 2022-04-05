#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
const int N = 1010, MOD = 1000000007;
int n;
ll ans = 1, f[N][N];
ll C(int n, int m)
{
    int x = n - m < m ? (n - m) : m; //常数级优化
    for (int i = 0; i < n; i++)
        f[i][0] = 1;
    for (int i = 1; i <= m; i++)
        f[0][i] = 0;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            f[i][j] = (f[i - 1][j] + f[i - 1][j - 1]) % MOD;
    return f[n][m];
}

int main()
{
    cin >> n;
    cout << C(n, n / 2) << endl;
    return 0;
}

//求组合数并取模

// static long[][] longs=new long[2000][1000];
// //调用这个函数能初始化所有C(n<=1999,m<=999)的组合数，C52,C43...
// private static void combine(int n, int m) {
//         //https://blog.csdn.net/wjl_zyl_1314/article/details/94208359
//         //ACM如需计算较大的组合数可采用（经常会取模，也很方便）。使用C(a, b) = C(a - 1, b) + C(a - 1, b - 1)递推处理
//         //C5 2=C5 3
//         int x = n - m < m ? (n - m) : m;
//         for(int i=0; i<=n; ++i)
//         {
//             longs[i][0] = 1;
//         }
//         for (int k = 1; k <=m; k++) {
//             longs[0][k] = 0;
//         }
//         for(int i=1; i<=n; ++i)
//         {
//             for(int j=1; j<=m; ++j)
//                 longs[i][j] = (longs[i-1][j] + longs[i-1][j-1]) % 1000000007;
//         }
// }