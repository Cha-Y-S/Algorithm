const fs = require("fs");
const fileName = process.platform === "linux" ? "/dev/stdin" : "example.dat";
const inputData = fs.readFileSync(fileName).toString().trim().split("\n");
const [N, M] = inputData[0].split(" ").map((item) => Number(item));
const n_input = inputData[1].split(" ").map((item) => Number(item));
const m_input = inputData[2].split(" ").map((item) => Number(item));
const K = Number(inputData[3]);
let [l_pole, r_pole] = [{}, {}];
let connected = Array(K).fill([]);
let lis = [];

const lower_bound = (value) => {
  let low = 0;
  let high = lis.length;

  while (low < high) {
    let mid = parseInt((low + high) / 2);

    if (value <= lis[mid]) {
      high = mid;
    } else {
      low = mid + 1;
    }
  }

  return high;
};

for (let i = 0; i < N; i++) {
  l_pole[n_input[i]] = i;
}

for (let i = 0; i < M; i++) {
  r_pole[m_input[i]] = i;
}

for (let i = 0; i < K; i++) {
  const connection = inputData[4 + i].split(" ").map((item) => Number(item));

  connected[i] = [l_pole[connection[0]], r_pole[connection[1]]];
}

connected.sort((a, b) => {
  if (a[0] != b[0]) {
    return a[0] - b[0];
  } else {
    return b[1] - a[1];
  }
});

for (let i = 0; i < K; i++) {
  const idx = lower_bound(connected[i][1]);

  if (idx == lis.length) {
    lis.push(connected[i][1]);
  } else {
    lis[idx] = connected[i][1];
  }
}

console.log(K - lis.length);
