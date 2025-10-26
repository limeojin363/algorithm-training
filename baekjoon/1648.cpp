#include <iostream>
#include <cstring>

using namespace std;

int n, m;
int cache[14 * 14][(1 << 14) - 1];

int dp(int cell_num, int status) {
    if (cell_num == n * m) return 1;

    int& ret = cache[cell_num][status];
    if (ret != -1) return ret;

    if (status & (1 << 0)) return ret = dp(cell_num + 1, status >> 1);

    ret = 0;
    // 마지막 행이 아님 -> 수직 놓기 가능
    bool vertical_ok = (cell_num / m) < (n - 1);
    // 마지막 열이 아니고, 다음 셀이 비어 있음 -> 수평 놓기 가능
    bool horizontal_ok = ((cell_num % m) < (m - 1)) && !(status & (1 << 1));

    if (vertical_ok)
        ret += dp(cell_num + 1, (status >> 1) | (1 << (m - 1))) % 9901;
    if (horizontal_ok)
        ret += dp(cell_num + 2, status >> 2) % 9901;
    // cout << "A " << cell_num << " " << status << "\n";
    // cout << "B " << vertical_ok << " " << horizontal_ok << "\n";
    // cout << "C " << ret << "\n";
    return ret = ret % 9901;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    memset(cache, -1, sizeof(cache));
    cout << dp(0, 0);
}