#include <iostream>
#include <vector>
#include <cstring>
#include <unordered_map>
#include <cassert>
#include <bitset>

using namespace std;

unordered_map<string, int> value_map {
    {"AA", 10},
    {"AB", 8},
    {"AC", 7},
    {"AD", 5},
    {"AF", 1},
    {"BB", 6},
    {"BC", 4},
    {"BD", 3},
    {"BF", 1},
    {"CC", 3},
    {"CD", 2},
    {"CF", 1},
    {"DD", 2},
    {"DF", 1},
    {"FF", 0},
};

int n, m;
int cache[15 * 15][(1 << 14)];
char board[15][15];

int get_tofu_value(int cell1, int cell2) {
    int r1 = cell1 / m;
    int c1 = cell1 % m;
    int r2 = cell2 / m;
    int c2 = cell2 % m;
    assert(r1 >= 0 && r1 < n && c1 >= 0 && c1 < m);
    assert(r2 >= 0 && r2 < n && c2 >= 0 && c2 < m);

    // cout << cell1 << " " << r1 << " " << c1 << " " << cell2 << " "   << r2 << " " << c2 << "\n";

    char rank1 = board[r1][c1];
    char rank2 = board[r2][c2];
    if (rank1 > rank2) {
        char temp = rank1;
        rank1 = rank2;
        rank2 = temp;
    }

    string total_rank = "";
    total_rank += rank1;
    total_rank += rank2;


    return value_map[total_rank];
}

int dp(int cell_num, int status) {
    if (cell_num == n * m) return 0;

    int& ret = cache[cell_num][status];
    if (ret != -1) return ret;
    
    ret = dp(cell_num + 1, status >> 1);

    if (status & (1 << 0)) {
        // cout << "cell_num: " << cell_num << " status: " << bitset<18>(status) << " ret: " << ret << "\n";
        return ret;
    }

    // 마지막 행이 아님 -> 수직 놓기 가능
    bool vertical_ok = (cell_num / m) < (n - 1);
    // 마지막 열이 아니고, 다음 셀이 비어 있음 -> 수평 놓기 가능
    bool horizontal_ok = ((cell_num % m) < (m - 1)) && !(status & (1 << 1));

    if (vertical_ok)
        ret = max(ret, get_tofu_value(cell_num, cell_num + m) + dp(cell_num + 1, (status >> 1) | (1 << (m - 1))));
    if (horizontal_ok)
        ret = max(ret, get_tofu_value(cell_num, cell_num + 1) + dp(cell_num + 2, status >> 2));

    // cout << "cell_num: " << cell_num << " status: " << bitset<18>(status) << " ret: " << ret << "\n";
    return ret;
}

int main() {
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    // cout.tie(NULL);

    cin >> n >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> board[i][j];


    memset(cache, -1, sizeof(cache));

    cout << dp(0, 0);
}