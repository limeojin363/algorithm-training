#include <iostream>
#include <vector>

using namespace std;

int n, q, s, e;
vector<int> sequence;
vector<int> xored_sequence;
// XOR 연산 포함 여부

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> q;

    sequence = vector<int>(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        cin >> sequence[i];
    }
    
    xored_sequence = vector<int>(n + 1, 0);
    xored_sequence[1] = sequence[1];
    for (int i = 2; i <= n; i++) {
        xored_sequence[i] = xored_sequence[i - 1] ^ sequence[i];
    }

    int curr;
    cin >> s >> e;
    curr = s == 1 ? xored_sequence[e] : xored_sequence[e] ^ xored_sequence[s - 1];
    for (int i = 0; i < q - 1; i++) {
        cin >> s >> e;
        curr ^= s == 1 ? xored_sequence[e] : xored_sequence[e] ^ xored_sequence[s - 1];
    }

    cout << curr;
}