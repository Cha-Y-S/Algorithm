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

  - 주어진 `n`에 따라 2차원 배열에서 가지는 가장 큰 값을 산출

    ```cpp
    for(int i = 0 ; i < n; i++){
      max += i + 1;
    }
    ```

  - `x`와 `y`를 선언한 후, 2차원 배열에 차례대로 값을 채워넣음

    - 1)&nbsp;수직방향으로 값을 채워넣음

    - 2)&nbsp;수평방향으로 값을 채워넣음

    - 3)&nbsp;대각선방향으로 값을 채워넣음

    - 각 단계별 반복마다 `x`와 `y`의 값이 배열 scope를 벗어나는지 검사

    - 새로 채워넣어야 할 위치에 이미 값이 존재하는지도 검사

    - 각 step이 끝날 때 마다 `x`와 `y`를 조정하여 새로 값을 채워야할 location 설정