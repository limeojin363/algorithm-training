#include <iostream>
#include <string.h>
#define MAX 1000000

using namespace std;

int is_prime[1000001];
int n, m;

void eratostenes() {
  memset(is_prime, 1, sizeof(is_prime));
  is_prime[0] = is_prime[1] = 0;

  for (int i = 2; i * i <= MAX; i++)
    if (is_prime[i])
      for (int j = i * i; j <= MAX; j += i)
        is_prime[j] = 0;
}

void print_sol() {
  for (int i = n; i <= m; i++)
    if (is_prime[i])
      cout << i << "\n";
}

int main() {
  cin >> n >> m;
  eratostenes();
  print_sol();
}