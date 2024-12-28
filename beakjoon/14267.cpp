#include <bits/stdc++.h>
#define N_MAX 100000

using namespace std;

void preset();
void solve();
int get_total(int num);

int n, m;
int direct[N_MAX + 1];
int cache[N_MAX + 1];
int amount_from_direct[N_MAX + 1];

int get_total(int num) {
    if (num == 1)
        return 0;
        
    int& ret = cache[num];
    if (ret != -1)
        return ret;

    return ret = amount_from_direct[num] + get_total(direct[num]);
}

void preset()
{
    memset(amount_from_direct, 0, sizeof(amount_from_direct));
    memset(cache, -1, sizeof(cache));
    
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> direct[i];
    while (m--) {
        int workman, compliment;
        cin >> workman >> compliment;
        amount_from_direct[workman] += compliment;
    }
    
}

void solve() {
    for (int i = 1; i <= n; i++)
        cout << get_total(i) << " ";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    preset();
    solve();
}
