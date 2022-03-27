#include <iostream>
#include <algorithm>
#include <sstream>
#include <cstring>
using namespace std;
string line;
const int N = 1004;
int n, t, a[N];
int main()
{
    cin >> t;
    getline(cin, line); //用来读取第一行的回车
    while (t--)
    {
        getline(cin, line);
        stringstream ssin(line);
        while (ssin >> a[n])
            n++;
    }
    sort(a, a + n);
    int ans1, ans2;
    for (int i = 1; i < n; i++)
        if (a[i] == a[i - 1])
            ans2 = a[i];
        else if (a[i] >= a[i - 1] + 2)
            ans1 = a[i] - 1;
    cout << ans1 << ' ' << ans2 << endl;
    return 0;
}