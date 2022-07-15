while(True):
    N = int(input())

    if N == 0:
        break

    words = [[]for i in range(N)]

    for i in range(N):
        input_str = input()

        words[i].append(input_str.upper())
        words[i].append(input_str)

    words.sort(key=lambda x: x[0])

    print(words[0][1])
