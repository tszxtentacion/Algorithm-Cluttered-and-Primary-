#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int N = 13, MOD = 100000000, S = 1 << N;
// typedef long long ll;
int m, n, x, g[N]; //  g[N]用来存储
int f[N + 1][S];
vector<int> state;
vector<int> head[S];

// 检查该状态是否符合要求(是否连续)
bool check(int s)
{
    return !(s & (s >> 1));
}

int main()
{
    cin >> m >> n;
    // 1. 输入，并用状态压缩的思路存储土地情况
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
        {
            cin >> x;
            g[i] += (!x << (j - 1)); //荒废土地是0，我们在这里转换为1
        }
    // 2. 记录合法情况
    for (int i = 0; i < (1 << m); i++)
        if (check(i))
            state.push_back(i);
    // 3, 对每一个可能状态的相邻行
    for (int i = 0; i < state.size(); i++)
        for (int j = 0; j < state.size(); j++)
        {
            int a = state[i], b = state[j];
            if ((a & b) == 0)
                head[i].push_back(j);
        }
    // 初始化
    f[0][0] = 1;
    // dp
    for (int i = 1; i <= n + 1; i++)
        for (int a = 0; a < state.size(); a++)
        {
            // 如果该状态有玉米种在贫瘠土地上
            if (g[i] & state[a])
                continue;
            for (int b = 0; b < head[a].size(); b++)
                f[i][a] = (f[i][a] + f[i - 1][head[a][b]]) % MOD;
        }
    cout << f[n + 1][0] << endl;
    return 0;
}
