const fileName = process.platform === "linux" ? "/dev/stdin" : "example.dat";
const inputData = require("fs")
  .readFileSync(fileName)
  .toString()
  .trim()
  .split("\n");
const input = (() => {
  let line = 0;
  return () => inputData[line++];
})();

const lower_bound = (arr, value) => {
  let low = 0;
  let high = arr.length;

  while (low < high) {
    let mid = parseInt((low + high) / 2);

    if (value <= arr[mid]) {
      high = mid;
    } else {
      low = mid + 1;
    }
  }

  return high;
};

while (true) {
  const [N, M] = input()
    .split(" ")
    .map((item) => Number(item));

  if (N === 0 && M === 0) {
    break;
  }

  if (N == 0 || M == 0) {
    console.log(0);
    continue;
  }

  let CD = Array.from({ length: N }, () => 0);
  let res = 0;

  for (let i = 0; i < N; i++) {
    CD[i] = Number(input());
  }

  for (let i = 0; i < M; i++) {
    const num = Number(input());

    const idx = lower_bound(CD, num);

    if (idx >= CD.length) {
      continue;
    }

    if (num === CD[idx]) {
      res++;
    }
  }

  console.log(res);
}
