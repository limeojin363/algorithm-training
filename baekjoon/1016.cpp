// 에라토스테네스의 체 변형

#include <iostream>
#include <string.h>

using namespace std;

int is_mul_of_prime[1000001];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  memset(is_mul_of_prime, 0, sizeof(is_mul_of_prime));
  long long minimum, maximum;
  cin >> minimum >> maximum;

  for (long long i = 2; (i <= 1000000) && ((i * i) <= maximum); i++)
    for (long long j = (minimum / (i * i)); (j * (i * i)) <= maximum; j++) {
      if (j * (i * i) < minimum)
        continue;

      is_mul_of_prime[j * (i * i) - minimum] = 1;
    }


  int res = maximum - minimum + 1;
  for (int i = 0; i <= maximum - minimum; i++)
    res -= is_mul_of_prime[i];

  cout << res;
}
