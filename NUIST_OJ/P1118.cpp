#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
const int N = 16;
int T;
int main()
{
    cin >> T;
    while (T--)
    {
        string s;
        cin >> s;
        char target = s[12];
        int ans = 0;
        int arr[N];
        // Êý×Ö»¯
        for (int i = 0; i < s.length(); i++)
            arr[i] = s[i] - '0';

        int sum = arr[0] * 1 + arr[2] * 2 + arr[3] * 3 + arr[4] * 4 + arr[6] * 5 + arr[7] * 6 + arr[8] * 7 + arr[9] * 8 + arr[10] * 9;
        ans += sum % 11;
        if (ans < 10)
        {
            if (ans == arr[12])
                cout << "Right" << endl;
            else
            {
                for (int i = 0; i < s.length() - 1; i++)
                    cout << s[i];
                cout << ans << endl;
            }
        }
        else
        {
            if (s[12] == 'X')
                cout << "Right" << endl;
            else
            {
                for (int i = 0; i < s.length() - 1; i++)
                    cout << s[i];
                cout << ans << endl;
            }
        }
    }
    return 0;
}