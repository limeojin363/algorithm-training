#include <iostream>
#include <cstring>
#include <algorithm>
#include <climits>

using namespace std;

int n;
int cache[500][500];
pair<int,int> matrix[500];

int dp(int start, int end) {
    int& ret = cache[start][end];
    if (ret != -1) return ret;

    if (start == end)
        return ret = 0;

    ret = INT_MAX;
    
    // i ~ i + 1을 마지막에 연산
    for (int i = start; i + 1 <= end; i++) {
        ret = min(ret, matrix[start].first * matrix[i].second * matrix[end].second + dp(start, i) + dp(i + 1, end));
    }

    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> matrix[i].first >> matrix[i].second;
    memset(cache, -1, sizeof(cache));

    cout << dp(0, n - 1);
}