const fileName = process.platform === "linux" ? "/dev/stdin" : "example.dat";
const inputData = require("fs")
  .readFileSync(fileName)
  .toString()
  .trim()
  .split("\n");
const N = Number(inputData[0]);
let seq = Array(N);
let dp = Array(N).fill(1);

for (let i = 0; i < N; i++) {
  seq[i] = Number(inputData[1 + i]);
}

for (let i = 1; i < N; i++) {
  for (let j = i - 1; j >= 0; j--) {
    if (seq[i] > seq[j]) {
      dp[i] = Math.max(dp[i], dp[j] + 1);
    }
  }
}

console.log(N - Math.max.apply(null, dp));
