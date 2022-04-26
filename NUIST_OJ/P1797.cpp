#include <iostream>
#include <algorithm>
using namespace std;
const int N = 100010;
int n, a[N], b[N], ans;

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    for (int i = 0; i < n; i++)
        scanf("%d", &b[i]);
    sort(a, a + n), sort(b, b + n);
    int s1 = 0, t1 = n - 1, s2 = 0, t2 = n - 1;
    while (s1 <= t1)
    {
        // a最快比b最快慢，则a最慢与b最快比赛
        if (a[t1] >b[t2])
        {
            t1--, t2--;
            ans += 200;
        }
        // a最快比b最快快，则a最快与b最快比
        else if (a[t1] < b[t2])
        {
            s1++, t2--;
            ans -= 200;
        }
        // a最快与b最快相同，则继续分情况
        else
        { // a最慢比b最慢快,则a最慢与b最慢比
            if (a[s1] > b[s2])
            {
                s1++, s2++;
                ans += 200;
            }
            // 否则用a最慢与b最快比
            else
            {
                if(a[s1] < b[t2])
                    ans -= 200;
                s1++, t2--;
            }
        }
    }
    cout << ans << endl;
    return 0;
}