# [방문 길이](https://programmers.co.kr/learn/courses/30/lessons/49994) - Summer/Winter Coding(~2018)

### 문제 설명

게임 캐릭터를 4가지 명령어를 통해 움직이려 합니다. 명령어는 다음과 같습니다.

  - U: 위쪽으로 한 칸 가기

  - D: 아래쪽으로 한 칸 가기

  - R: 오른쪽으로 한 칸 가기

  - L: 왼쪽으로 한 칸 가기

캐릭터는 좌표평면의 (0, 0) 위치에서 시작합니다. 좌표평면의 경계는 왼쪽 위(-5, 5), 왼쪽 아래(-5, -5), 오른쪽 위(5, 5), 오른쪽 아래(5, -5)로 이루어져 있습니다.

![Image](https://grepp-programmers.s3.ap-northeast-2.amazonaws.com/files/production/ace0e7bc-9092-4b95-9bfb-3a55a2aa780e/%E1%84%87%E1%85%A1%E1%86%BC%E1%84%86%E1%85%AE%E1%86%AB%E1%84%80%E1%85%B5%E1%86%AF%E1%84%8B%E1%85%B51_qpp9l3.png)

예를 들어, "ULURRDLLU"로 명령했다면

![Image](https://grepp-programmers.s3.ap-northeast-2.amazonaws.com/files/production/668c7458-e184-472d-9d32-f5d2acca759a/%E1%84%87%E1%85%A1%E1%86%BC%E1%84%86%E1%85%AE%E1%86%AB%E1%84%80%E1%85%B5%E1%86%AF%E1%84%8B%E1%85%B52_lezmdo.png)

  - 1번 명령어부터 7번 명령어까지 다음과 같이 움직입니다.

![Image](https://grepp-programmers.s3.ap-northeast-2.amazonaws.com/files/production/08558e36-d667-4160-bfec-b754c78a7d85/%E1%84%87%E1%85%A1%E1%86%BC%E1%84%86%E1%85%AE%E1%86%AB%E1%84%80%E1%85%B5%E1%86%AF%E1%84%8B%E1%85%B53_sootjd.png)

  - 8번 명령어부터 9번 명령어까지 다음과 같이 움직입니다.

![Image](https://grepp-programmers.s3.ap-northeast-2.amazonaws.com/files/production/a52af28e-5835-438b-9f40-5467ebf9bf03/%E1%84%87%E1%85%A1%E1%86%BC%E1%84%86%E1%85%AE%E1%86%AB%E1%84%80%E1%85%B5%E1%86%AF%E1%84%8B%E1%85%B54_hlpiej.png)

이때, 우리는 게임 캐릭터가 지나간 길 중 **캐릭터가 처음 걸어본 길의 길이**를 구하려고 합니다. 예를 들어 위의 예시에서 게임 캐릭터가 움직인 길이는 9이지만, 캐릭터가 처음 걸어본 길의 길이는 7이 됩니다. (8, 9번 명령어에서 움직인 길은 2, 3번 명령어에서 이미 거쳐 간 길입니다)

단, 좌표평면의 경계를 넘어가는 명령어는 무시합니다.

예를 들어, "LULLLLLLU"로 명령했다면

![Image](https://grepp-programmers.s3.ap-northeast-2.amazonaws.com/files/production/f631f005-f8de-4392-a76c-a9ef64b6de08/%E1%84%87%E1%85%A1%E1%86%BC%E1%84%86%E1%85%AE%E1%86%AB%E1%84%80%E1%85%B5%E1%86%AF%E1%84%8B%E1%85%B55_nitjwj.png)

  - 1번 명령어부터 6번 명령어대로 움직인 후, 7, 8번 명령어는 무시합니다. 다시 9번 명령어대로 움직입니다.

![Image](https://grepp-programmers.s3.ap-northeast-2.amazonaws.com/files/production/35e62f0a-43c6-4142-bec6-6d28fbc57216/%E1%84%87%E1%85%A1%E1%86%BC%E1%84%86%E1%85%AE%E1%86%AB%E1%84%80%E1%85%B5%E1%86%AF%E1%84%8B%E1%85%B56_nzhumd.png)

이때 캐릭터가 처음 걸어본 길의 길이는 7이 됩니다.

명령어가 매개변수 dirs로 주어질 때, 게임 캐릭터가 처음 걸어본 길의 길이를 구하여 return 하는 solution 함수를 완성해 주세요.

---

### 제한사항

  - dirs는 string형으로 주어지며, 'U', 'D', 'R', 'L' 이외에 문자는 주어지지 않습니다.

  - dirs의 길이는 500 이하의 자연수입니다.

---

### 입출력 예

|    dirs     | answer |
| :---------: | :----: |
| "ULURRDLLU" |   7    |
| "LULLLLLLU" |   7    |

---

### 입출력 예 설명

#### 입출력 예 #1

  - 문제의 예시와 같습니다.

#### 입출력 예 #2

  - 문제의 예시와 같습니다.

---

### 문제 접근

  - C++ STL `<map>`, `<set>` 사용

  - `map`에는 문제에서 주어지는 `U, D, R, L`에 대해 변경할 좌표값이 `U, D, R, L`을 `key`값으로 `pair`형태로 저장되어 있음
  
  - `set`은 중복된 값을 저장하지 않음

    - `current location -> new location`
    
    - `new location -> current location`
    
    - 해당 `path` 두 개를 저장해 두면, 한 가지 `path`에 대해 방향성이 없는 `path` 저장 가능

  - 첫 번째 시도

    ```cpp
    set<pair<pair<int, int>, pair<int, int>>>::iterator it = visited.find(road);

    // If the path is not in the set
    if (it == visited.end()) {
      visited.insert(road);
      road.first = new_loc;
      road.second = cur_loc;
      visited.insert(road);
      answer++;
    }
    ```

      - `set`에 경로가 이미 존재하는 지 확인 후, insert 하였음

      - but, `set`에 이미 값이 존재하는 경우, 중복을 제거하기 때문에 해당 과정 불필요

  - 발전시킨 코드

    ```cpp
    // Insert the path into visited set
    // If the path is already in the set, duplicate path will be removed
    visited.insert(road = {cur_loc, new_loc});
    visited.insert(road = {new_loc, cur_loc});
    ```

  - `set`에는 중복된 값이 저장되어 있지 않고, `set`에 insert 하기 전, 이미 이동이 불가능한 좌표에 대해선 예외 처리를 해주었으므로 답은 `size of set / 2`