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
const s = new Set();

for (let i = 0; i < N; i++) {
  const word = input()
    .split("")
    .sort((a, b) => a.localeCompare(b))
    .join("");

  s.add(word);
}

console.log(s.size);
