# 정수 내림차순으로 배치하기 - 연습문제

### 문제 설명

함수 solution은 정수 n을 매개변수로 입력받습니다. n의 각 자릿수를 큰것부터 작은 순으로 정렬한 새로운 정수를 리턴해주세요. 예를들어 n이 118372면 873211을 리턴하면 됩니다.

---

### 제한 조건

  - `n`은 1이상 8000000000 이하인 자연수입니다.

---

### 입출력 예

|   n    | return |
| :----: | :----: |
| 118372 | 873211 |

---

### 접근 방식

  - 주어진 수 `n`을 `string`으로 변환
    - `<string>`의 `to_string(n)` 이용
    - ```cpp
      string to_string (int num);
      string to_string (long num);
      string to_string (long long num);
      string to_string (unsigned num);
      string to_string (unsigned long num);
      string to_string (unsigned long long num);
      string to_string (float num);
      string to_string (double num);
      string to_string (long double num);
      ```

  - 변한된 `string`을 sorting

    - `<algorithm>`

    - ```cpp
      void sort(RandomIt start, RandomIt end, greater<>());
      ```

  - sorting된 `string`을 다시 `long long`으로 변환

    - `<string>` c++11에서 추가됨 

    - ```cpp
      int stoi(const string& str);
      float stof(const string& str);
      long stol(const string& str);
      double stod(const string& str);
      unsigned int stoul(const string& str);
      long long stoll(const string& str);
      unsigned long long stoull(const string& str);
      long double stold(const string& str);
      ```

