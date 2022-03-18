#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
const int N = 100010;
ll a[N], p[N], q[N], n, mina = 1e10, minb = 1e10, minv = 1e10;

ll gcd(ll a, ll b)
{
    return b ? gcd(b, a % b) : a;
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
        scanf("%lld", &a[i]);
    sort(a, a + n);
    int m = unique(a, a + n) - a; //去重后的数量
    for (int i = 0; i < m - 1; i++)
    {
        ll k = gcd(a[i], a[i + 1]);
        p[i] = a[i + 1] / k;
        q[i] = a[i] / k;
    }
    ll pp = p[0], qq = q[0];
    for (int i = 0; i < m; i++)
    {
        pp = gcd(pp, p[i]);
        qq = gcd(qq, q[i]);
    }
    ll k = gcd(pp, qq);
    cout << pp / k << '/' << qq / k << endl;
    return 0;
}