while True:
    try:
        N = int(input())
        s = set()

        for i in range(N):
            num = input()
            tmp = 0

            for c in num:
                tmp |= 1 << (ord(c) - ord('1'))

            s.add(tmp)

        print(len(s))

    except:
        break
