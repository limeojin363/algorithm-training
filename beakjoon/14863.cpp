#include <bits/stdc++.h>
#define N_MAX 100
#define K_MAX 100000

using namespace std;

void preset();
void solve();
int get_maximum_money(int route_num, int remaining_time);

int n, k;
// 시간, 모금액 순서
pair<int, int> by_working[N_MAX];
pair<int, int> by_cycle[N_MAX];
int cache[N_MAX][K_MAX + 1];

int get_maximum_money(int route_num, int remaining_time)
{
    if (remaining_time < 0)
        return INT_MIN;

    // base case: 남은 시간이 0 이상인 채로 끝
    if (route_num == n)
        return 0;

    int &ret = cache[route_num][remaining_time];
    if (ret != -1)
        return ret;

    return ret = max(get_maximum_money(route_num + 1, remaining_time - by_working[route_num].first) + by_working[route_num].second,
            get_maximum_money(route_num + 1, remaining_time - by_cycle[route_num].first) + by_cycle[route_num].second);
}

void preset()
{
    cin >> n >> k;
    for (int i = 0; i < n; i++)
        cin >> by_working[i].first >> by_working[i].second >> by_cycle[i].first >> by_cycle[i].second;

    memset(cache, -1, sizeof(cache));
}

void solve()
{
    cout << get_maximum_money(0, k);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    preset();    
    solve();
}
