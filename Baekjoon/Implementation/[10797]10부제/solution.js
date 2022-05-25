const fileName = "/dev/stdin";
const inputData = require("fs")
  .readFileSync(fileName)
  .toString()
  .trim()
  .split("\n");

const input = (() => {
  let line = 0;
  return () => inputData[line++];
})();

const day = Number(input());
let res = 0;

input()
  .split(" ")
  .map((item) => (res = day === Number(item) ? res + 1 : res));

console.log(res);
