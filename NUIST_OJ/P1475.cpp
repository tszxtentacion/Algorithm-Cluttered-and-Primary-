#include <iostream>
#include <algorithm>
using namespace std;
const int N = 509;
int n, money;
bool vis_t[N];
struct node
{
    int t, v;
} a[N];

bool comp(const node &a, const node &b)
{
    return a.v > b.v;
}

int main()
{
    cin >> money;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i].t;
    for (int i = 1; i <= n; i++)
        cin >> a[i].v;
    sort(a + 1, a + n + 1, comp);
    //  最优贪心，即假设每个游戏可在ddl前最后一秒完成，一以此给别的游戏机会
    for (int i = 1; i <= n; i++)
    {
        int flag = 0; // 无法完成的标志
        for (int j = a[i].t; j >= 1; j--)
        {
            if (vis_t[j] == false) //该时间没有被使用过
            {
                vis_t[j] = true;
                flag = 1;
                break; //当前任务在最贪心的情况下完成了，考虑下一个任务
            }
        }
        if (flag == 0) //如果该任务所有允许时间都被用过，即无法完成,那么这一次完成最后一个任务
        {
            for (int j = n; j >= 1; j--)
            {
                if (vis_t[j] == 0)
                {
                    vis_t[j] = 1;
                    break;
                }
            }
            money -= a[i].v; // 预定任务未完成，则扣钱
        }
    }
    cout << money << endl;
    return 0;
}