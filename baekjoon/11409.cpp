#include <iostream>
#include <cassert>
#include <cstring>
#include <vector>
#include <queue>
#define COST_MAX 54321
#define CAPACITY_MAX 54321
#define STAFF_MAX 1001
#define TASK_MAX 1001

using namespace std;

int source = 0, sink = 1;
int cost[STAFF_MAX][TASK_MAX];
int capacity[STAFF_MAX][TASK_MAX];
int flow[STAFF_MAX][TASK_MAX];
vector<int> s_match;
vector<int> t_match;
int n, m;
vector<int> parent;
vector<int> d;

int staff_node(int num) {
    assert(num >= 1);
    assert(num <= n);

    // 2 ~ n + 1
    return num + 1;
}

int task_node(int num) {
    assert(num >= 1);
    assert(num <= m);

    // n + 2 ~ n + m + 1
    return num + n + 1;
}

void solve() {
    int total_task = 0;
    int total_salary = 0;

    int cnt = 0;
    while (1) {
        cnt++;
        // cout << "\n" << cnt << "번째 증가 경로 찾기" << "\n";
        vector<int> d(n + m + 2, COST_MAX);
        d[source] = 0;
        parent = vector<int>(n + m + 2, -1);
        queue<int> q;
        vector<bool> inQueue(n + m + 2, false);
        parent[source] = source;
        q.push(source);

        while (!q.empty()) {
            int curr = q.front(); q.pop();
            inQueue[curr] = false;
            for (int i = 0; i < n + m + 2; i++) {
                if (capacity[curr][i] - flow[curr][i] > 0) // 잔여 용량이 존재
                    if (d[curr] + cost[curr][i] < d[i]) // 비용 감소 가능
                    {
                        d[i] = d[curr] + cost[curr][i];
                        parent[i] = curr;
                        if (!inQueue[i]) {
                            inQueue[i] = true;
                            q.push(i);
                        }
                    }
            }
        }

        if (parent[sink] == -1) {
            // cout << "실패";
            break;
        }

        // cout << "성공:\n";
        int amount = 54321;
        int salary = 0;
        for (int curr = sink; curr != source; curr = parent[curr]) {
            amount = min(amount, capacity[parent[curr]][curr] - flow[parent[curr]][curr]);
        }
        for (int curr = sink; curr != source; curr = parent[curr]) {
            flow[parent[curr]][curr] += amount;z
            flow[curr][parent[curr]] -= amount;
            salary += cost[parent[curr]][curr];
            // cout << " " << parent[curr] << " -> " << curr << " 비용: " << cost[parent[curr]][curr] << " 잔여유량: " << capacity[parent[curr]][curr] - flow[parent[curr]][curr] << " /";
        }
        total_task += amount;
        total_salary += salary;
    }

    cout << total_task << "\n" << -total_salary;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    // 소스 -> 각 직원
    for (int s = 1; s <= n; s++) {
        cost[source][staff_node(s)] = cost[staff_node(s)][source] = 0;
        capacity[source][staff_node(s)] = capacity[staff_node(s)][source] = 1;
        flow[source][staff_node(s)] = flow[staff_node(s)][source] = 0;
    }
    // 각 업무 -> 싱크
    for (int t = 1; t <= m; t++) {
        cost[task_node(t)][sink] = cost[sink][task_node(t)] = 0;
        capacity[task_node(t)][sink] = capacity[sink][task_node(t)] = 1;
        flow[task_node(t)][sink] = flow[sink][task_node(t)] = 0;
    }
    // 각 직원 -> 각 업무
    for (int s = 1; s <= n; s++) 
        for (int t = 1; t <= m; t++) {
            cost[staff_node(s)][task_node(t)] = cost[task_node(t)][staff_node(s)] = COST_MAX;
            capacity[staff_node(s)][task_node(t)] = capacity[task_node(t)][staff_node(s)] = 0;
            flow[staff_node(s)][task_node(t)] = flow[task_node(t)][staff_node(s)] = 0;
        }
    // 각 직원 -> 각 업무(가능 여부 반영)
    for (int s = 1; s <= n; s++) {
        int k; cin >> k;
        for (int i = 0; i < k; i++) {
            int t, c; cin >> t >> c;
            capacity[staff_node(s)][task_node(t)] = 1;
            cost[staff_node(s)][task_node(t)] = -c;
            cost[task_node(t)][staff_node(s)] = c;
        }
    }

    solve();
}
