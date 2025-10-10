#include <bits/stdc++.h>

using namespace std;

int k, n;
int lines[10001];

unsigned int binary_search(unsigned int start, unsigned int end) {
  if (start > end)
    return 0;

  unsigned int mid = (start + end) / 2;

  int cnt = 0;
  for (int i = 0; i < k; i++)
    cnt += lines[i] / mid;

  if (cnt >= n)
    return max(mid, binary_search(mid + 1, end));
  else
    return binary_search(start, mid - 1);
}

int main() {
  cin >> k >> n;
  for (int i = 0; i < k; i++)
    cin >> lines[i];

  cout << binary_search(1, INT_MAX);

  return 0;
}