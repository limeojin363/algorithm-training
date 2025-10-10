#include <bits/stdc++.h>
#define TASK_MAXNUM 100001

using namespace std;

void preset();
int get_prev_max_time(int a);
void solve();

int n; // 전체 노드 개수
int task_time[TASK_MAXNUM];
vector<int> entries[TASK_MAXNUM];
int cache[TASK_MAXNUM];

void preset() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> task_time[i];
        int cnt; cin >> cnt;

        for (int j = 0; j < cnt; j++)
        {
            // dp에서 원래 방향과 반대 방향으로 탐색하도록
            int temp; cin >> temp;
            entries[i].push_back(temp);
        }
    }
}

int prev_max_time(int a) {
    int& ret = cache[a];
    if (ret != -1)
        return ret;

    ret = 0;
    for (int i = 0; i < entries[a].size(); i++) {
        int now = entries[a][i];
        ret = max(ret, task_time[now] + prev_max_time(now));
    }

    return ret;
}

void solve() {
    memset(cache, -1, sizeof(cache));

    int sol = 0;
    for (int i = 1; i <= n; i++)
        sol = max(sol, task_time[i] + prev_max_time(i));

    cout << sol;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    preset();
    solve();
}
