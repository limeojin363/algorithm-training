#include <iostream>
#include <cstring>
#include <vector>
#define STAFF_MAX 1001
#define TASK_MAX 1001

using namespace std;

bool staff_to_task[STAFF_MAX][TASK_MAX];
vector<int> s_match;
vector<int> t_match;
int n, m;
vector<bool> visited;

int dfs(int s) {
    if (visited[s]) return false;
    visited[s] = true;

    for (int t = 1; t <= m; t++) {
        if (staff_to_task[s][t]) {
            if (t_match[t] == -1 || dfs(t_match[t])) {
                t_match[t] = s;
                s_match[s] = t;
                return true;
            }
        }
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    for (int s = 1; s <= n; s++) {
        int k; cin >> k;
        for (int i = 0; i < k; i++) {
            int t; cin >> t;
            staff_to_task[s][t] = true;
        }
    }

    int ret = 0;
    s_match = vector<int>(n + 1, -1);
    t_match = vector<int>(m + 1, -1);
    for (int s = 1; s <= n; s++) {
        visited = vector<bool>(n + 1, false);
        if (dfs(s))
            ret++;
    }

    cout << ret;
}