const fileName = process.platform === "linux" ? "/dev/stdin" : "example.dat";
const inputData = require("fs").readFileSync(fileName).toString().trim();
const sub = new Set();

for (let i = 0; i < inputData.length; i++) {
  for (let j = i; j < inputData.length; j++) {
    sub.add(inputData.slice(i, j + 1));
  }
}

console.log(sub.size);
