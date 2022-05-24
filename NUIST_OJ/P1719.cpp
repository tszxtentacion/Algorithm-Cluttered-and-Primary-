#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int n, k;

int main()
{
    cin >> n >> k;
    vector<int> vec;
    int tmp = 1, ans = 0;
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        if (x == k)
        {
            // 将每个k的下标与最近的幂次的距离插入
            while (tmp * 2 <= i)
                tmp *= 2;
            vec.push_back(i - tmp);
        }
    }
    for (int i = 0; i < vec.size(); i++)
    {
        // 若次数大于距离，则说明此前的步骤可以使得该k被直接删去，所以加1
        if (ans >= vec[i])
            ans += 1;
        // 否则，将对此k所做的步骤作为最大步骤
        else
            ans = vec[i] + 1;
    }
    cout << ans << endl;
    return 0;
}