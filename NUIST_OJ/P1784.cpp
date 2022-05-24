#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
typedef long long ll;
const int N = 1010, M = 10010;
typedef pair<int, int> PII;
priority_queue<PII> q;

int n, m, a, b;

int main()
{
    cin >> n >> m;
    while (n--)
    {
        cin >> a >> b;
        q.push(make_pair(min(a, b), max(a, b)));
    }
    ll ans = 0; // 已经吃了的量
    while (m-- && q.size())
    {
        ll w = q.top().first, l = q.top().second;
        q.pop();
        ans += w * w;
        l -= w;
        if (l > 0 && w > 0) // 如果还有意义，则入队
            q.push(make_pair(min(l, w), max(l, w)));
    }
    cout << ans << endl;
    return 0;
}