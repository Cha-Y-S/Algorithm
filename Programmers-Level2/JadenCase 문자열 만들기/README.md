# [JadenCase 문자열 만들기](https://programmers.co.kr/learn/courses/30/lessons/12951) - 연습문제

### 문제 설명

JadenCase란 모든 단어의 첫 문자가 대문자이고, 그 외의 알파벳은 소문자인 문자열입니다. 문자열 s가 주어졌을 때, s를 JadenCase로 바꾼 문자열을 리턴하는 함수, solution을 완성해주세요.

---

### 제한사항

  - s는 길이 1 이상인 문자열입니다.
  
  - s는 알파벳과 공백문자(" ")로 이루어져 있습니다.

  - 첫 문자가 영문이 아닐때에는 이어지는 영문은 소문자로 씁니다. ( 첫번째 입출력 예 참고 )

---

### 입출력 예

|            s            |         return          |
| :---------------------: | :---------------------: |
| "3people unFollowed me" | "3people Unfollowed Me" |
|   "for the last week"   |   "For The Last Week"   |

---

### 문제 접근

  - 주어진 문자열을 모두 소문자로 변환

  - 실패 사례

    - `<sstream>`을 이용해 `split` 이후 첫 문자만 대문자로 변환 시도

    - 단어 사이에 공백이 여러 개인 경우 처리 불가

  - 소문자로 변환된 문자열을 검사하면서 조건에 따라 대문자로 변환

    ```cpp
    if(s[i] == ' ' && i + 1 < s.size() && isalpha(s[i + 1]))
      // 1. 현재 문자가 공백
      // 2. 현재 문자 다음 인덱스가 문자열의 길이를 초과하지 않음
      // 3. 다음 문자가 알파벳인 경우
    ```

---

### 다른 사람의 풀이

```cpp
#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    string answer = "";

    answer += toupper(s[0]);
    for (int i = 1; i < s.size(); i++)
        s[i - 1] == ' ' ? answer += toupper(s[i]) : answer += tolower(s[i]);

    return answer;
}
```

  - 대/소문자로의 변환을 한번에 한 케이스

  - 여러 공백도 처리가 됨

  - `tolower`과 `toupper`는 알파벳이 아닌 경우 문자 그대로 다시 반환