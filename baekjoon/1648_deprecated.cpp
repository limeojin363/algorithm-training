#include <iostream>
#include <cstring>
#include <set>

using namespace std;

int n, m;
int cache[15][20000];

void get_next_list(int row_num, int curr_col_state, int next_col_state, set<int>* list);

bool is_cell_filled(int col_state, int num) {
    return col_state & (1 << num);
}

void get_next_list(int row_num, int curr_col_state, int next_col_state, set<int>* list) {
    // base case: 초과 도달(해당 열이 다 채워짐)
    if (row_num == n) {
        list->insert(next_col_state);
        return;
    }

    // 해당 셀이 채워져 있는 경우 - 다음 행으로 패스
    if (is_cell_filled(curr_col_state, row_num)) {
        return get_next_list(row_num + 1, curr_col_state, next_col_state, list);
    }

    // 열의 마지막 셀인 경우
    if (row_num == n - 1 || is_cell_filled(curr_col_state, row_num + 1)) {
        return get_next_list(row_num + 1, curr_col_state | (1 << row_num), next_col_state | (1 << row_num), list);
    }

    get_next_list(row_num + 1, curr_col_state | (1 << row_num), next_col_state | (1 << row_num), list);
    get_next_list(row_num + 2, curr_col_state | (3 << row_num), next_col_state, list);
}

int dp(int col_num, int col_state) {
    int& ret = cache[col_num][col_state];
    if (ret != -1) return ret;

    // base case: 마지막 열
    if (col_num == m - 1) {
        int i = 0;
        while (1) {
            // 초과 도달
            if (i == n)
                return 1;

            // 셀이 채워져 있지 않음
            if (!is_cell_filled(col_state, i)) {
                // 다음 칸이 유효(보드 바깥으로 벗어나지 않음)하고, 채워져 있지 않음 -> 두 칸 연달아 채우기 성공
                if ((i + 1 <= n - 1) && !is_cell_filled(col_state, i + 1)) {
                    i += 2;
                    continue;
                }
                // 두 칸 연달아 채우기 실패
                return 0;
            }
            // 셀이 채워져 있음 -> 다음 칸으로 넘어가기
            else {
                i++;
                continue;
            }
        }
    }

    // 투입한 도미노 개수 + 다음 열의 상태별로 dp 함수 계속 호출
    set<int> list;
    get_next_list(0, col_state, 0, &list);
    ret = 0;
    // cout << col_num << " " << col_state << " - next_list: ";
    for (int item: list) {
        // cout << "ITEM: " << item << " ";
        ret += dp(col_num + 1, item) % 9901;
    }
    // cout << col_num << " " << col_state << " - next_list: ";
    // cout << "\n";

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