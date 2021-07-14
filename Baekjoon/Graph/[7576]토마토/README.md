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

  -  `BFS` 사용하여 접근

  - 이 전에 풀었던 `BFS`문제들과 로직 자체는 동일

  - 단, `BFS`의 시작점이 여러 개일 수 있음

    - 주어진 `matrix` 중 원소 값들이 1인 위치부터 시작(여러개인 경우 동시에)

    - `queue`에 해당 좌표를 모두 push하고 시작하면 동시에 시작 가능

  - `BFS` 수행 후 `matrix` 내에 0이 하나라도 있으면 -1 반환

  - 0이 없는 경우 `matrix` 원소의 `최댓값 - 1` 반환