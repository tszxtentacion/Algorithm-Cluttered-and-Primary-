N, V, M = map(int, input().strip().split())     # 容积，承重
v, m, w = [0], [0], [0]     # 体积，重量，价值
for i in range(1, N + 1):
    a, b, c = map(int, input().strip().split())
    v.append(a)
    m.append(b)
    w.append(c)
# f[j][k]: 已用容积，承重
f = [[0 for i in range(1003)] for j in range(1003)]
# f[j][k] = (f[j][k], f[j-v[i]][k-m[i]] + w[i])
for i in range(N):
    for j in range(V, v[i]-1, -1):
        for k in range(M, m[i]-1, -1):
            f[j][k] = max(f[j][k], f[j-v[i]][k-m[i]] + w[i])

print(f[V][M])



