#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
const int N = 17, M = 3010;
int n, m;
int a[N];
ll f[M];

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    sort(a + 1, a + n + 1);
    f[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = a[i]; j <= m; j++)
            f[j] += f[j - a[i]];
    }
    cout << f[m] << endl;
    return 0;
}