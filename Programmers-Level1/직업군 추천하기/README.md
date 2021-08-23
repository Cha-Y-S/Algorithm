# [직업군 추천하기](https://programmers.co.kr/learn/courses/30/lessons/84325) - 위클리 챌린지 / 4주차

### 문제 설명

개발자가 사용하는 언어와 `언어 선호도`를 입력하면 그에 맞는 직업군을 추천해주는 알고리즘을 개발하려고 합니다.

아래 표는 5개 직업군 별로 많이 사용하는 5개 언어에 `직업군 언어 점수`를 부여한 표입니다.

| 점수 | SI         | CONTENTS   | HARDWARE   | PORTAL     | GAME       |
| :--- | :--------- | :--------- | :--------- | :--------- | :--------- |
| 5    | JAVA       | JAVASCRIPT | C          | JAVA       | C++        |
| 4    | JAVASCRIPT | JAVA       | C++        | JAVASCRIPT | C#         |
| 3    | SQL        | PYTHON     | PYTHON     | PYTHON     | JAVASCRIPT |
| 2    | PYTHON     | SQL        | JAVA       | KOTLIN     | C          |
| 1    | C#         | C++        | JAVASCRIPT | PHP        | JAVA       |

예를 들면, SQL의 SI `직업군 언어 점수`는 3점이지만 CONTENTS `직업군 언어 점수`는 2점입니다. SQL의 HARDWARE, PORTAL, GAME `직업군 언어 점수`는 0점입니다.

`직업군 언어 점수`를 정리한 문자열 배열 `table`, 개발자가 사용하는 언어를 담은 문자열 배열 `languages`, `언어 선호도`를 담은 정수 배열 `preference`가 매개변수로 주어집니다. 개발자가 사용하는 언어의 `언어 선호도` x `직업군 언어 점수`의 총합이 가장 높은 직업군을 return 하도록 solution 함수를 완성해주세요. 총합이 같은 직업군이 여러 개일 경우, 이름이 사전 순으로 가장 빠른 직업군을 return 해주세요.

---

### 제한사항

  - `table`의 길이 = 5

    - `table`의 원소는 `"직업군 5점언어 4점언어 3점언어 2점언어 1점언어"`형식의 문자열입니다. `직업군`, `5점언어`, `4언어`, `3점언어`, `2점언어`, `1점언어`는 하나의 공백으로 구분되어 있습니다.

    - `table`은 모든 테스트케이스에서 동일합니다.

  - 1 ≤ `languages`의 길이 ≤ 9

    - `languages`의 원소는 `"JAVA"`, `"JAVASCRIPT"`, `"C"`, `"C++"` ,`"C#"` , `"SQL"`, `"PYTHON"`, `"KOTLIN"`, `"PHP"` 중 한 개 이상으로 이루어져 있습니다.

    - `languages`의 원소는 중복되지 않습니다.

  - `preference`의 길이 = `languages`의 길이

    - 1 ≤ `preference`의 원소 ≤ 10

  - `preference`의 i번째 원소는 `languages`의 i번째 원소의 `언어 선호도`입니다.

  - return 할 문자열은 `"SI"`, `"CONTENTS"`, `"HARDWARE"`, `"PORTAL"`, `"GAME"` 중 하나입니다.

---

### 입출력 예

| table                                                                                                                                                                                                 | languages                | preference | result     |
| :---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- | :----------------------- | :--------- | :--------- |
| ["SI JAVA JAVASCRIPT SQL PYTHON C#", "CONTENTS JAVASCRIPT JAVA PYTHON SQL C++", "HARDWARE C C++ PYTHON JAVA JAVASCRIPT", "PORTAL JAVA JAVASCRIPT PYTHON KOTLIN PHP", "GAME C++ C# JAVASCRIPT C JAVA"] | ["PYTHON", "C++", "SQL"] | [7, 5, 5]  | "HARDWARE" |
| ["SI JAVA JAVASCRIPT SQL PYTHON C#", "CONTENTS JAVASCRIPT JAVA PYTHON SQL C++", "HARDWARE C C++ PYTHON JAVA JAVASCRIPT", "PORTAL JAVA JAVASCRIPT PYTHON KOTLIN PHP", "GAME C++ C# JAVASCRIPT C JAVA"] | ["JAVA", "JAVASCRIPT"]   | [7, 5]     | "PORTAL"   |

---

### 입출력 예 설명

#### 입출력 예 #1

각 직업군 별로 점수를 계산해보면 아래와 같습니다.

아래 사진은 `개발자 언어 선호도` 나타낸 표입니다.

![tc1_preference.PNG](https://grepp-programmers.s3.ap-northeast-2.amazonaws.com/files/production/9a711ad6-4a8e-4028-b100-0280a4e3a7dd/tc1_preference.PNG)

아래 사진은 개발자가 선호하는 언어의 `직업군 언어 점수`를 나타낸 표입니다.

![tc1_score.PNG](https://grepp-programmers.s3.ap-northeast-2.amazonaws.com/files/production/1ef5a88a-8109-415d-b611-a6320410b1e1/tc1_score.PNG)

따라서 점수 총합이 41로 가장 높은 `"HARDWARE"`를 return 해야 합니다.

#### 입출력 예 #2

각 직업군 별로 점수를 계산해보면 아래와 같습니다.

아래 사진은 `개발자 언어 선호도` 나타낸 표입니다.

![tc2_preference.PNG](https://grepp-programmers.s3.ap-northeast-2.amazonaws.com/files/production/e49d818b-938a-4cc3-8d2a-27783f2e1af5/tc2_preference.PNG)

아래 사진은 개발자가 선호하는 언어의 `직업군 언어 점수`를 나타낸 표입니다.

![tc2_score.PNG](https://grepp-programmers.s3.ap-northeast-2.amazonaws.com/files/production/0624156e-e1d3-4299-b554-470815322a79/tc2_score.PNG)

점수 총합이 55로 가장 높은 직업군은 "SI" 와 "PORTAL"입니다.<br/>
따라서 사전 순으로 먼저 오는 "PORTAL"을 return 해야 합니다.

---

### 문제 접근

  - 입력받은 `table`정보를 직업군별로 나눠 5개의 `map`으로 각 언어별 점수를 저장

    - 5개의 `map`은 벡터 컨테이너로 구현하였으며, 각 직업군별 인덱스를 고정하기 위해 모든 직업군을 저장하고 있는 `jobs` 벡터 추가

    - 직업군을 파싱하여 인덱스를 구한 경우, 언어 별로 점수를 매김

      ```cpp
      table_map[job_index][language] = point--;

      /*
      * job_index: 직업군을 통해 유추한 인덱스 값
      * language: 입력받은 언어
      * point: 언어별로 부여받는 점수로, 초기값은 5
      * /
      ```
  - `languages`와 `preference`는 `lang_pref`라는 `pair` 벡터를 만들어 해당 벡터에 저장하여 관리

  - 이후 `table_map`의 크기만큼 반복하며 `lang_pref`에 있는 언어 별로 점수를 뽑아, 해당 언어의 `개발자의 언어 선호도`와 곱한 후 합함

  - 최종 합이 기존 저장된 `max`값보다 큰 경우 `max`값과 `answer`를 갱신하며, 이때 `max`값과 같은 경우 사전순으로 먼저 오는 직업군으로 갱신

    ```cpp
    else if(max == sum){
      answer = jobs[i] < answer ? jobs[i] : answer;
    }
    ```