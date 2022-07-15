from audioop import reverse


T = int(input())

for t in range(T):
    J, N = map(int, input().split())

    boxes = [0 for i in range(N)]
    res = 0

    for i in range(N):
        R, C = map(int, input().split())

        boxes[i] = R * C

    boxes.sort(reverse=True)

    for i in range(N):
        J -= boxes[i]
        res += 1

        if(J <= 0):
            break

    print(res)
