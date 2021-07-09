# [토마토](https://www.acmicpc.net/problem/7576)

<div align = center>

| 시간 제한 | 메모리 제한 | 제출  | 정답  | 맞은 사람 | 정답 비율 |
| :-------: | :---------: | :---: | :---: | :-------: | :-------: |
|   1 초    |   256 MB    | 91856 | 31916 |   19921   |  33.432%  |

</div>

### 문제

철수의 토마토 농장에서는 토마토를 보관하는 큰 창고를 가지고 있다. 토마토는 아래의 그림과 같이 격자 모양 상자의 칸에 하나씩 넣어서 창고에 보관한다. 

<div align = center>

![Image](https://upload.acmicpc.net/de29c64f-dee7-4fe0-afa9-afd6fc4aad3a/-/preview/)

</div>

창고에 보관되는 토마토들 중에는 잘 익은 것도 있지만, 아직 익지 않은 토마토들도 있을 수 있다. 보관 후 하루가 지나면, 익은 토마토들의 인접한 곳에 있는 익지 않은 토마토들은 익은 토마토의 영향을 받아 익게 된다. 하나의 토마토의 인접한 곳은 왼쪽, 오른쪽, 앞, 뒤 네 방향에 있는 토마토를 의미한다. 대각선 방향에 있는 토마토들에게는 영향을 주지 못하며, 토마토가 혼자 저절로 익는 경우는 없다고 가정한다. 철수는 창고에 보관된 토마토들이 며칠이 지나면 다 익게 되는지, 그 최소 일수를 알고 싶어 한다.

토마토를 창고에 보관하는 격자모양의 상자들의 크기와 익은 토마토들과 익지 않은 토마토들의 정보가 주어졌을 때, 며칠이 지나면 토마토들이 모두 익는지, 그 최소 일수를 구하는 프로그램을 작성하라. 단, 상자의 일부 칸에는 토마토가 들어있지 않을 수도 있다.

---

### 입력

첫 줄에는 상자의 크기를 나타내는 두 정수 M,N이 주어진다. M은 상자의 가로 칸의 수, N은 상자의 세로 칸의 수를 나타낸다. 단, 2 ≤ M,N ≤ 1,000 이다. 둘째 줄부터는 하나의 상자에 저장된 토마토들의 정보가 주어진다. 즉, 둘째 줄부터 N개의 줄에는 상자에 담긴 토마토의 정보가 주어진다. 하나의 줄에는 상자 가로줄에 들어있는 토마토의 상태가 M개의 정수로 주어진다. 정수 1은 익은 토마토, 정수 0은 익지 않은 토마토, 정수 -1은 토마토가 들어있지 않은 칸을 나타낸다.

토마토가 하나 이상 있는 경우만 입력으로 주어진다.

---

### 출력

여러분은 토마토가 모두 익을 때까지의 최소 날짜를 출력해야 한다. 만약, 저장될 때부터 모든 토마토가 익어있는 상태이면 0을 출력해야 하고, 토마토가 모두 익지는 못하는 상황이면 -1을 출력해야 한다.

---

### 예제 입력

<table>
  <tr>
    <th align = center>예제 입력 1</th>
    <th align = center>예제 출력 1</th>
  </tr>
  <tr>
    <td align = center>
      <table>
        <tr>
          <td align = center colspan = "3">6</td>
          <td align = center colspan = "3">4</td> 
        </tr>
        <tr>
          <td align = center>0</td>
          <td align = center>0</td>
          <td align = center>0</td>
          <td align = center>0</td>
          <td align = center>0</td>
          <td align = center>0</td>
        </tr>
        <tr>
          <td align = center>0</td>
          <td align = center>0</td>
          <td align = center>0</td>
          <td align = center>0</td>
          <td align = center>0</td>
          <td align = center>0</td>
        </tr>
        <tr>
          <td align = center>0</td>
          <td align = center>0</td>
          <td align = center>0</td>
          <td align = center>0</td>
          <td align = center>0</td>
          <td align = center>0</td>
        </tr>
        <tr>
          <td align = center>0</td>
          <td align = center>0</td>
          <td align = center>0</td>
          <td align = center>0</td>
          <td align = center>0</td>
          <td align = center>1</td>
        </tr>
      </table>
    </td>
    <td align = center>8</td>
  </tr>
</table>

<table>
  <tr>
    <th align = center>예제 입력 2</th>
    <th align = center>예제 출력 2</th>
  </tr>
  <tr>
    <td align = center>
      <table>
        <tr>
          <td align = center colspan = "3">6</td>
          <td align = center colspan = "3">4</td> 
        </tr>
        <tr>
          <td align = center>0</td>
          <td align = center>-1</td>
          <td align = center>0</td>
          <td align = center>0</td>
          <td align = center>0</td>
          <td align = center>0</td>
        </tr>
        <tr>
          <td align = center>-1</td>
          <td align = center>0</td>
          <td align = center>0</td>
          <td align = center>0</td>
          <td align = center>0</td>
          <td align = center>0</td>
        </tr>
        <tr>
          <td align = center>0</td>
          <td align = center>0</td>
          <td align = center>0</td>
          <td align = center>0</td>
          <td align = center>0</td>
          <td align = center>0</td>
        </tr>
        <tr>
          <td align = center>0</td>
          <td align = center>0</td>
          <td align = center>0</td>
          <td align = center>0</td>
          <td align = center>0</td>
          <td align = center>1</td>
        </tr>
      </table>
    </td>
    <td align = center>-1</td>
  </tr>
</table>

<table>
  <tr>
    <th align = center>예제 입력 3</th>
    <th align = center>예제 출력 3</th>
  </tr>
  <tr>
    <td align = center>
      <table>
        <tr>
          <td align = center colspan = "3">6</td>
          <td align = center colspan = "3">4</td> 
        </tr>
        <tr>
          <td align = center>1</td>
          <td align = center>-1</td>
          <td align = center>0</td>
          <td align = center>0</td>
          <td align = center>0</td>
          <td align = center>0</td>
        </tr>
        <tr>
          <td align = center>0</td>
          <td align = center>-1</td>
          <td align = center>0</td>
          <td align = center>0</td>
          <td align = center>0</td>
          <td align = center>0</td>
        </tr>
        <tr>
          <td align = center>0</td>
          <td align = center>0</td>
          <td align = center>0</td>
          <td align = center>0</td>
          <td align = center>-1</td>
          <td align = center>0</td>
        </tr>
        <tr>
          <td align = center>0</td>
          <td align = center>0</td>
          <td align = center>0</td>
          <td align = center>0</td>
          <td align = center>-1</td>
          <td align = center>1</td>
        </tr>
      </table>
    </td>
    <td align = center>6</td>
  </tr>
</table>

<table>
  <tr>
    <th align = center>예제 입력 4</th>
    <th align = center>예제 출력 4</th>
  </tr>
  <tr>
    <td align = center>
      <table>
        <tr>
          <td align = center colspan = "2">5</td>
          <td align = center colspan = "3">5</td> 
        </tr>
        <tr>
          <td align = center>-1</td>
          <td align = center>1</td>
          <td align = center>0</td>
          <td align = center>0</td>
          <td align = center>0</td>
        </tr>
        <tr>
          <td align = center>0</td>
          <td align = center>-1</td>
          <td align = center>-1</td>
          <td align = center>-1</td>
          <td align = center>0</td>
        </tr>
        <tr>
          <td align = center>0</td>
          <td align = center>-1</td>
          <td align = center>-1</td>
          <td align = center>-1</td>
          <td align = center>0</td>
        </tr>
        <tr>
          <td align = center>0</td>
          <td align = center>-1</td>
          <td align = center>-1</td>
          <td align = center>-1</td>
          <td align = center>0</td>
        </tr>
        <tr>
          <td align = center>0</td>
          <td align = center>0</td>
          <td align = center>0</td>
          <td align = center>0</td>
          <td align = center>0</td>
        </tr>
      </table>
    </td>
    <td align = center>14</td>
  </tr>
</table>

<table>
  <tr>
    <th align = center>예제 입력 5</th>
    <th align = center>예제 출력 5</th>
  </tr>
  <tr>
    <td align = center>
      <table>
        <tr>
          <td align = center colspan = "2">2</td>
          <td align = center colspan = "2">2</td> 
        </tr>
        <tr>
          <td align = center>1</td>
          <td align = center>-1</td>
        </tr>
        <tr>
          <td align = center>-1</td>
          <td align = center>1</td>
        </tr>
      </table>
    </td>
    <td align = center>0</td>
  </tr>
</table>

---

### 문제 접근

  - 그래프 내 최단 거리를 구하는 것이므로 `Breadth First Search`

  - 입력값 기반 `matrix` 초기화

  - `matrix`와 같은 크기의 `visited` 초기화

    - `visited`는 이미 방문을 했는지에 대한 검사와 동시에 해당 시작좌표로부터 해당 좌표까지 도달하는데 필요한 `step` 수를 저장하고 있음

  - `queue<pair<int, int>>`사용

    - `queue`에는 검사 대상 좌표가 들어있음

  - 검사 대상 좌표를 기준으로 4방향 검사(북, 동, 남, 서) / **시계방향**

    - `vector<> dir`에 `북, 동, 남, 서`에 대한 정보 저장

      ```cpp
      vector<pair<int, int>> dir = {make_pair(0, -1), make_pair(1, 0), make_pair(0, 1), make_pair(-1, 0)};
      ```

      |       |  북   |  동   |  남   |  서   |
      | :---: | :---: | :---: | :---: | :---: |
      |   x   |   0   |   1   |   0   |  -1   |
      |   y   |   1   |   0   |  -1   |   0   |
    
  - 4방면 중 `matrix`를 벗어난 경우 pass

  - `matrix`를 벗어나지 않은 경우 다음 로직 수행

    - 해당 좌표를 방문한 적이 없고 벽이 아닌 경우 push

    - 이때, 해당 좌표까지의 `total step`은 현재 좌표까지의 `total step + 1`

      ```cpp
      visited[nx][ny] = visited[cx][cy] + 1;
      ```

  - 목표 지점까지의 최소 단계 수는 `visited[dx][dy]`