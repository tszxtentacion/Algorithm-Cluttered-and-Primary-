#include <iostream>
#include <algorithm>
using namespace std;
const int N = 1009;
int f[N], n = 4, m;
int a[] = {10, 20, 50, 100};
int main()
{
    cin >> m;
    for (int i = 0; i < n; i++)
        for (int j = a[i]; j <= m; j++)
            f[j] += f[j - a[i]];
    cout << f[m] << endl;
    return 0;
}