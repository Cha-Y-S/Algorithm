import sys

T = int(sys.stdin.readline())


def input_data():
    global A
    global B
    global C

    _ = int(sys.stdin.readline())

    A = set(map(int, sys.stdin.readline().split()))

    _ = int(sys.stdin.readline())

    B = set(map(int, sys.stdin.readline().split()))

    _ = int(sys.stdin.readline())

    C = set(map(int, sys.stdin.readline().split()))


def check_validity(number):
    result = True

    for n in number:
        if n != '5' and n != '8':
            result = False
            break

    return result


while(T > 0):
    input_data()

    lucky_number = set()

    for a in A:
        for b in B:
            for c in C:
                tmp = a + b + c

                if(check_validity(str(tmp))):
                    lucky_number.add(tmp)

    sys.stdout.write(str(len(lucky_number)) + "\n")

    T -= 1
