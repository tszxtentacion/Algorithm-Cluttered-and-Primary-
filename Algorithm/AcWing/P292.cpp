#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;
const int N = 10, M = 1 << 10;
int n, m;
string s[N];
int g[1010], cnt[M];
int f[2][M][M];
vector<int> state;

// 状态(行)内合法化
bool check(int state)
{
    for (int i = 0; i < m; i++)
        if ((state >> i & 1) && ((state >> i + 1 & 1) || (state >> i + 2 & 1)))
            return false;
    return true;
}

// 计算该行内有多少个炮兵
int count(int state)
{
    int res = 0;
    for (int i = 0; i < m; i++)
        if (state >> i & 1)
            res++;
    return res;
}

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 0; j < m; j++)
        {
            char c;
            cin >> c;
            g[i] += (c == 'H') << j;
        }

    // 找出所有合法的行内摆放方法（老套路！！！）
    for (int i = 0; i < (1 << m); i++)
        if (check(i))
        {
            state.push_back(i);
            cnt[i] = count(i); // 记录该状态下的行内炮兵个数
        }
    // dp
    for (int i = 1; i <= n; i++)
        for (int j = 0; j < state.size(); j++)         // 第i-1行
            for (int k = 0; k < state.size(); k++)     // 第i行
                for (int u = 0; u < state.size(); u++) // 第i-2行
                {
                    int a = state[j], b = state[k], c = state[u];
                    // 看三行的摆放是否冲突
                    if ((a & b) | (b & c) | (a & c))
                        continue;
                    // 看行内摆放与地形是否冲突
                    if (g[i] & b | g[i - 1] & a)
                        continue;
                    // 滚动数组： i&1
                    f[i & 1][j][k] = max(f[i & 1][j][k], f[i - 1 & 1][u][j] + cnt[b]);
                }
    int ans = 0;
    for (int i = 0; i < state.size(); i++)
        for (int j = 0; j <= state.size(); j++)
            ans = max(ans, f[n & 1][i][j]);
    cout << ans << endl;
    return 0;
}