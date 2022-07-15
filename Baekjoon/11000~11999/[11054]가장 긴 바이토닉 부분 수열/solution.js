const fs = require("fs");
// const inputData = fs.readFileSync("example.dat").toString().split("\n");
const inputData = fs.readFileSync("/dev/stdin").toString().split("\n");
const N = Number(inputData[0]);
const seq = inputData[1].split(" ").map((item) => Number(item));
const rseq = [...seq].reverse();
let dp_asc = Array(N).fill(1);
let dp_desc = Array(N).fill(1);

for (let i = 1; i < N; i++) {
  for (let j = i - 1; j >= 0; j--) {
    if (seq[i] > seq[j]) {
      dp_asc[i] = Math.max(dp_asc[i], dp_asc[j] + 1);
    }
    if (rseq[i] > rseq[j]) {
      dp_desc[i] = Math.max(dp_desc[i], dp_desc[j] + 1);
    }
  }
}

let lbs_size = 0;
for (let i = 0; i < N; i++) {
  lbs_size = Math.max(lbs_size, dp_asc[i] + dp_desc[N - i - 1] - 1);
}

console.log(lbs_size);
