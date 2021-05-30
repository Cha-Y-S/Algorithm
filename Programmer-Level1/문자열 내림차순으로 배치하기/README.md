# 문자열 내림차순으로 배치하기 - 연습문제

### 문제 설명

문자열 s에 나타나는 문자를 큰것부터 작은 순으로 정렬해 새로운 문자열을 리턴하는 함수, solution을 완성해주세요.
s는 영문 대소문자로만 구성되어 있으며, 대문자는 소문자보다 작은 것으로 간주합니다.

---

### 제한 조건

  - str은 길이 1 이상인 문자열입니다.

---

### 입출력 예

| s | return |
|:---:|:---:|
| "Zbcdefg" | "gfedbcZ" |

---

### 접근 방식

  - 소문자를 담는 string 객체 `lower`와 대문자를 담는 string 객체 `upper` 선언

  - `s`의 길이만큼 for문을 수행하며 소문자는 lower에, 대문자는 upper에 push

  - `lower`와 `upper` 각각 `sort` 수행

    - ```cpp
      void sort(RandomIt start, RandomIt last, greater<>());
      void sort(RandomIt start, RandomIt last, less<>());
      ```

    - greater<>(): 내림차순으로 sort를 수행할 수 있게 해주는 임시 객체

    - less<>(): 오름차순으로 sort를 수행할 수 있게 해주는 임시 객체(sort의 default 값)

  - `answer`는 정렬된 `lower`와 `upper`를 `+` 연산자를 이용해 초기화 시킴