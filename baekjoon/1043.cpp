#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
#define PARTY_MAX 51
#define PEOPLE_MAX 51

using namespace std;

int n, m, temp;
int table[PEOPLE_MAX][PEOPLE_MAX];
int visited[PEOPLE_MAX];
vector<int> who_knows_truth;
vector<int> party[PARTY_MAX];

int main() {
    cin >> n >> m;
    // 진실을 아는 사람들 받기
    cin >> temp;
    for (int i = 0; i < temp; i++) {
        int man; cin >> man;
        who_knows_truth.push_back(man);
    }
    // 파티별 인원 받기
    for (int i = 0; i < m; i++) {
        cin >> temp;
        for (int j = 0; j < temp; j++) {
            int man; cin >> man;
            party[i].push_back(man);
        }
    }
    // 그래프 모델링(인접 테이블)
    // 같은 파티에 속해 있으면 연결된 간선이 있다
    memset(table, 0, sizeof(table));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < party[i].size() - 1; j++) 
            for (int k = j + 1; k < party[i].size(); k++) {
                int a = party[i][j], b = party[i][k];
                table[a][b] = table[b][a] = 1;
            }
    }
    // vistied 초기화
    memset(visited, 0, sizeof(visited));
    // 진실을 아는 사람들과 연결되는 사람들을 bfs로 구함
    for (int i = 0; i < who_knows_truth.size(); i++) {
        queue<int> q;
 
        int node = who_knows_truth[i];
        if (visited[node]) continue;

        q.push(node);
        visited[node] = 1;

        while (!q.empty()) {
            int node1 = q.front(); q.pop();
            for (int node2 = 1; node2 <= n; node2++) {
                if (!table[node1][node2]) continue;
                if (visited[node2]) continue;

                q.push(node2);
                visited[node2] = 1;
            }
        }
    }
    // 답 출력: 구성원들의 vistied가 전부 0인 파티 개수
    int res = 0;
    for (int i = 0; i < m; i++) {
        bool ok = true;
        for (int j = 0; j < party[i].size(); j++) {
            int node = party[i][j];
            if (visited[node]) {
                ok = false;
                break;
            }
        }
        if (ok) res++;
    }
    cout << res;
}