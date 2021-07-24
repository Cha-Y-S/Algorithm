# [구명보트](https://programmers.co.kr/learn/courses/30/lessons/42885) - 탐욕법(Greedy)

### 문제 설명

무인도에 갇힌 사람들을 구명보트를 이용하여 구출하려고 합니다. 구명보트는 작아서 한 번에 최대 2명씩 밖에 탈 수 없고, 무게 제한도 있습니다.

예를 들어, 사람들의 몸무게가 [70kg, 50kg, 80kg, 50kg]이고 구명보트의 무게 제한이 100kg이라면 2번째 사람과 4번째 사람은 같이 탈 수 있지만 1번째 사람과 3번째 사람의 무게의 합은 150kg이므로 구명보트의 무게 제한을 초과하여 같이 탈 수 없습니다.

구명보트를 최대한 적게 사용하여 모든 사람을 구출하려고 합니다.

사람들의 몸무게를 담은 배열 people과 구명보트의 무게 제한 limit가 매개변수로 주어질 때, 모든 사람을 구출하기 위해 필요한 구명보트 개수의 최솟값을 return 하도록 solution 함수를 작성해주세요.

---

### 제한사항

  - 무인도에 갇힌 사람은 1명 이상 50,000명 이하입니다.

  - 각 사람의 몸무게는 40kg 이상 240kg 이하입니다.

  - 구명보트의 무게 제한은 40kg 이상 240kg 이하입니다.

  - 구명보트의 무게 제한은 항상 사람들의 몸무게 중 최댓값보다 크게 주어지므로 사람들을 구출할 수 없는 경우는 없습니다.

---

### 입출력 예

|      people      | limit | return |
| :--------------: | :---: | :----: |
| [70, 50, 80, 50] |  100  |   3    |
|   [70, 80, 50]   |  100  |   3    |

---

### 문제 접근

  - `progresses`가 empty가 될 때까지 반복 수행

  - 각 `progresses` 인덱스에 맞는 `speeds`를 더함

    - `progresses` 각 원소가 가질 수 있는 최댓값은 100으로 고정

  - `progresses` 가장 앞 원소가 100인 경우 맨 앞 원소를 제거하며, 그 다음 원소값 또한 100인 경우 100이 아니거나 `progresse`가 empty가 아닐 때 까지 수행하며 제거된 원소의 개수를 카운트함

  - 한 루프에서 원소가 제거된 경우 제거된 원소의 개수를 push_back

---

### [다른사람의 풀이]

  ```cpp
  vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;

    int day;
    int max_day = 0;
    for (int i = 0; i < progresses.size(); ++i)
    {
        day = (99 - progresses[i]) / speeds[i] + 1;

        if (answer.empty() || max_day < day)
            answer.push_back(1);
        else
            ++answer.back();

        if (max_day < day)
            max_day = day;
    }

    return answer;
  }
  ```

  - `++answer.back()`: 마지막 원소를 1 증가시킴