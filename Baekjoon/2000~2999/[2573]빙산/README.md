# [빙산](https://www.acmicpc.net/problem/2573)

<div align = center>

| 시간 제한 | 메모리 제한 | 제출  | 정답  | 맞은 사람 | 정답 비율 |
| :-------: | :---------: | :---: | :---: | :-------: | :-------: |
|   1 초    |   256 MB    | 52628 | 14808 |   9834    |  25.754%  |

</div>

### 문제

지구 온난화로 인하여 북극의 빙산이 녹고 있다. 빙산을 그림 1과 같이 2차원 배열에 표시한다고 하자. 빙산의 각 부분별 높이 정보는 배열의 각 칸에 양의 정수로 저장된다. 빙산 이외의 바다에 해당되는 칸에는 0이 저장된다. 그림 1에서 빈칸은 모두 0으로 채워져 있다고 생각한다.

<div align=center>
  <table>
    <tr>
      <td align=center></td>
      <td align=center></td>
      <td align=center></td>
      <td align=center></td>
      <td align=center></td>
      <td align=center></td>
      <td align=center></td>
    </tr>
    <tr>
      <td align=center></td>
      <td align=center>2</td>
      <td align=center>4</td>
      <td align=center>5</td>
      <td align=center>3</td>
      <td align=center></td>
      <td align=center></td>
    </tr>
    <tr>
      <td align=center></td>
      <td align=center>3</td>
      <td align=center></td>
      <td align=center>2</td>
      <td align=center>5</td>
      <td align=center>2</td>
      <td align=center></td>
    </tr>
    <tr>
      <td align=center></td>
      <td align=center>7</td>
      <td align=center>6</td>
      <td align=center>2</td>
      <td align=center>4</td>
      <td align=center></td>
      <td align=center></td>
    </tr>
    <tr>
      <td align=center></td>
      <td align=center></td>
      <td align=center></td>
      <td align=center></td>
      <td align=center></td>
      <td align=center></td>
      <td align=center></td>
    </tr>
  </table>

그림 1. 행의 개수가 5이고 열의 개수가 7인 2차원 배열에 저장된 빙산의 높이 정보

</div>

빙산의 높이는 바닷물에 많이 접해있는 부분에서 더 빨리 줄어들기 때문에, 배열에서 빙산의 각 부분에 해당되는 칸에 있는 높이는 일년마다 그 칸에 동서남북 네 방향으로 붙어있는 0이 저장된 칸의 개수만큼 줄어든다. 단, 각 칸에 저장된 높이는 0보다 더 줄어들지 않는다. 바닷물은 호수처럼 빙산에 둘러싸여 있을 수도 있다. 따라서 그림 1의 빙산은 일년후에 그림 2와 같이 변형된다.

그림 3은 그림 1의 빙산이 2년 후에 변한 모습을 보여준다. 2차원 배열에서 동서남북 방향으로 붙어있는 칸들은 서로 연결되어 있다고 말한다. 따라서 그림 2의 빙산은 한 덩어리이지만, 그림 3의 빙산은 세 덩어리로 분리되어 있다.

<div align=center>
  <table>
    <tr>
      <td align=center></td>
      <td align=center></td>
      <td align=center></td>
      <td align=center></td>
      <td align=center></td>
      <td align=center></td>
      <td align=center></td>
    </tr>
    <tr>
      <td align=center></td>
      <td align=center></td>
      <td align=center>2</td>
      <td align=center>4</td>
      <td align=center>1</td>
      <td align=center></td>
      <td align=center></td>
    </tr>
    <tr>
      <td align=center></td>
      <td align=center>1</td>
      <td align=center></td>
      <td align=center>1</td>
      <td align=center>5</td>
      <td align=center></td>
      <td align=center></td>
    </tr>
    <tr>
      <td align=center></td>
      <td align=center>5</td>
      <td align=center>4</td>
      <td align=center>1</td>
      <td align=center>2</td>
      <td align=center></td>
      <td align=center></td>
    </tr>
    <tr>
      <td align=center></td>
      <td align=center></td>
      <td align=center></td>
      <td align=center></td>
      <td align=center></td>
      <td align=center></td>
      <td align=center></td>
    </tr>
  </table>

