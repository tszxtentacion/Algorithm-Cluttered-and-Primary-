#include <iostream>
#include <algorithm>
#include <map>
using namespace std;
map<int, int> m;
typedef long long ll;
const int N = 2007;
int T, n, k, a[N], b[N], c[N], d[N];
ll ans;

int main()
{
    cin >> T;
    while (T--)
    {
        ans = 0;
        m.clear();
        cin >> n;
        for (int i = 0; i < n; i++)
            scanf("%d %d %d %d", &a[i], &b[i], &c[i], &d[i]);
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
            {
                int s = -a[i] - b[j];
                m[s]++;
            }
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
            {
                int s = c[i] + d[j];
                ans += m[s];
            }
        cout << ans << endl;
    }
    return 0;
}