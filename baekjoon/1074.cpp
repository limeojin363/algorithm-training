// https://www.acmicpc.net/problem/1074
// solved: 2025-10-11

#include <iostream>
#include <math.h>
#define N_MAX 15

using namespace std;

int daq(int p, int y, int x);

int n, r, c;

int daq(int p, int y, int x) {
    // base case
    if (p == 0) return 0;
    
    // 2의 p승을 4분할해서 구간(1 ~ 4) 결정
    int mid = pow(2, p) / 2;
    int square = pow(mid, 2);
    // 1구간
    if (x < mid && y < mid) {
        return square * 0 + daq(p - 1, y, x);
    }
    // 2구간
    if (x >= mid && y < mid) {
        return square * 1 + daq(p - 1, y, x - mid);
    }
    // 3구간
    if (x < mid && y >= mid) {
        return square * 2 + daq(p - 1, y - mid, x);
    }
    // 4구간
    if (x >= mid && y >= mid) {
        return square * 3 + daq(p - 1, y - mid, x - mid);
    }
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> r >> c;
    cout << daq(n, r, c);    
}