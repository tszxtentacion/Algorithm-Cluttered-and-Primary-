#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int n;

int main()
{
    while (cin >> n)
    {
        if (n == 0)
            break;
        int num[104];
        memset(num, 0, sizeof num);
        int cnt = 0; // ¼ÇÂ¼Î»Êý
        for (int i = 0; n > 0; i++)
        {
            num[i] = n % 8;
            cnt++;
            n = n / 8;
        }
        for (int i = cnt - 1; i >= 0; i--)
            cout << num[i];
        cout << endl;
    }
    return 0;
}