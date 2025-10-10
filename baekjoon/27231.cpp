#include <bits/stdc++.h>

using namespace std;

int t; string n;
set<long long> s;

int l;

void recursivelyGetAvailableSum(long long nowVal, int idx) {
  if (idx == n.length()) {
    s.insert(nowVal);
    return;
  }

  for (int offset = 1; idx + offset <= n.length(); offset++)
    recursivelyGetAvailableSum(nowVal + stoi(n.substr(idx, offset)), idx + offset);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> t;
  while (t--) {
    cin >> n;
    s.clear();
    recursivelyGetAvailableSum(0, 0);
    bool isInfinite = true;
    for (int i = 0; i < n.length(); i++)
      isInfinite = isInfinite && ((int)(n[i] - '0') == 0 || (int)(n[i] - '0') == 1);

    if (isInfinite) {
      cout << "Hello, BOJ 2023!" << "\n";
      continue;
    }

    long long maxVal = 0;
    for (long long v : s)
      maxVal = max(maxVal, v);

    int cnt = 0;
    int m = 1;
    while (1) {
      long long sumByM = 0;
      for (int i = 0; i < n.length(); i++)
        sumByM += pow((int)(n[i] - '0'), m);
      if (s.find(sumByM) != s.end())
        cnt++;
      if (sumByM >= maxVal)
        break;
      m++;
    }
    cout << cnt << "\n";
  }
}