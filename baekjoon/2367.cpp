#include <iostream>
#include <cstring>
#include <vector>
#include <cassert>
#include <queue>
#define NODE_MAX 302

using namespace std;

int n, k, d;
int flow[NODE_MAX][NODE_MAX];
int capacity[NODE_MAX][NODE_MAX];

int source = 0;
int sink = 1;

int people_node(int num) {
    assert(num >= 1);
    assert(num <= n);
    
    // 2 ~ (n + 1)
    return num + 1;
}

int dish_node(int num) {
    assert(num >= 1);
    assert(num <= d);
    
    // (n + 2) ~ (n + d + 1)
    return num + n + 1;
}

int max_flow() {
    int total = 0;
    while (1) {
        vector<int> parent(n + d + 2, -1);
        queue<int> q;
        parent[source] = source;
        q.push(source);

        // 증가 경로 찾기
        while (!q.empty() && parent[sink] == -1) {
            int curr = q.front(); q.pop();
            for (int i = 0; i < n + d + 2; i++) {
                int r = capacity[curr][i] - flow[curr][i];
                if (r > 0 && parent[i] == -1) {
                    parent[i] = curr;
                    q.push(i);
                }
            }
        }

        if (parent[sink] == -1)
            break;

        int amount = 123456;
        for (int curr = sink; curr != source; curr = parent[curr])
            amount = min(amount, capacity[parent[curr]][curr] - flow[parent[curr]][curr]);

        for (int curr = sink; curr != source; curr = parent[curr]) {
            flow[parent[curr]][curr] += amount;
            flow[curr][parent[curr]] -= amount;
        }
        total += amount;
    }

    return total;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> k >> d;
    // source -> 각 사람
    for (int i = 1; i <= n; i++) {
        capacity[source][people_node(i)] = k;
    }
    // 각 음식 -> sink
    for (int i = 1; i <= d; i++) {
        cin >> capacity[dish_node(i)][sink];
    }
    for (int i = 1; i <= n; i++) {
        int z; cin >> z;
        while (z--) {
            int dish; cin >> dish;
            capacity[people_node(i)][dish_node(dish)] = 1;
        }
    }

    cout << max_flow();
}