그림 2

</div>

<div align=center>
  <table>
    <tr>
      <td align=center></td>
      <td align=center></td>
      <td align=center></td>
      <td align=center></td>
      <td align=center></td>
      <td align=center></td>
      <td align=center></td>
    </tr>
    <tr>
      <td align=center></td>
      <td align=center></td>
      <td align=center></td>
      <td align=center>3</td>
      <td align=center></td>
      <td align=center></td>
      <td align=center></td>
    </tr>
    <tr>
      <td align=center></td>
      <td align=center></td>
      <td align=center></td>
      <td align=center></td>
      <td align=center>4</td>
      <td align=center></td>
      <td align=center></td>
    </tr>
    <tr>
      <td align=center></td>
      <td align=center></td>
      <td align=center>3</td>
      <td align=center>2</td>
      <td align=center></td>
      <td align=center></td>
      <td align=center></td>
    </tr>
    <tr>
      <td align=center></td>
      <td align=center></td>
      <td align=center></td>
      <td align=center></td>
      <td align=center></td>
      <td align=center></td>
      <td align=center></td>
    </tr>
  </table>

그림 3

</div>

한 덩어리의 빙산이 주어질 때, 이 빙산이 두 덩어리 이상으로 분리되는 최초의 시간(년)을 구하는 프로그램을 작성하시오. 그림 1의 빙산에 대해서는 2가 답이다. 만일 전부 다 녹을 때까지 두 덩어리 이상으로 분리되지 않으면 프로그램은 0을 출력한다.

---

### 입력

첫 줄에는 이차원 배열의 행의 개수와 열의 개수를 나타내는 두 정수 N과 M이 한 개의 빈칸을 사이에 두고 주어진다. N과 M은 3 이상 300 이하이다. 그 다음 N개의 줄에는 각 줄마다 배열의 각 행을 나타내는 M개의 정수가 한 개의 빈 칸을 사이에 두고 주어진다. 각 칸에 들어가는 값은 0 이상 10 이하이다. 배열에서 빙산이 차지하는 칸의 개수, 즉, 1 이상의 정수가 들어가는 칸의 개수는 10,000 개 이하이다. 배열의 첫 번째 행과 열, 마지막 행과 열에는 항상 0으로 채워진다.

---

### 출력

첫 줄에 빙산이 분리되는 최초의 시간(년)을 출력한다. 만일 빙산이 다 녹을 때까지 분리되지 않으면 0을 출력한다.

---

### 예제 입력

| 예제 입력1                                                                                    | 예제 출력1 |
| :-------------------------------------------------------------------------------------------- | :--------- |
| 5 7<br/>0 0 0 0 0 0 0<br/>0 2 4 5 3 0 0<br/>0 3 0 2 5 2 0<br/>0 7 6 2 4 0 0<br/>0 0 0 0 0 0 0 | 2          |

---

### 문제 접근

- `BFS` 및 구현 문제

- 빙산의 정보를 입력받은 후 라벨링 수행

- 라벨링 된 cluster의 개수가 0개이거나 2개 이상인 경우, break

  - break 시 cluster의 개수가 0개인 경우 반환값은 0

  - cluster의 개수가 2개 이상인 경우 반환값은 그때까지 count 된 year 값

- break가 되지 않는 경우, 주어진 문제 조건에 따라 빙산을 녹임

  - 빙산을 녹일 때, `board`를 참조하여 빙산을 녹이되, 다음 좌표 참조 시 이미 녹은 지점을 참조하지 않도록 `copyBoard`를 만들어 진행

  - `N * M` 만큼 순회가 완료되면 기존 board에 copyBoard 복사
