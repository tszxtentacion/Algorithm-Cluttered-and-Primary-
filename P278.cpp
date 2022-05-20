#include <iostream>
#include <algorithm>
using namespace std;
const int N = 109, M = 100010;
int f[M], a[N];
int n, m;
int main()
{
    cin >> n >> m;
    f[0] = 1;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        for (int j = m; j >= a[i]; j--)
            f[j] += f[j - a[i]];
    }
    cout << f[m] << endl;
    return 0;
}