const fs = require("fs");
// const inputData = fs.readFileSync("example.dat").toString().split("\n");
const inputData = fs.readFileSync("/dev/stdin").toString().split("\n");
const N = Number(inputData[0]);
const seq = inputData[1].split(" ").map((item) => Number(item));
let lis = [];

const lower_bound = (value) => {
  low = 0;
  high = lis.length;

  while (low < high) {
    mid = parseInt((low + high) / 2);

    if (value < lis[mid]) {
      high = mid;
    } else {
      low = mid + 1;
    }
  }

  return high;
};

for (let i = 0; i < N; i++) {
  idx = lower_bound(seq[i]);

  if (idx == lis.length) {
    lis.push(seq[i]);
  } else {
    lis[idx] = seq[i];
  }
}

console.log(lis.length);
