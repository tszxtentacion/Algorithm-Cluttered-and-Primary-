#include <iostream>
#include <algorithm>
#include <cmath>
#include <queue>
#define x first
#define y second
using namespace std;
const int N = 10010;
typedef long long ll;
int a[10];
int g[12][12] = {-7};
bool st[2050];
int ans;
int res[2050];
int bfs()
{
    queue<int> q;
    q.push(2021);
    st[2021] = true;
    while (q.size())
    {
        int t = q.front();
        q.pop();
        // 进行三种操作
        for (int i = 0; i < 3; i++)
        {
            if (t == 1)
                return res[1];
            if (i == 0 && t % 2 == 0)
            {
                int c = t / 2;
                if (!st[c])
                {
                    st[c] = true;
                    q.push(c);
                    res[c] = res[t] + 1;
                }
            }
            if (i == 1)
            {
                int c = t - 1;
                if (!st[c])
                {
                    st[c] = true;
                    q.push(c);
                    res[c] = res[t] + 1;
                }
            }
            if (i == 2)
            {
                int c = t + 1;
                if (!st[c])
                {
                    st[c] = true;
                    q.push(c);
                    res[c] = res[t] + 1;
                }
            }
        }
    }
}
int main()
{
    cout << bfs() << endl;
    return 0;
}