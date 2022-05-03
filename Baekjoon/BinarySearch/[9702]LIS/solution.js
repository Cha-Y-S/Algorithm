const fs = require("fs");
const fileName = process.platform === "linux" ? "/dev/stdin" : "example.dat";
const inputData = fs.readFileSync(fileName).toString().trim().split("\n");
const T = Number(inputData[0]);
inputData.shift();
let lis = [];

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

for (let t = 0; t < T; t++) {
  const N = Number(inputData[0]);
  inputData.shift();
  const seq = inputData.map((item) => Number(item));
  let res = 0;

  for (let i = 0; i < N; i++) {
    inputData.shift();
  }

  for (let i = 0; i < N; i++) {
    lis.length = 0;
    for (let j = i; j < N; j++) {
      const idx = lower_bound(seq[j]);

      if (idx == lis.length) {
        lis.push(seq[j]);
      } else {
        lis[idx] = seq[j];
      }

      res += lis.length;
    }
  }

  console.log(`Case #${t + 1}: ${res}`);
}
