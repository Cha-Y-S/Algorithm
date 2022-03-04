N = int(input())
MAX = 1001

dp = [0 for i in range(MAX)]

dp[1] = dp[3] = 0
dp[2] = dp[4] = 1

for i in range(5, N + 1):
    if(min({dp[i-1], dp[i-3], dp[i-4]}) == 1):
        dp[i] = 0
    else:
        dp[i] = 1

print("SK" if dp[N] == 1 else "CY")
