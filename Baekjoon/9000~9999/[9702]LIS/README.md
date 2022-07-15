# [LIS](https://www.acmicpc.net/problem/9702)

<div align = center>

| 시간 제한 | 메모리 제한 | 제출 | 정답 | 맞은 사람 | 정답 비율 |
| :-------- | :---------- | :--- | :--- | :-------- | :-------- |
| 1 초      | 128 MB      | 182  | 68   | 60        | 45.455%   |

</div>

### 문제

Mr. C is interested with Longest Increasing Subsequence problem. Given a sequence S = s<sub>1</sub>, s<sub>2</sub>, …, s<sub>N</sub>. The Longest Increasing Subsequence is the subsequence L = l<sub>1</sub>, l<sub>2</sub>, …, l<sub>k</sub> of S such that l<sub>1</sub> < l<sub>2</sub> < … < l<sub>k</sub>. 

Given a sequence S, find the total length of LIS of every consecutive subsequence (subsequence which elements are consecutive in the original sequence) of S with non zero length!

---

### 입력

The first line of input consists of an integer T denotes the number of cases. It is followed by T blocks, each representing a case.

The first line of each case contains an integers: N (1 ≤ N ≤ 500), the length of S.

The next N lines each consists of an integer s<sub>i</sub> (1 ≤ s<sub>i</sub> ≤ N) denoting the i-th element of S. Each element of S is unique.

---

### 출력

Output consists of T lines, each describes the solution for each case with the same order as in input.

Each case consists of a single line with the format “Case #i: S”, where i represents the case number and S represents the total length of LIS of every consecutive subsequence of S.

---

### 예제 입력

| 예제 입력1                | 예제 출력1 |
| :------------------------ | :--------- |
| 1<br/>3<br/>3<br/>1<br/>2 | Case #1: 8 |

---

### 문제 접근

  - 이분 탐색 문제

  - 각 케이스별로 수열을 입력받음

  - 입력받은 수열에서 시작점을 갱신해가면서 모든 `lis`를 찾은 후 각 `lis`의 크기를 합산

  - 케이스별로 합산된 부분 수열의 크기를 출력