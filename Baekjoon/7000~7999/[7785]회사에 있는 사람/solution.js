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

const N = Number(input());
const company = new Set();

for (let i = 0; i < N; i++) {
  const [name, info] = input().split(" ");

  if (info === "enter") {
    company.add(name);
  } else {
    company.delete(name);
  }
}

console.log([...company].sort().reverse().join("\n"));
