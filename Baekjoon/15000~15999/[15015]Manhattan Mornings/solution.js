const fs = require("fs");
const fileName = process.platform === "linux" ? "/dev/stdin" : "example.dat";
const inputData = fs.readFileSync(fileName).toString().split("\n");
const N = Number(inputData[0]);
const location = inputData[1].split(" ").map((item) => Number(item));
let H = [location[0], location[1]];
let W = [location[2], location[3]];
let conv = [0, 0];
let lis = [];
let errands = Array(N).fill([]);

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

W[0] -= H[0];
W[1] -= H[1];

if (W[0] < 0) {
  conv[0] = -1;
} else {
  conv[0] = 1;
}

if (W[1] < 0) {
  conv[1] = -1;
} else {
  conv[1] = 1;
}

for (let i = 0; i < N; i++) {
  errands[i] = inputData[2 + i].split(" ").map((item) => Number(item));

  errands[i][0] -= H[0];
  errands[i][0] *= conv[0];

  errands[i][1] -= H[1];
  errands[i][1] *= conv[1];
}

H = [0, 0];
W[0] *= conv[0];
W[1] *= conv[1];

errands.sort((a, b) => {
  if (a[0] != b[0]) {
    return a[0] - b[0];
  } else {
    return a[1] - b[1];
  }
});

for (let i = 0; i < N; i++) {
  if (errands[i][0] < H[0] || errands[i][0] > W[0]) continue;
  if (errands[i][1] < H[1] || errands[i][1] > W[1]) continue;

  if (lis.length == 0 || lis[lis.length - 1] <= errands[i][1])
    lis.push(errands[i][1]);
  else {
    const idx = upper_bound(errands[i][1]);
    lis[idx] = errands[i][1];
  }
}

console.log(lis.length);
