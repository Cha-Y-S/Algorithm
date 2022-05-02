const fs = require("fs");
const fileName = process.platform === "linux" ? "/dev/stdin" : "example.dat";
const inputData = fs.readFileSync(fileName).toString().split("\n");
const N = Number(inputData[0]);
let lis = [];
let res = [];
let pole = Array(N).fill([]);
let idxs = Array(N);

const lower_bound = (value) => {
  let low = 0;
  let high = lis.length;

  while (low < high) {
    let mid = parseInt((low + high) / 2);

    if (value <= lis[mid]) {
      high = mid;
    } else {
      low = mid + 1;
    }
  }

  return high;
};

for (let i = 0; i < N; i++) {
  pole[i] = inputData[1 + i].split(" ").map((item) => Number(item));
}

pole.sort((a, b) => {
  return a[0] - b[0];
});

for (let i = 0; i < N; i++) {
  const idx = lower_bound(pole[i][1]);

  idxs[i] = idx;

  if (idx == lis.length) {
    lis.push(pole[i][1]);
  } else {
    lis[idx] = pole[i][1];
  }
}

let target = lis.length - 1;
for (let i = N - 1; i >= 0; i--) {
  if (target == idxs[i]) {
    target--;
  } else {
    res.push(pole[i][0]);
  }
}

res.sort((a, b) => {
  return a - b;
});

console.log(N - lis.length);
for (let i = 0; i < res.length; i++) {
  console.log(res[i]);
}
