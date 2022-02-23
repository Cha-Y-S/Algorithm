N = int(input())

arr = list(map(int, input().split()))

tmp1 = tmp2 = res = 1

for i in range(N - 1):
  if(arr[i] <= arr[i+1]):
    tmp1 += 1
  else:
    tmp1 = 1
  
  if(arr[i] >= arr[i+1]):
    tmp2 += 1
  else:
    tmp2 = 1

  result = max(tmp1, tmp2)
  res = max(result, res)

print(res)