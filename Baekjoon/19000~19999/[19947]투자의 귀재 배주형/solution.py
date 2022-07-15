def getBenefitA(x):
    return int(x * 1.05)


def getBenefitB(x):
    return int(x * 1.2)


def getBenefitC(x):
    return int(x * 1.35)


if __name__ == '__main__':
    H, Y = map(int, input().split())
    dp = [H for i in range(Y + 1)]

    for i in range(1, Y + 1):
        if (i >= 5):
            dp[i] = max(getBenefitA(dp[i-1]),
                        max(getBenefitB(dp[i-3]), getBenefitC(dp[i-5])))
        elif (i >= 3):
            dp[i] = max(getBenefitA(dp[i-1]), getBenefitB(dp[i - 3]))
        else:
            dp[i] = getBenefitA(dp[i-1])

    print(dp[Y])
