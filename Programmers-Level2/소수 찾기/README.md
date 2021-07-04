# 소수 찾기 - 완전탐색

### 문제 설명

한자리 숫자가 적힌 종이 조각이 흩어져있습니다. 흩어진 종이 조각을 붙여 소수를 몇 개 만들 수 있는지 알아내려 합니다.

각 종이 조각에 적힌 숫자가 적힌 문자열 numbers가 주어졌을 때, 종이 조각으로 만들 수 있는 소수가 몇 개인지 return 하도록 solution 함수를 완성해주세요.

---

### 제한사항

  - numbers는 길이 1 이상 7 이하인 문자열입니다.

  - numbers는 0~9까지 숫자만으로 이루어져 있습니다.

  - "013"은 0, 1, 3 숫자가 적힌 종이 조각이 흩어져있다는 의미입니다.

---

### 입출력 예

| numbers | return |
| :-----: | :----: |
|  "17"   |   3    |
|  "011"  |   2    |

---

### 입출력 예 설명

#### 입출력 예 #1

[1, 7]으로는 소수 [7, 17, 71]를 만들 수 있습니다.

#### 입출력 예 #2

[0, 1, 1]으로는 소수 [11, 101]를 만들 수 있습니다.

  - 11과 011은 같은 숫자로 취급합니다.

---

### 문제 접근

  - `<algorithm>`의 `next_permutation` 사용

    ```cpp
    // default
    template <class BidirIt>
    bool next_permutation (BidirIt first, BidirIt last);

    // custom
    template <class BidirIt, class Compare>
    bool next_permutation (BidirIt first, BidirIt last, Compare comp);
    ```

  - `next_permutation`은 현재 순열에서 더 큰 순열을 구하는 것이기 때문에 수행 전 기존 순열이 오름차순으로 정렬되어 있어야 함

    - 반대로 `prev_permutation`의 경우 더 작은 순열을 구하는 것이므로 기존 순열이 내림차순으로 정렬되어 있어야 함

      ```cpp
      // default
      template< class BidirIt >
      bool prev_permutation(BidirIt first, BidirIt last );

      // custom
      template< class BidirIt, class Compare >
      bool prev_permutation(BidirIt first, BidirIt last, Compare comp );
      ```

  - `next_permutation`을 사용해 구할 수 있는 모든 수를 구한 후 `<algorithm>`의 `unique`와 `<vector>`의 `erase`를 사용해 중복 제거

    ```cpp
    template <class ForwardIterator>
    ForwardIterator unique (ForwardIterator first, ForwardIterator last); 
    
    v.erase(unique(v.begin(), v.end()), v.end());
    ```

    - `unique`함수는 중복되는 모든 값들을 쓰레기 값으로 처리 후 vector의 가장 뒤로 보낸 후, 쓰레기 값들이 시작되는 첫 번째 `iterator`를 반환함

  - 이후, 주어진 문자열로부터 생성 가능한 모든 숫자들에 대해 소수 판별 과정 진행