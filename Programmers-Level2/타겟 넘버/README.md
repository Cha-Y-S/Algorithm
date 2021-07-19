# [타겟 넘버](https://programmers.co.kr/learn/courses/30/lessons/43165) - 깊이/너비 우선 탐색(DFS/BFS)

### 문제 설명

n개의 음이 아닌 정수가 있습니다. 이 수를 적절히 더하거나 빼서 타겟 넘버를 만들려고 합니다. 예를 들어 [1, 1, 1, 1, 1]로 숫자 3을 만들려면 다음 다섯 방법을 쓸 수 있습니다.

    -1+1+1+1+1 = 3
    +1-1+1+1+1 = 3
    +1+1-1+1+1 = 3
    +1+1+1-1+1 = 3
    +1+1+1+1-1 = 3

사용할 수 있는 숫자가 담긴 배열 numbers, 타겟 넘버 target이 매개변수로 주어질 때 숫자를 적절히 더하고 빼서 타겟 넘버를 만드는 방법의 수를 return 하도록 solution 함수를 작성해주세요.

---

### 제한사항

  - 주어지는 숫자의 개수는 2개 이상 20개 이하입니다.

  - 각 숫자는 1 이상 50 이하인 자연수입니다.

  - 타겟 넘버는 1 이상 1000 이하인 자연수입니다.

---

### 입출력 예

|     numbers     | target | return |
| :-------------: | :----: | :----: |
| [1, 1, 1, 1, 1] |   3    |   5    |

---

### 입출력 예 설명

문제에 나온 예와 같습니다.

---

### 문제 접근

  - `DFS/BFS`문제

  - 예시에서 첫 index 값을 더할 때(**target이 4개 만들어짐**)

![image](https://user-images.githubusercontent.com/24904962/126047123-8510be05-15a9-4fbf-a097-e340127b0e9c.png)

  - 예시에서 첫 index 값을 뺄 때(**target이 1개 만들어짐**)

![image](https://user-images.githubusercontent.com/24904962/126047157-f92c8a5f-1d5a-4cdb-89e7-2a3e52a01476.png)

  - 위 사진의 모든 노드를 탐색하며 연산한 후, 해당 값이 `target`과 같은 횟수를 카운트 해야하므로 `DFS/BFS`를 사용해 전 노드의 탐색 필요

  - 문제는 `BFS`를 활용해 해결했지만 `DFS`로도 접근해 볼 필요

    ```cpp
    int dfs(int prev, int index, vector<int> numbers, int target) {
      int result = 0;
      if (index == number.size()) {
        if (prev == target) {
          return 1;
        }
        return 0;
      }

      int cs1 = prev + numbers[index];
      int cs2 = prev - numbers[index];

      result += dfs(cs1, index + 1, numbers, target);
      result += dfs(cs2, index + 1, numbers, target);

      return result;
    }

    int solution(vector<int> numbers, int target) {
      int answer = 0;
      int cs = number[0];

      answer += dfs(cs, 1, numbers, target);
      answer += dfs(cs, 1, numbers, target);

      return answer;
    }
    ```

  - 전체 노드의 수는 2<sup>vector's size</sup>개로, 예시에서는 총 **2<sup>5</sup> == 32**개의 노드를 탐색함

    - 주어진 숫자 갯수의 최대값은 20이므로 해당 문제에서의 노드의 최대 개수는 **2<sup>20</sup> == 1M**개