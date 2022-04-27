const fs = require("fs");
// const inputData = fs.readFileSync("example.dat").toString().split("\n");
const inputData = fs.readFileSync("/dev/stdin").toString().split("\n");
const N = Number(inputData[0]);
const seq = inputData[1].split(" ").map((item) => Number(item));
let dp = Array(N).fill(1);

for (let i = 1; i < N; i++) {
  for (let j = i - 1; j >= 0; j--) {
    if (seq[i] > seq[j]) {
      dp[i] = Math.max(dp[i], dp[j] + 1);
    }
  }
}

console.log(Math.max.apply(null, dp));
