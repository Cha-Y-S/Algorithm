const fs = require("fs");
// const inputData = fs.readFileSync("example.dat").toString().split("\n");
const inputData = fs.readFileSync("/dev/stdin").toString().split("\n");
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
  console.log("Case #%d", t + 1);
  const tmp = inputData[0].split(" ");
  inputData.shift();

  N = Number(tmp[0]);
  K = Number(tmp[1]);

  const seq = inputData[0].split(" ").map((item) => Number(item));
  inputData.shift();

  for (let i = 0; i < N; i++) {
    let idx = lower_bound(seq[i]);

    if (idx == lis.length) {
      lis.push(seq[i]);
    } else {
      lis[idx] = seq[i];
    }
  }

  console.log(K <= lis.length ? "1" : "0");
  lis.length = 0;
}
