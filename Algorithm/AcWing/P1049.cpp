#include <iostream>
#include <algorithm>
using namespace std;
const int N = 100010, T = 52;
int a[N];
int f[N], t, n;
int main()
{
    cin >> t;
    while (t--)
    {
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            f[0] = a[0];
            f[i] = max(f[i - 1], f[i - 2] + a[i]);
        }
        cout << f[n - 1] << endl;
    }
    return 0;
}