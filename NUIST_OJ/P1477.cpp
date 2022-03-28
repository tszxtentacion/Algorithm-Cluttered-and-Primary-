#include <iostream>
#include <algorithm>
using namespace std;
const int N = 104;
int m[N], v[N], t, n;
double ans;
struct node
{
    double m, v;
    double p;
} a[N];
bool cmp(node a, node b)
{
    return a.p > b.p;
}
int main()
{
    cin >> n >> t;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i].m >> a[i].v;
        a[i].p = a[i].v / a[i].m;
    }
    sort(a, a + n, cmp);
    for (int i = 0; i < n; i++)
    {
        if (t >= a[i].m)
        {
            t -= a[i].m;
            ans += a[i].v;
        }
        else
        {
            ans += t * a[i].p;
            break;
        }
    }
    printf("%.2f\n", ans);
    return 0;
}