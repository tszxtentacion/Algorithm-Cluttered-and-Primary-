#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
typedef long long ll;
const int N = 1005;
int f[N][N];
char s[N], t[N];
int main()
{
    cin >> s + 1 >> t + 1;
    memset(f, 0x3f, sizeof f);
    int ls = strlen(s + 1), lt = strlen(t + 1);
    for (int i = 0; i < N; i++)
        f[i][0] = 0;
    for (int i = 1; i <= ls; i++)
        for (int j = 1; j <= lt; j++)
            if (s[i] == t[i])
                f[i][j] = f[i - 1][j - 1];
            else
                f[i][j] = min(f[i - 1][j - 1] + 1, f[i - 1][j]);
    cout << f[ls][lt] << endl;
    return 0;
}