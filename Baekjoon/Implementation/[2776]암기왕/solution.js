const fileName = process.platform === "linux" ? "/dev/stdin" : "example.dat";
const inputData = require("fs").readFileSync(fileName).toString().split("\n");

const input = (() => {
  let line = 0;
  return () => inputData[line++];
})();

const T = Number(input());

for (let t = 0; t < T; t++) {
  const N = Number(input());
  const note = new Set();
  input()
    .split(" ")
    .map((item) => note.add(item));
  const M = Number(input());
  console.log(
    input()
      .split(" ")
      .map((item) => (note.has(item) ? 1 : 0))
      .join("\n")
  );
}
