#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
const int N = 1e8 + 10;
int sum[N];
int main()
{
    int n;
    cin >> n;
    for (int c = 0; c * c * 2 <= n; c++)
        for (int d = c; c * c + d * d <= n; d++)
        {
            if (!sum[c * c + d * d])
                sum[c * c + d * d] = c + 1; //防止0
        }
    for (int a = 0; a * a * 4 <= n; a++)
        for (int b = a; a * a + b * b <= n / 2; b++)
        {
            int sum_ = n - a * a - b * b;
            if (sum[sum_])
            {
                int c = sum[sum_] - 1;
                int d = sqrt(sum_ - c * c) + 1e-4;
                printf("%d %d %d %d\n", a, b, c, d);
                return 0;
            }
        }
    return 0;
}