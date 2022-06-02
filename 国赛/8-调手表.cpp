#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;
const int N = 1e5;
int n, k, num[N];
queue<int> q;
// “最优策略”--->bfs
void bfs()
{
    memset(num, -1, sizeof num);
    q.push(0);
    while (q.size())
    {
        int front = q.front();
        q.pop();
        // 向前拨1
        int t1 = (front + 1) % n;
        if (num[t1] = -1) // 若该时间（拨了1之后）赋过值， 则跳过，因为第一次赋就是最小的
        {
            num[t1] = num[front] + 1;
            q.push(t1);
        }
        // 向前拨k
        int t2 = (front + k) % n;
        if (num[t2] == -1)
        {
            num[t2] = num[front] + 1;
            q.push(t2);
        }
    }
}

int main()
{
    cin >> n >> k;
    bfs();
    sort(num, num + n);
    cout << num[n - 1] << endl;
    return 0;
}