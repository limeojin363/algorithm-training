#include <bits/stdc++.h>
#define LEN 1000000

using namespace std;

int n;
long long sqaured[LEN];

void preset() {
  cin >> n;
  for (int i = 1; i < LEN; i++) {
    sqaured[i] = i * i;
  }
}

void solve() {
  while (n--) {
    long long x, y;
    cin >> x >> y;
    long long diff = y - x;
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  preset();
  solve();
}
