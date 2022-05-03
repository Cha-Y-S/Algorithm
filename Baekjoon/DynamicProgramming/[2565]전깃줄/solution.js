const fs = require("fs");
const fileName = process.platform === "linux" ? "/dev/stdin" : "example.dat";
const inputData = fs.readFileSync(fileName).toString().trim().split("\n");
const N = Number(inputData[0]);
let pole = Array(N).fill([]);
let dp = Array(N).fill(1);

for (let i = 0; i < N; i++) {
  pole[i] = inputData[1 + i].split(" ").map((item) => Number(item));
}

pole.sort((a, b) => {
  return a[0] - b[0];
});

for (let i = 1; i < N; i++) {
  for (let j = i - 1; j >= 0; j--) {
    if (pole[i][1] > pole[j][1]) {
      dp[i] = Math.max(dp[i], dp[j] + 1);
    }
  }
}

console.log(N - Math.max.apply(null, dp));
