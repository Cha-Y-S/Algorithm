const fileName = process.platform === "linux" ? "/dev/stdin" : "example.dat";
const [A, B] = require("fs")
  .readFileSync(fileName)
  .toString()
  .trim()
  .split("\n");

let dp = Array.from(Array(A.length + 1), () => Array(B.length + 1).fill(0));

for (let i = 1; i < dp.length; i++) {
  for (let j = 1; j < dp[i].length; j++) {
    if (A.charAt(i - 1) === B.charAt(j - 1)) {
      dp[i][j] = dp[i - 1][j - 1] + 1;
    } else {
      dp[i][j] = Math.max(dp[i - 1][j], dp[i][j - 1]);
    }
  }
}

console.log(dp[A.length][B.length]);
