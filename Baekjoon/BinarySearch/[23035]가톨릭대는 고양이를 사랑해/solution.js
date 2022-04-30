const fs = require("fs");
const fileName = process.platform === "linux" ? "/dev/stdin" : "example.dat";
const inputData = fs.readFileSync(fileName).toString().split("\n");
const [N, M] = inputData[0].split(" ");
inputData.shift();

const T = Number(inputData[0].split(" "));
inputData.shift();

let cats = Array.from({ length: T }, () => [0, 0]);
let lis = [];

const upper_bound = (value) => {
  let low = 0;
  let high = lis.length;

  while (low < high) {
    let mid = parseInt((low + high) / 2);

    if (value < lis[mid]) {
      high = mid;
    } else {
      low = mid + 1;
    }
  }

  return high;
};

for (let i = 0; i < T; i++) {
  cats[i] = inputData[0].split(" ");
  cats[i][0] = Number(cats[i][0]);
  cats[i][1] = Number(cats[i][1]);
  inputData.shift();
}

cats.sort((a, b) => {
  return a[0] != b[0] ? a[0] - b[0] : a[1] - b[1];
});

for (let i = 0; i < T; i++) {
  if (cats[i][0] > N || cats[i][1] > M) continue;

  if (lis.length == 0 || lis[lis.length - 1] <= cats[i][1])
    lis.push(cats[i][1]);
  else {
    const idx = upper_bound(cats[i][1]);
    lis[idx] = cats[i][1];
  }
}

console.log(lis.length);
