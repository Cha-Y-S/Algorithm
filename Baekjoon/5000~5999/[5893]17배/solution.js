const fileName = process.platform === "linux" ? "/dev/stdin" : "example.dat";
const inputData = require("fs")
  .readFileSync(fileName)
  .toString()
  .trim()
  .split("\n");

const mul17 = (n) => {
  let left = n + "0000";
  let right = "0000" + n;
  let result = "";

  let carry = false;
  for (let i = left.length - 1; i >= 0; i--) {
    if (left[i] == "0" && right[i] == "0") {
      if (carry) {
        result = "1" + result;
      } else {
        result = "0" + result;
      }
      carry = false;
    } else if (left[i] == "1" && right[i] == "1") {
      if (carry) {
        result = "1" + result;
      } else {
        result = "0" + result;
      }
      carry = true;
    } else {
      if (carry) {
        result = "0" + result;
        carry = true;
      } else {
        result = "1" + result;
        carry = false;
      }
    }
  }

  result = carry ? "1" + result : result;

  return result;
};

console.log(mul17(inputData));
