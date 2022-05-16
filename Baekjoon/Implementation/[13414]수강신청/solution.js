const fileName = process.platform === "linux" ? "/dev/stdin" : "example.dat";
const inputData = require("fs")
  .readFileSync(fileName)
  .toString()
  .trim()
  .split("\n");

const input = (() => {
  let line = 0;
  return () => inputData[line++];
})();

let [K, L] = input()
  .split(" ")
  .map((item) => Number(item));
const enroll = {};

for (let i = 0; i < L; i++) {
  enroll[input()] = i;
}

const res = Object.entries(enroll)
  .sort((a, b) => a[1] - b[1])
  .splice(0, K)
  .map((item) => item[0]);
console.log(res.join("\n"));
