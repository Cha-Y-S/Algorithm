# [Tow Dots](https://www.acmicpc.net/problem/16929)

<div align = center>

| 시간 제한 | 메모리 제한 | 제출  | 정답  | 맞은 사람 | 정답 비율 |
| :-------: | :---------: | :---: | :---: | :-------: | :-------: |
|   2 초    |   512 MB    | 4506  | 2045  |   1319    |  42.686%  |

</div>

### 문제

[Two Dots](https://www.dots.co/twodots/)는 Playdots, Inc.에서 만든 게임이다. 게임의 기초 단계는 크기가 N×M인 게임판 위에서 진행된다.

<div align = center>
  <img src="https://upload.acmicpc.net/6a0e30d5-c325-40e4-b8b2-e5878b8dbc49/-/preview/" width = "320" heigth = "693" />
</div>

각각의 칸은 색이 칠해진 공이 하나씩 있다. 이 게임의 핵심은 같은 색으로 이루어진 사이클을 찾는 것이다.

다음은 위의 게임판에서 만들 수 있는 사이클의 예시이다.

<table style="width=100%;">
  <tr>
    <td style="width=50%;"><img src="https://upload.acmicpc.net/33712230-43d5-45f7-8b2d-dcb21b9c602c/-/preview/" width = "320" height = "693" /></td>
    <td style="width=50%;"><img src="https://upload.acmicpc.net/93730ab5-3ecf-4553-a411-50c22aa1e413/-/preview/" width = "320" height = "693" /></td>
  </tr>
</table>

점 k개 d<sub>1</sub>, d<sub>2</sub>, ..., d<sub>k</sub>로 이루어진 사이클의 정의는 아래와 같다.

  - 모든 k개의 점은 서로 다르다. 

  - k는 4보다 크거나 같다.

  - 모든 점의 색은 같다.

  - 모든 1 ≤ i ≤ k-1에 대해서, d<sub>i</sub>와 d<sub>i+1</sub>은 인접하다. 또, d<sub>k</sub>와 d<sub>1</sub>도 인접해야 한다. 두 점이 인접하다는 것은 각각의 점이 들어있는 칸이 변을 공유한다는 의미이다.

게임판의 상태가 주어졌을 때, 사이클이 존재하는지 아닌지 구해보자.

---

### 입력

첫째 줄에 게임판의 크기 N, M이 주어진다. 둘째 줄부터 N개의 줄에 게임판의 상태가 주어진다. 게임판은 모두 점으로 가득차 있고, 게임판의 상태는 점의 색을 의미한다. 점의 색은 알파벳 대문자 한 글자이다.

---

### 출력

사이클이 존재하는 경우에는 "Yes", 없는 경우에는 "No"를 출력한다.

---

### 예제 입력

| 예제 입력1                     | 예제 출력1 |
| :----------------------------- | :--------- |
| 3 4<br/>AAAA<br/>ABCA<br/>AAAA | Yes        |

| 예제 입력2                     | 예제 출력2 |
| :----------------------------- | :--------- |
| 3 4<br/>AAAA<br/>ABCA<br/>AADA | No         |

| 예제 입력3                              | 예제 출력3 |
| :-------------------------------------- | :--------- |
| 4 4<br/>YYYR<br/>BYBY<br/>BBBY<br/>BBBY | Yes        |

| 예제 입력4                                                                       | 예제 출력4 |
| :------------------------------------------------------------------------------- | :--------- |
| 7 6<br/>AAAAAB<br/>ABBBAB<br/>ABAAAB<br/>ABABBB<br/>ABAAAB<br/>ABBBAB<br/>AAAAAB | Yes        |

| 예제 입력5                               | 예제 출력5 |
| :--------------------------------------- | :--------- |
| 2 13<br/>ABCDEFGHIJKLM<br/>NOPQRSTUVWXYZ | No         |

---

### 문제 접근

  - `DFS` 이용, 그래프 내의 사이클 검사

  - 방문하지 않은 정점에 대해 main에서 `DFS`를 호출하며, 이 때 `DFS`가 호출된 후 해당 정점은 visited를 `true`로 초기화

  - `DFS`를 수행 시 4방위의 값들이 같은 값인지 검사하고, `DFS` 수행

    - main에서 호출될 때 받은 시작 정점과 현재 정점을 인자로 받음

    - `DFS`수행 중 시작 정점과 현재 정점이 같고, `cnt`가 4 이상인 경우 cycle이 생성된 것

      - 해당 문제에서 cycle이 생성되기위한 조건은 edge가 4 이상이어야 함