#include <iostream>
#include <math.h>

using namespace std;

int s, n, k, l;
int e[100001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> s >> n;
    for (int i = 0; i < n; i++)
        cin >> e[i];
    cin >> k >> l;

    int res_index = -1;
    int res_cost = 100000 * 10000;

    for (int i = 0; i < n; i++) {
        int dist = abs(e[i] - s);
        int cost;
        if (dist >= k * 2)
            cost = (dist - k * 2) * l;
        else
            cost = k * 2 - dist;
        
        if (cost < res_cost) { 
            res_cost = cost;
            res_index = i + 1;
        }
    }

    cout << res_cost << " " << res_index;
}