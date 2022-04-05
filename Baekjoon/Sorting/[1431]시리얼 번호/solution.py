N = int(input())
words = ["" for i in range(N)]

for i in range(N):
    words[i] = input()


def sum_number(x):
    result = 0
    for c in x:
        if c.isdigit():
            result += int(c)
    return result


words.sort(key=lambda x: (len(x), sum_number(x), x))

for word in words:
    print(word)
