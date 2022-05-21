#include <iostream>
#include <algorithm>
using namespace std;
const int N = 100010;
int prime[N];
int cnt = 0; // 素数存在数组里的位置，已有素数的个数
bool vis[N];
void eulerSevie(int n)
{
    for (int i = 2; i <= n; i++)
    {
        if (vis[i] == false) // 未被访问，即为素数
            prime[++cnt] = i;
        // 欧拉筛的核心
        for (int j = 1; j <= cnt && i * prime[j] <= n; j++)
        {
            vis[i * prime[j]] = true;
            if (i % prime[j] == 0)
                break;
        }
    }
}