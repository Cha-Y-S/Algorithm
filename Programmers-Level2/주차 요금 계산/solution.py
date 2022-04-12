from math import ceil


def solution(fees, records):
    answer = []
    enter = {}
    parking = {}

    for i in range(len(records)):
        t, n, info = records[i].split()
        hour, minute = int(t[0:2]), int(t[3:])

        if info == "IN":
            enter[n] = hour * 60 + minute
        else:
            if n in parking:
                parking[n] += (hour * 60 + minute) - enter[n]
            else:
                parking[n] = (hour * 60 + minute) - enter[n]
            enter.pop(n)

    for n, t in enter.items():
        if n in parking:
            parking[n] += (23 * 60 + 59) - enter[n]
        else:
            parking[n] = (23 * 60 + 59) - enter[n]

    parking = sorted(parking.items())

    for n, t in parking:
        fee = 0

        if t < fees[0]:
            fee = fees[1]
        else:
            fee = fees[1] + ceil((t - fees[0]) / fees[2]) * fees[3]

        answer.append(fee)

    return answer
