#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;
bool vis[3040];
vector<int> prime;
ll f[3020][3020];

ll dfs(int index, ll sum)
{
    // 记忆化，若已经搜索过这个分支，直接返回
    if (f[index][sum] != -1)
        return f[index][sum];
    // 若当前分支没有搜索过
    if (sum == 2019)
        return 1;
    if (index >= prime.size() || sum > 2019)
        return 0;
    ll ans = 0;
    // 带与不带改结点
    ans += dfs(index + 1, sum);
    ans += dfs(index + 1, sum + prime[index]);
    return f[index][sum] = ans;
}

int main()
{
    // 素数筛
    memset(vis, true, sizeof vis);
    for (int i = 2; i <= 3020; i++)
        if (vis[i])
            for (int j = i; i * j <= 3020; j++)
                vis[j] = false;
    for (int i = 2; i <= 2019; i++)
        if (vis[i])
            prime.push_back(i);
    memset(f, -1, sizeof f);
    ll ans = dfs(0, 0);
    cout << ans << endl;
    return 0;
}