# [2 x n 타일링](https://programmers.co.kr/learn/courses/30/lessons/12900) - 연습문제

### 문제 설명

가로 길이가 2이고 세로의 길이가 1인 직사각형모양의 타일이 있습니다. 이 직사각형 타일을 이용하여 세로의 길이가 2이고 가로의 길이가 n인 바닥을 가득 채우려고 합니다. 타일을 채울 때는 다음과 같이 2가지 방법이 있습니다.

타일을 가로로 배치 하는 경우
타일을 세로로 배치 하는 경우
예를들어서 n이 7인 직사각형은 다음과 같이 채울 수 있습니다.

![Imgur](https://i.imgur.com/29ANX0f.png)

직사각형의 가로의 길이 n이 매개변수로 주어질 때, 이 직사각형을 채우는 방법의 수를 return 하는 solution 함수를 완성해주세요.

---

### 제한사항

  - 가로의 길이 n은 60,000이하의 자연수 입니다.

  - 경우의 수가 많아 질 수 있으므로, 경우의 수를 1,000,000,007으로 나눈 나머지를 return해주세요.

---

### 입출력 예

| n    | result |
| :--- | :----- |
| 4    | 5      |

---

### 입출력 예 설명

#### 입출력 예 #1

다음과 같이 5가지 방법이 있다.

![Imgur](https://i.imgur.com/keiKrD3.png)

![Imgur](https://i.imgur.com/O9GdTE0.png)

![Imgur](https://i.imgur.com/IZBmc6M.png)

![Imgur](https://i.imgur.com/29LWVzK.png)

![Imgur](https://i.imgur.com/z64JbNf.png)

---

### 문제 접근

  - `Dynamic Programming` 문제

  - 점화식: a<sub>i</sub> = a<sub>i-1</sub> + a<sub>i-2</sub>, i ≥ 2, a<sub>1</sub> = 1, a<sub>2</sub> = 2

  - 모듈러 연산의 법칙

    - 모듈러 연산은 제수(나누는 수)가 소수일 때, `+`, `*`에 대해 교환법칙과 분배법칙이 성립함

    - `(a + b) % c` = `((a % c) + (b % c)) % c`

  - 제수가 `1,000,000,007`이므로 모듈러 연산의 결과값은 최대 `1,000,000,006`

  - 모듈러 연산의 최대 결과값 두 개를 더해도 `int`형의 범위를 넘지 않으므로 `dp`벡터는 `int`형이어도 문제 없음