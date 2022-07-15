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

const [N, C] = input()
  .split(" ")
  .map((item) => Number(item));
const freq = {};
const order = {};
const sorted = [];

input()
  .split(" ")
  .map((item, idx) => {
    let tmp = Number(item);
    if (tmp in freq) {
      freq[tmp] += 1;
    } else {
      freq[tmp] = 1;
    }

    if (!(tmp in order)) {
      order[tmp] = idx;
    }
  });

for (let key in freq) {
  sorted.push([key, freq[key]]);
}

const res = sorted
  .sort((a, b) => {
    return a[1] != b[1] ? b[1] - a[1] : order[a[0]] - order[b[0]];
  })
  .map((item) => {
    const [key, value] = item;
    return new Array(value).fill(key).join(" ");
  })
  .join(" ");

console.log(res);
