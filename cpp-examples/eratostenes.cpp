#include <iostream>
#include <vector>

using namespace std;

void eratosthenes(int n) {
    vector<bool> is_prime(n + 1, true); // 소수 여부를 저장하는 배열
    is_prime[0] = is_prime[1] = false; // 0과 1은 소수가 아님

    for (int i = 2; i * i <= n; ++i) {
        if (is_prime[i]) {
            for (int j = i * i; j <= n; j += i) {
                is_prime[j] = false; // i의 배수는 소수가 아님
            }
        }
    }

    // 소수 출력
    for (int i = 2; i <= n; ++i) {
        if (is_prime[i]) {
            cout << i << " ";
        }
    }
    cout << endl;
}

int main() {
    int n;
    cout << "Enter the value of n: ";
    cin >> n;

    eratosthenes(n);

    return 0;
}