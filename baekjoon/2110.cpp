#include <iostream>
#include <algorithm>
#define HOME_POS_MAXNUM 200001
#define GAP_MAXVAL 1000000000

using namespace std;

int n, c;
int home_pos[HOME_POS_MAXNUM];

void preset() {
  cin >> n >> c;
  for (int i = 0; i < n; i++)
    cin >> home_pos[i];
  // 이분 탐색 수행이 가능하도록 정렬
  sort(home_pos, home_pos + n);
}

// 해당 간격으로 c개 이상의 집에 공유기를 설치할 수 있는지
bool ok(int gap) {

  int prev_pos = home_pos[0];
  int cnt = 1; // 첫째 집에는 무조건 설치하고 시작

  for (int i = 0; i < n; i++) {
    int now_pos = home_pos[i];
    if ((now_pos - prev_pos) >= gap) {
      prev_pos = now_pos;
      cnt++;
    }
  }

  return cnt >= c;
}

void solve() {
  int left = 1;
  int right = GAP_MAXVAL;
  int sol;

  while (left <= right) {
    int mid = (left + right) / 2;

    if (ok(mid)) {
      left = mid + 1;
      sol = mid; // sol은 항상 커지는 방향으로만 갱신됨
    }
    else {
      right = mid - 1;
    }
  }

  cout << sol;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  preset();
  solve();
}
