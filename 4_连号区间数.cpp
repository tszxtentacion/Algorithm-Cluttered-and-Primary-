#include <iostream>
using namespace std;

const int MAX = 50010;
int arr[MAX];

int main()
{
    int n, max, min, ans = 0;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    for (int i = 0; i < n; i++)
    {
        max = 0, min = MAX; //初始化最大值与最小值
        for (int j = i; j < n; j++)
        {
            max = arr[j] > max ? arr[j] : max; //检测最大值是否变化（并修改）
            min = arr[j] < min ? arr[j] : min; //检测最小值是否变化（并修改）
            if (max - min == j - i)
                ans++; // max-min == j-i 则意味着是连号区间
        }
    }
    cout << ans << endl;
    return 0;
}
