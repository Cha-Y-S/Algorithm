const fileName = process.platform === "linux" ? "/dev/stdin" : "example.dat";
const inputData = require("fs")
  .readFileSync(fileName)
  .toString()
  .trim()
  .split("\n");
const sum1 = inputData[0]
  .split(" ")
  .map((item) => Number(item))
  .reduce((sum, cur) => {
    return sum + cur;
  }, 0);
const sum2 = inputData[1]
  .split(" ")
  .map((item) => Number(item))
  .reduce((sum, cur) => {
    return sum + cur;
  }, 0);

console.log(sum1 > sum2 ? sum1 : sum2);
