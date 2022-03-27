#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
const int N = 1e6 + 10;
int n;
ll ans, a, b, c, s[11];
bool st[11];
// a + b / c

// 用来计算所定区间内的数值大小
ll cal(int i, int j)
{
    ll num = 0;
    while (1)
    {
        num = num * 10 + s[j];
        if (j == i)
            break;
        j--;
    }
    return num;
}

void check()
{
    for (int i = 1; i < 9; i++)
        for (int j = i+1; j < 9; j++)
        {
            a = cal(1, i);
            b = cal(i + 1, j);
            c = cal(j + 1, 9);
            //printf("%lld %lld %lld\n", a, b, c);
            if (a * c + b == n * c)
                ans++;
        }
}

void dfs(int step)
{
    if (step == 10)
    {
        check();
        return;
    }

    for (int i = 1; i <= 9; i++)
    {
        if (st[i])
            continue;
        st[i] = true, s[step] = i;
        dfs(step + 1);
        st[i] = false, s[step] = 0;
    }
    return;
}

int main()
{
    cin >> n;
    dfs(1);
    cout << ans << endl;
    return 0;
}