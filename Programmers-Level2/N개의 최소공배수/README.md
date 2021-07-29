# [N개의 최소공배수](https://programmers.co.kr/learn/courses/30/lessons/12953) - 연습문제

### 문제 설명

두 수의 최소공배수(Least Common Multiple)란 입력된 두 수의 배수 중 공통이 되는 가장 작은 숫자를 의미합니다. 예를 들어 2와 7의 최소공배수는 14가 됩니다. 정의를 확장해서, n개의 수의 최소공배수는 n 개의 수들의 배수 중 공통이 되는 가장 작은 숫자가 됩니다. n개의 숫자를 담은 배열 arr이 입력되었을 때 이 수들의 최소공배수를 반환하는 함수, solution을 완성해 주세요.

---

### 제한사항

  - arr은 길이 1이상, 15이하인 배열입니다.

  - arr의 원소는 100 이하인 자연수입니다.

---

### 입출력 예

|    arr     | result |
| :--------: | :----: |
| [2,6,8,14] |  168   |
|  [1,2,3]   |   6    |

---

### 문제 접근

  - 두 수의 최대공약수

    `a % b == 0 ? b : gcd(b, a % b);`
  
  - 두 수의 최소공배수

    `a * b / gcd(a, b)`

  - 세 개 이상의 수의 최소 공배수
  - 
    ```cpp
    l = a * b / gcd(a, b);
    lcm = l * c / gcd(l, c);    
    ```

---

### 다른 사람의 풀이

```cpp
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int gcd(int x, int y) { return x % y == 0 ? y : gcd(y, x % y); }
int lcm(int x, int y) { return x * y / gcd(x, y); }
int solution(vector<int> arr) {
    int answer = arr[0];
    for (int i = 1; i < arr.size(); i++)
        answer = lcm(answer, arr[i]);
    return answer;
}
```
