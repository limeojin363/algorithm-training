// https://www.acmicpc.net/problem/1003

#include <iostream>
#include <stdexcept>
#include <cstring>
#define LEN 41

using namespace std;

int dp(int num);

int cache_zero[LEN];
int cache_one[LEN];
int t;

int dp_zero(int num) {
    if (num < 0) throw runtime_error("num is less than zero");

    int& ret = cache_zero[num];
    if (ret != -1) return ret;

    if (num == 0) return ret = 1;
    if (num == 1) return ret = 0;

    return ret = dp_zero(num - 1) + dp_zero(num - 2);
}

int dp_one(int num) {
    if (num < 0) throw runtime_error("num is less than zero");

    int& ret = cache_one[num];
    if (ret != -1) return ret;

    if (num == 0) return ret = 0;
    if (num == 1) return ret = 1;

    return ret = dp_one(num - 1) + dp_one(num - 2);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> t;
    while (t--) {
        int n; cin >> n;
        
        memset(cache_zero, -1, sizeof(cache_zero));
        memset(cache_one, -1, sizeof(cache_one));

        cout << dp_zero(n) << " " << dp_one(n) << "\n";
    }
}
