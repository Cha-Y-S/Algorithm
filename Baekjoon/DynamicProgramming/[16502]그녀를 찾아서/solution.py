t = int(input())
M = int(input())

graph = [[] for i in range(4)]
dp = [[0 for i in range(t + 1)] for i in range(4)]

dp[0][0] = dp[1][0] = dp[2][0] = dp[3][0] = 0.25

for i in range(M):
    s, e, prob = map(str, input().split())

    graph[ord(s) - ord('A')].append([ord(e)-ord('A'), float(prob)])

for k in range(t):
    for i in range(len(graph)):
        for v, p in graph[i]:
            dp[v][k + 1] += dp[i][k] * p

for i in range(4):
    print("%.2f" % (dp[i][t]*100))
