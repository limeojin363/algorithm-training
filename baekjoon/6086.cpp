#include <bits/stdc++.h>

using namespace std;

int n;
int flow[52][52];
int capacity[52][52];

// 0 -> 25
int maxFlow()
{
    int source = 0, sink = 25;
    int totalFlow = 0;

    while (1) {
        vector<int> parent(52, -1);
        queue<int> q;
        parent[source] = source;
        q.push(source);

        while (!q.empty() && parent[sink] == -1) {
            int curr = q.front(); q.pop();
            for (int i = 0; i < 52; i++) {
                int remainder = capacity[curr][i] - flow[curr][i];

                if (remainder > 0 && parent[i] == -1) {
                    parent[i] = curr;
                    q.push(i);
                }
            }
        }

        if (parent[sink] == -1)
            break;

        int amount = 1001;

        for (int curr = sink; curr != source; curr = parent[curr]) {
            amount = min(amount, capacity[parent[curr]][curr] - flow[parent[curr]][curr]);
        }

        
        for (int curr = sink; curr != source; curr = parent[curr]) {
            flow[parent[curr]][curr] += amount;
            flow[curr][parent[curr]] -= amount;
        }
        totalFlow += amount;
    }

    return totalFlow;
}

int cToNum(char c)
{
    if (c >= 'A' && c <= 'Z')
        return c - 'A'; // 0 ~ 25
    else
        return c - 'a' + 26; // 26 ~ 51
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    memset(flow, 0, sizeof(flow));
    memset(capacity, 0, sizeof(capacity));

    cin >> n;
    for (int i = 0; i < n; i++) {
        char a, b; int f;
        cin >> a >> b >> f;

        int deparatureNode = cToNum(a);
        int destinationNode = cToNum(b);

        capacity[deparatureNode][destinationNode] += f;
        capacity[destinationNode][deparatureNode] += f;
    }

    cout << maxFlow();
}
