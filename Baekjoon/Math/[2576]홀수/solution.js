const fileName = process.platform === "linux" ? "/dev/stdin" : "example.dat";
const inputData = require("fs")
  .readFileSync(fileName)
  .toString()
  .trim()
  .split("\n");
let res_min = 100;
let res_sum = 0;

inputData.map((item) => {
  let num = Number(item);
  if (num % 2 != 0) {
    res_min = res_min > num ? num : res_min;
    res_sum += num;
  }
});

if (res_sum === 0) {
  console.log(-1);
} else {
  console.log([res_sum, res_min].join("\n"));
}
