#include <iostream>
#include <algorithm>
using namespace std;
const int N = 20010;
int V, n;
int f[N];

int main()
{
    cin >> V;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int v;
        cin >> v;
        // j表示当前使用的总体积
        for (int j = V; j >= v; j--)
            f[j] = max(f[j], f[j - v] + v);
    }
    cout << V - f[V] << endl;
    return 0;
}