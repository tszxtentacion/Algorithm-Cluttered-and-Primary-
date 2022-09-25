n = int(input())
s = list(map(int, input().strip().split()))

f = [[-1e9 for j in range(n+1)] for i in range(3)]
f[0][0] = 0

for i in range(1, n + 1):
    f[0][i] = max(f[0][i-1], f[2][i-1])
    f[1][i] = max(f[0][i-1] - s[i-1], f[1][i-1])
    f[2][i] = f[1][i-1] + s[i-1]

ans = 0
for j in range(1, n + 1):
    ans = max(ans, max(f[0][j], f[1][j], f[2][j]))

print(ans)
