let fs = require("fs");
let inputs = fs
  .readFileSync("/dev/stdin")
  .toString()
  .split(/ |\n/)
  .map((input) => input.trim());

let idx = 0;
let t = parseInt(inputs[idx++]);

let cache;
let card;
let partialSum;

const dp = (left, right) => {
  if (cache[left][right] !== -1) return cache[left][right];

  if (left - right == 0) {
    cache[left][right] = card[left];
    return cache[left][right];
  }

  let leftSel = 0;
  leftSel += card[left];
  leftSel +=
    partialSum[right] -
    (left + 1 == 0 ? 0 : partialSum[left + 1 - 1]) -
    dp(left + 1, right);

  let rightSel = 0;
  rightSel += card[right];
  rightSel +=
    partialSum[right - 1] -
    (left == 0 ? 0 : partialSum[left - 1]) -
    dp(left, right - 1);

  cache[left][right] = leftSel > rightSel ? leftSel : rightSel;

  return cache[left][right];
};

while (t--) {
  const n = parseInt(inputs[idx++]);

  card = new Array(0);
  partialSum = new Array(0);

  for (let i = 0; i < n; i++) card.push(parseInt(inputs[idx++]));

  partialSum.push(card[0]);
  for (let i = 1; i < n; i++) partialSum.push(partialSum[i - 1] + card[i]);

  cache = new Array();
  for (let i = 0; i <= n; i++) {
    let temp = new Array();

    for (let j = 0; j <= n; j++) temp.push(-1);

    cache.push(temp);
  }

  console.log(dp(0, n - 1));
}
