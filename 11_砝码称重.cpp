#include <iostream>
#include <algorithm>
using namespace std;
const int N = 102, M = 200010, B = 100005; //天平两侧，所以两个B
int n, total, w[N];
bool f[N][M];
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &w[i]);
        total += w[i];
    }
    f[0][B] = true;
    for (int i = 1; i <= n; i++)
        for (int j = -total; j <= total; j++) //负数， 所以加了B这个偏移量
        {
            f[i][j + B] = f[i - 1][j + B];
            if (j - w[i] >= -total)
                f[i][j + B] |= f[i - 1][j - w[i] + B];
            if (j + w[i] <= total)
                f[i][j + B] |= f[i - 1][j + w[i] + B];
        }

    int res = 0;
    for (int i = 1; i <= total; i++)
    {
        if (f[n][i+B])
            res++;
    }
    cout << res << endl;
    return 0;
}
