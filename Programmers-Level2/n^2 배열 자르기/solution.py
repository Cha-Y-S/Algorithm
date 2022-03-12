def solution(n, left, right):
    answer = []

    for i in range(int(left), int(right + 1)):
        row = i // n
        col = i % n

        answer.append(row + 1 if row > col else col + 1)

    return answer
