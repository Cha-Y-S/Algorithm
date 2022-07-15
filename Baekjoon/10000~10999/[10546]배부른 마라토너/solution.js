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
const player = {};

for (let i = 0; i < N; i++) {
  const p = input();

  if (p in player === false) {
    player[p] = 1;
    continue;
  }

  player[p] += 1;
}

for (let i = 0; i < N - 1; i++) {
  const p = input();

  player[p] -= 1;
}

for (let key in player) {
  if (player[key] != 0) {
    console.log(key);
    break;
  }
}
