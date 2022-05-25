import sys

N = sys.stdin.readline()


def mul17(n):
    left = n[:len(n) - 1] + "0000"
    right = "0000" + n
    result = ""

    carry = False
    for i in range(len(left) - 1, -1, -1):
        if left[i] == '0' and right[i] == '0':
            if carry:
                result = "1" + result
            else:
                result = "0" + result
            carry = False
        elif left[i] == '1' and right[i] == '1':
            if carry:
                result = "1" + result
            else:
                result = "0" + result
            carry = True
        else:
            if carry:
                result = "0" + result
                carry = True
            else:
                result = "1" + result
                carry = False

    result = "1" + result if carry else result

    return result


sys.stdout.write(mul17(N) + "\n")
