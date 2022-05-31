#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
const int N = 100010;
int a[N], n, k, maxv = 0;
int main()
{
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        a[x]++;
        maxv = max(maxv, x);
    }
    int res = 0;
    // k=0进行特判
    if (k == 0)
    {
        for (int i = 0; i <= maxv; i++)
            if (a[i])
                res++;
    }
    else
    {
        for (int i = 0; i < k; i++)
        {
            // 分组， 组内dp; m为组内下标
            int val[N], f[N], m = 0;
            // 积分相差为k的分为一组
            for (int j = i; j <= maxv; j += k)
                val[m++] = a[j];
            // 组内dp
            for (int j = 0; j < m; j++)
            {
                if (j == 0)
                    f[j] = val[j];
                else if (j == 1)
                    f[j] = max(f[j - 1], val[j]);
                else
                    f[j] = max(f[j - 2] + val[j], f[j - 1]);
            }
            res += f[m - 1];
        }
    }
    cout << res << endl;
    return 0;
}