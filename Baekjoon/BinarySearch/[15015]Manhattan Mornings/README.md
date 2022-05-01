# [Manhattan Mornings](https://www.acmicpc.net/problem/15015)

<div align = center>

| 시간 제한 | 메모리 제한 | 제출 | 정답 | 맞은 사람 | 정답 비율 |
| :-------- | :---------- | :--- | :--- | :-------- | :-------- |
| 2 초      | 512 MB      | 92   | 54   | 46        | 58.228%   |

</div>

### 문제

As a New Yorker you are always very busy. Apart from your long work day you tend to have a very long list of errands that need to be done on any particular day. You really hate getting up early so you always end up going over your to-do list after work, but this is starting to seriously hurt your free time.

One day you realize that some of the places you have to go by lie on your walk to the office, so you can visit them before work. The next day you notice that if you take a slightly different route to work you can run most of your errands without increasing the length of your route. Since errands take a negligible amount of time, you don’t even have to get up any earlier to do this! This nice little side effect of the grid-like New York streets gets you thinking. Given all the locations of your errands on the New York grid, how many can you visit on your way to work without getting up any earlier?

The New York grid is modelled with streets that are parallel to the x-axis and avenues that are parallel to the y-axis. Specifically, there is a street given by y = a for every a ∈ Z, and there is an avenue given by x = b for every b ∈ Z. It is given that an errand always takes place on an intersection between a street and an avenue. Since you walk to your work, you can use all roads in both directions.

---

### 입력

  - The first line contains an integer 0 ≤ n ≤ 10<sup>5</sup>, the number of errands you have to run that day.

  - The next line contains four integers 0 ≤ x<sub>h</sub>, y<sub>h</sub>, x<sub>w</sub>, y<sub>w</sub> ≤ 10<sup>9</sup> corresponding to the locations of your house and workplace.

  - The next n lines each contain two integers 0 ≤ x<sub>i</sub>, y<sub>i</sub> ≤ 10<sup>9</sup>, the coordinates of your ith errand.

---

### 출력

Output a single line, containing the number of errands you can run before work without taking a longer route than necessary.

---

### 예제 입력

| 예제 입력1                            | 예제 출력1 |
| :------------------------------------ | :--------- |
| 3<br/>0 0 6 6<br/>5 4<br/>2 6<br/>3 1 | 2          |

| 예제 입력2                                            | 예제 출력2 |
| :---------------------------------------------------- | :--------- |
| 5<br/>2 1 0 0<br/>0 0<br/>0 1<br/>2 0<br/>2 1<br/>3 1 | 3          |

| 예제 입력3                                                           | 예제 출력3 |
| :------------------------------------------------------------------- | :--------- |
| 4<br/>200 100 100 200<br/>50 150<br/>200 200<br/>100 100<br/>100 100 | 2          |

---

### 문제 접근

  - 이분 탐색 문제

  - [가톨릭대는 고양이를 사랑해](https://github.com/firemancha/Algorithm/tree/main/Baekjoon/BinarySearch/%5B23035%5D%EA%B0%80%ED%86%A8%EB%A6%AD%EB%8C%80%EB%8A%94%20%EA%B3%A0%EC%96%91%EC%9D%B4%EB%A5%BC%20%EC%82%AC%EB%9E%91%ED%95%B4)와 비슷한 문제
  
  - 단, `H`와 `W` 값에 따라 좌표값을 변환해주어야 함(좌표계 변환)