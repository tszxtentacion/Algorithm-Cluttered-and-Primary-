#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;
const int N = 510;
typedef long long ll;
int m, n, h;
int f[50]; //用一维数组表示二维状态，类似于之前的01背包的优化
ll ans;

int mian()
{
    cin >> m >> n;
    h = (int)(sqrt(2 * (m + n)));
    for (int s = 0; s < (1 << h); s++)
    {
        int tmpH = h, curS = s, cntA = 0, cntB = 0;
        // 初始化最下面一行，因为整体的排列都取决于最下面一行
        for (int i = tmpH; i >= 1; i--, curS>>= 1)
        {
            f[i] = curS & 1; // &1, 即判断最右边是0还是1
            if (f[i])
                cntA++;
            else
                cntB++;
        }
        // 验证该种排列是否满足要求
        while (tmpH--)
        {
            for (int i = 1; i <= tmpH; i++)
            {
                if (f[i + 1] == f[i])
                {
                    cntA++;
                    f[i] = 1;
                }
                else
                {
                    cntB++;
                    f[i] = 0;
                }
            }
        }
        // 判断，并累计结果
        if (cntA == m && cntB == n)
            ans++;
    }
    cout << ans << endl;
    return 0;
}
