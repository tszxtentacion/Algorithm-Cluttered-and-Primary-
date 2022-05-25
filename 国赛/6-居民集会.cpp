#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;
const int N = 100010;
typedef long long ll;
vector<int> vec; //  用来存站点，vector方便递归是的选/丢
int n, l;
int dist[N], num[N];
ll ans = 1e9;
void dfs(int step)
{
    // 出口，若待选的三个都确定了
    if (vec.size() == 3)
    {
        vec.push_back(l); // 压入固定的那个第四个
        ll tmp = 0;       // 该方案下的效益
        int idx = 0;      // 遍历每一户人家的时候，判断到哪个站点了
        for (int i = 1; i <= n; i++)
        {
            if (dist[i] <= vec[idx])
                tmp += 1ll * (vec[idx] - dist[i]) * num[i];
            if (dist[i] == vec[idx]) // 说明下一户人家属于下一个站点了
                idx++;
        }
        // 取较小者
        ans = min(ans, tmp);
        vec.pop_back();
        return;
    }
    // 遍历,递归
    for (int i = step; i <= n; i++)
    {
        vec.push_back(dist[i]);
        dfs(i + 1);
        vec.pop_back();
    }
}

int main()
{
    cin >> n >> l;
    for (int i = 1; i <= n; i++)
        cin >> dist[i] >> num[i];
    dfs(1);
    cout << ans << endl;
    return 0;
}