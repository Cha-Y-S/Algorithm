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

const input_data = () => {
  const A = new Set();
  const B = new Set();
  const C = new Set();

  const N = Number(input());

  input()
    .split(" ")
    .map((item) => A.add(Number(item)));

  const M = Number(input());

  input()
    .split(" ")
    .map((item) => B.add(Number(item)));

  const K = Number(input());

  input()
    .split(" ")
    .map((item) => C.add(Number(item)));

  return [A, B, C];
};

const check_validity = (number) => {
  let result = true;

  for (let n of number) {
    if (n != "5" && n != "8") {
      result = false;
      break;
    }
  }

  return result;
};

let T = Number(input());

while (T-- > 0) {
  const [A, B, C] = input_data();

  const lucky_number = new Set();

  for (let a of A) {
    for (let b of B) {
      for (let c of C) {
        const tmp = a + b + c;
        if (check_validity(new String(tmp))) {
          lucky_number.add(tmp);
        }
      }
    }
  }

  console.log(lucky_number.size);
}
