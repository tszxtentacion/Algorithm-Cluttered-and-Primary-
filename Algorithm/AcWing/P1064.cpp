#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;
const int N = 12, S = (1 << N); // 棋盘、国王常量， 状态数量

ll f[N][N * N][S]; // 第i行，已经有了j个，第i行的状态
int n, m;
int cnt[S]; // 状态S中的国王的数量
vector<int> state;
vector<int> head[S]; //  存当前状态的下一行可能状态

// 检查一行中的相邻格子是否都摆放，若是，则false
bool check(int x)
{
    return !(x & (x >> 1));
}

// 统计状态x中的国王数量
int count(int x)
{
    int c = 0;
    for (int i = 0; i < n; i++)
        c += (x >> i & 1);
    return c;
}

int main()
{
    cin >> n >> m;
    // 1. 对每一个可能状态进行合法化判断
    for (int i = 0; i < (1 << n); i++)
    {
        if (check(i))
        {
            state.push_back(i);
            cnt[i] = count(i);
        }
    }
    // 2. 对每一个可能状态的相邻行进行合法化
    for (int i = 0; i < state.size(); i++)
        for (int j = 0; j < state.size(); j++)
        {
            int a = state[i], b = state[j];
            if ((a & b) == 0 && check(a | b))
                head[i].push_back(j);
        }
    // 初始化
    f[0][0][0] = 1;
    // dp
    for (int i = 1; i <= n + 1; i++)               // 枚举1～n+1行
        for (int j = 0; j <= m; j++)               //枚举国王数量
            for (int a = 0; a < state.size(); a++) //枚举所有合法状态
                for (int b = 0; b < head[a].size(); b++)
                {
                    int c = cnt[state[a]];
                    if (j >= c) // 前i行的国王总数量必定大于第i行的
                        f[i][j][a] += f[i - 1][j - c][head[a][b]];
                }
    // 输出时，用n+1行, 什么都不放
    cout << f[n + 1][m][0] << endl;
    return 0;
}