#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
const int N = 104;

int n, g[N][N], fans[N];

int main()
{
    while (cin >> n)
    {
        memset(g, 0, sizeof g);
        memset(fans, 0, sizeof fans);
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                cin >> g[i][j];
        int ans = 0;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
            {
                if (g[i][j] == 1 && g[j][i] == 0)
                    fans[j]++;
            }
        for (int i = 0; i < n; i++)
            cout << fans[i] << endl;
    }
    return 0;
}