# [진우의 달 여행 (Large)](https://www.acmicpc.net/problem/17485)

<div align = center>

| 시간 제한 | 메모리 제한 | 제출 | 정답 | 맞은 사람 | 정답 비율 |
| :-------- | :---------- | :--- | :--- | :-------- | :-------- |
| 1 초      | 256 MB      | 772  | 341  | 251       | 43.127%   |

</div>

### 문제

우주비행이 꿈이였던 진우는 음식점 '매일매일싱싱'에서 열심히 일한 결과 달 여행에 필요한 자금을 모두 마련하였다! 지구와 우주사이는 N X M 행렬로 나타낼 수 있으며 각 원소의 값은 우주선이 그 공간을 지날 때 소모되는 연료의 양이다.

<div align=center>
  [예시]
  <img alt="" src="https://upload.acmicpc.net/9e155c65-43ea-492b-af73-d3f9f9c9dc44/-/preview/" style="height: 353px; width: 150px;">
</div>

진우는 여행경비를 아끼기 위해 조금 특이한 우주선을 선택하였다. 진우가 선택한 우주선의 특징은 아래와 같다.

**1. 지구 -> 달로 가는 경우 우주선이 움직일 수 있는 방향은 아래와 같다.**

<img alt="" src="https://upload.acmicpc.net/8f6fc516-9870-4ef6-8474-b5d82f7b6f21/-/preview/" style="width: 200px; height: 200px;">
<img alt="" src="https://upload.acmicpc.net/eb6f87f0-f4d0-43cc-8e9d-5d94bfc41936/-/preview/" style="width: 200px; height: 200px;">
<img alt="" src="https://upload.acmicpc.net/e7b501aa-c92c-4a17-aed7-c7868b89af7a/-/preview/" style="width: 200px; height: 200px;">

**2. 우주선은 전에 움직인 방향으로 움직일 수 없다. 즉, 같은 방향으로 두번 연속으로 움직일 수 없다.**

진우의 목표는 **연료를 최대한 아끼며 지구의 어느위치에서든 출발하여 달의 어느위치든 착륙하는 것**이다.

최대한 돈을 아끼고 살아서 달에 도착하고 싶은 진우를 위해 달에 도달하기 위해 필요한 연료의 최소값을 계산해 주자.

---

### 입력

첫줄에 지구와 달 사이 공간을 나타내는 행렬의 크기를 나타내는 **N, M (2 ≤ N, M ≤ 1000)**이 주어진다.

다음 N줄 동안 각 행렬의 원소 값이 주어진다. 각 행렬의 원소값은 100 이하의 자연수이다.

---

### 출력

달 여행에 필요한 최소 연료의 값을 출력한다.

---

### 예제 입력

| 예제 입력1                                                                        | 예제 출력1 |
| :-------------------------------------------------------------------------------- | :--------- |
| 6 4<br/>5 8 5 1<br/>3 5 8 4<br/>9 77 65 5<br/>2 1 5 2<br/>5 98 1 5<br/>4 95 67 58 | 29         |

---

### 문제 접근

  - `DP` 문제

  - [진우의 달 여행 (Small)](https://github.com/firemancha/Algorithm/tree/main/Baekjoon/DynamicProgramming/%5B17484%5D%EC%A7%84%EC%9A%B0%EC%9D%98%20%EB%8B%AC%20%EC%97%AC%ED%96%89%20(Small))과 동일한 문제