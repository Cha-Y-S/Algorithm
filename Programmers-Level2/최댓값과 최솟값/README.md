# 최댓값과 최솟값 - 연습문제

### 문제 설명

문자열 s에는 공백으로 구분된 숫자들이 저장되어 있습니다. str에 나타나는 숫자 중 최소값과 최대값을 찾아 이를 "(최소값) (최대값)"형태의 문자열을 반환하는 함수, solution을 완성하세요.
예를들어 s가 "1 2 3 4"라면 "1 4"를 리턴하고, "-1 -2 -3 -4"라면 "-4 -1"을 리턴하면 됩니다.

---

### 제한사항

  - s에는 둘 이상의 정수가 공백으로 구분되어 있습니다.

---

### 입출력 예

|       s       | return  |
| :-----------: | :-----: |
|   "1 2 3 4"   |  "1 4"  |
| "-1 -2 -3 -4" | "-4 -1" |
|    "-1 -1"    | "-1 -1" |

---

### 문제 접근

  - 문자열처리는 C++의 스트링 스트림 사용

    ```cpp
    #include <sstream>
    #include <string>

    string s = "1 2 3 4"
    stringstream st;

    st.str(s);  // string stream에 문자열 s를 입력함

    while(!s.eof()){  // File input stream과 같이 eof 사용 가능
      ...
    }

    while(s >> num){  // 다른 stream 처리와 같이 num에 입력 가능할 때까지 반복 수행
      ...
    }
    ```

  - 최대, 최소 비교를 위한 `vector<int> numbers` 선언

    - `<algorithm>`의 `min_element`와 `max_element`이용, 최대, 최소값을 구함

    ```cpp
    #include <algorithm>
    #include <vector>

    vector<int> numbers = {1, 2, 3, 4};

    min = *min_element(numbers.begin(), numbers.end());
    max = *max_element(numbers.begin(), numbers.end());
    ```

    - `min_element`와 `max_element`는 배열 또는 벡터 중 최대, 최솟값을 찾아줌

    - 최댓값이나 최솟값이 여러 개로 중복되는 경우 가장 먼저 등장하는 최대, 최솟값의 `Iterator` 반환

    - 값을 얻어내기 위해 `*`연산자 사용