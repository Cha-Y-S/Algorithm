# 문자열 내 마음대로 정렬하기 - 연습문제

### 문제 설명

문자열로 구성된 리스트 strings와, 정수 n이 주어졌을 때, 각 문자열의 인덱스 n번째 글자를 기준으로 오름차순 정렬하려 합니다. 예를 들어 strings가 ["sun", "bed", "car"]이고 n이 1이면 각 단어의 인덱스 1의 문자 "u", "e", "a"로 strings를 정렬합니다.

---

### 제한 조건

  - strings는 길이 1 이상, 50이하인 배열입니다.

  - strings의 원소는 소문자 알파벳으로 이루어져 있습니다.

  - strings의 원소는 길이 1 이상, 100이하인 문자열입니다.

  - 모든 strings의 원소의 길이는 n보다 큽니다.

  - 인덱스 1의 문자가 같은 문자열이 여럿 일 경우, 사전순으로 앞선 문자열이 앞쪽에 위치합니다.

---

### 입출력 예

|         strings         |   n   |         return          |
| :---------------------: | :---: | :---------------------: |
|  ["sun", "bed", "car"]  |   1   |  ["car", "bed", "sun"]  |
| ["abce", "abcd", "cdx"] |   2   | ["abcd", "abce", "cdx"] |

---

### 입출력 예 설명

#### 입출력 예#1

"sun", "bed", "car"의 1번째 인덱스 값은 각각 "u", "e", "a" 입니다. 이를 기준으로 strings를 정렬하면 ["car", "bed", "sun"] 입니다.

#### 입출력 예#2

"abce"와 "abcd", "cdx"의 2번째 인덱스 값은 "c", "c", "x"입니다. 따라서 정렬 후에는 "cdx"가 가장 뒤에 위치합니다. "abce"와 "abcd"는 사전순으로 정렬하면 "abcd"가 우선하므로, 답은 ["abcd", "abce", "cdx"] 입니다.

---

### 접근 방식

  - `pair` 클래스 사용

    - `#include <utility>`

    - 두 객체를 하나의 객체로 취급할 수 있게 묶어주는 클래스

    - pair<[type1], [type2]> p : `type1`과 `type2`의 쌍으로 이루어지는 pair 클래스 p 선언

    - p.first: p의 첫번째 인자 반환(`type1`)

    - p.second: p의 두번째 인자 반환(`type2`)

    - make_pair(var1, var2): `var1`과 `var2`가 들어간 pair 클래스 생성

    - #### sort 알고리즘에 의해 정렬 가능
  
  - `sort` 함수 사용

    - `#include <algorithm>`

    - ```cpp
      void sort(RandomIt first, RandomIt last);
      void sort(RandomIt first, RandomIt last. Compare comp);
      ```
    
    - first, last: 정렬을 수행할 원소들의 범위를 가리키는 반복자

    - comp: 인자 두 개를 받는 비교 함수, 첫 번째 인자가 더 작을 경우 true 반환(오름차순 기준)

    - ``` cpp
      bool cmp(const Type1 &a, const Type2 &b);
      ```

    - 시간 복잡도 - O(n logn)

  - `pair<string, char>`을 선언 후 first에는 `strings`의 문자열이, second에는 first에서 `n` 인덱스에 해당하는 char 값이 들어감

  - `pair.second`를 기준으로 정렬하며, second 값이 같은 경우 first를 기준으로 정렬
  