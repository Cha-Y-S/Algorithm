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

let low = 100;
let res = 0;

for (let i = 0; i < 4; i++) {
  let point = Number(input());

  low = low > point ? point : low;

  res += point;
}

res -= low;
low = 100;

for (let i = 0; i < 2; i++) {
  let point = Number(input());

  low = low > point ? point : low;

  res += point;
}

res -= low;

console.log(res);
