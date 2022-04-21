#include <iostream>
#include <algorithm>
using namespace std;
const int N = 1009;
int a[N], b[N], n;
int sequence[N]; //  最优序列，存放的是任务的序号(id)
int time_[N];
struct node
{
    // shorter: a、b中用时更短的时间
    int shorter, id;
} task[N];
bool comp(node x, node y)
{
    return x.shorter < y.shorter;
}
int main()
{
    while (cin >> n)
    {
        for (int i = 0; i < n; i++)
        {
            task[i].id = i;
            cin >> a[i];
        }
        for (int i = 0; i < n; i++)
        {
            cin >> b[i];
            task[i].shorter = min(a[i], b[i]);
        }
        sort(task, task + n, comp);
        int aa = 0, bb = n - 1; //前后一起往中间找
        for (int i = 0; i < n; i++)
        {
            if (task[i].shorter == a[task[i].id]) //如果A上的时间比B上的小,优先考虑
                sequence[aa++] = task[i].id;
            else
                sequence[bb--] = task[i].id;
        }
        // 统计在A上所花费的时间
        for (int i = 1; i <= n; i++) //此时的i表示“个数”,注意与下标的对应关系
            time_[i] = time_[i - 1] + a[sequence[i - 1]];
        // 第一个在A上完成的任务可以直接立即在B上开始
        int sum = time_[1] + b[sequence[0]];
        //统计在B上所花费的时间
        for (int i = 2; i <= n; i++)
            sum = max(time_[i], sum) + b[sequence[i - 1]];
        cout << sum << endl;
    }
    return 0;
}