#include <iostream>
#include <algorithm>
using namespace std;
const int N = 104;
int n, m;
long long ans;
int f[900][900];

int main()
{
    cin >> m >> n;
    f[1][1] = 1;
    for (int y = 2; y <= m; y++)
        for (int x = 1; x <= n; x++)
        {
            if (y >= 3)
            {
                if (x >= 2)
                    f[x][y] += f[x - 1][y - 2];
            }
            if (y >= 2)
            {
                if (x >= 3)
                    f[x][y] += f[x - 2][y - 1];
            }
        }
    cout << f[n][m] << endl;
    return 0;
}