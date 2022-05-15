const fileName = process.platform === "linux" ? "/dev/stdin" : "example.dat";
const inputData = require("fs")
  .readFileSync(fileName)
  .toString()
  .trim()
  .split("\n");

const trees = {};
let tree = "";
let cnt = 0;

inputData.map((tree) => {
  trees[tree] = (trees[tree] || 0) + 1;
  cnt++;
});

console.log(
  Object.keys(trees)
    .sort()
    .map((key) => `${key} ${((trees[key] / cnt) * 100).toFixed(4)}`)
    .join("\n")
);
