#include <iostream>
#include <algorithm>
using namespace std;
const int N = 1001, MOD = 123456;
int n, k;
int a[N];
int ans;
// 用于判断该位置是否为转折点
bool judge(int i)
{
    if ((a[i] > a[i - 1] && a[i] > a[i + 1]) || (a[i] < a[i - 1] && a[i] > a[i + 1]))
        return true;
    return false;
}

// 交换数组中两个位置的值
void swap(int i1, int i2)
{
    int tmp = a[i1];
    a[i1] = a[i2];
    a[i2] = tmp;
}

// step: 递归的层数; sum: 当前转折点的数量
void dfs(int step, int sum)
{
    // 判断是否为转折点
    if (step > 2 && judge(step - 2))
        sum++;
    // 剪枝，转折点过多或者过少都进行剪枝
    if (sum > k - 1 || sum + n - step < k - 1)
        return;
    // 全排列递归的出口
    if (step == n - 1)
    {
        if (step > 1 && judge(step - 1))
            sum++;
        if (sum == k - 1)
            ans++;
        return;
    }
    // 全排列
    for (int i = step; i < n; i++)
    {
        swap(step, i);
        dfs(step + 1, sum);
        swap(step, i);
    }
}

int main()
{
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
        a[i] = i;
    dfs(0, 0);
    cout << ans << endl;
    return 0;
}
