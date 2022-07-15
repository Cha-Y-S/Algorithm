const fileName = process.platform === "linux" ? "/dev/stdin" : "example.dat";
const inputData = require("fs")
  .readFileSync(fileName)
  .toString()
  .trim()
  .split(" ");

const skill = inputData.map((item) => Number(item));

console.log(Math.abs(skill[0] + skill[3] - (skill[1] + skill[2])));
