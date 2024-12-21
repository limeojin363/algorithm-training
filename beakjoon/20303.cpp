// 2차원 dp가 안된다고 한다 하..

// #include <iostream>
// #include <queue>
// #include <vector>
// #include <string.h>

// using namespace std;

// int dp(int idx, int crying_kids_num);

// int n, m, k;
// int c[30010];
// int visited[30010];
// int set_number[30010];
// typedef struct {
//   int number_of_kids = 0;
//   int number_of_candies = 0;
// } Set_info;
// Set_info set_info[30010];
// vector<int> adj_list[30010];

// void input() {
//   cin >> n >> m >> k;

//   for (int i = 1; i <= n; i++)
//     cin >> c[i];

//   for (int i = 0; i < m; i++)
//   {
//     int src, dest;
//     cin >> src >> dest;
//     adj_list[src].push_back(dest);
//     adj_list[dest].push_back(src);
//   }
// }

// void execute_bfs() {
//   int kid_idx = 1, set_idx = 1;
//   for (int i = 1; i <= n; i++)
//     set_info[set_idx] = { 0, 0 };

//   while (kid_idx <= n) {
//     if (!visited[kid_idx]) {
//       queue<int> q = {};
//       visited[kid_idx] = true;
//       q.push(kid_idx);
//       set_info[set_idx].number_of_kids++;
//       set_info[set_idx].number_of_candies += c[kid_idx];

//       while (!q.empty()) {
//         int now = q.front();
//         q.pop();

//         for (int i = 0; i < adj_list[now].size(); i++) {
//           int visit_target = adj_list[now][i];
//           if (!visited[visit_target]) {
//             visited[visit_target] = true;
//             q.push(visit_target);
//             set_info[set_idx].number_of_kids++;
//             set_info[set_idx].number_of_candies += c[visit_target];
//           }
//         }
//       }

//       set_idx++;
//     }

//     kid_idx++;
//   }

//   // for (int i = 1; set_info[i].number_of_candies != 0; i++) {
//   //   cout << i << "set_info[i].number_of_candies: " << set_info[i].number_of_candies << "set_info[i].number_of_kids: " << set_info[i].number_of_kids << "\n";
//   // }
// }

// int cache[30010][3010];

// int dp(int idx, int crying_kids_num) {
//   int& ret = cache[idx][crying_kids_num];
//   if (ret != -1)
//     return ret;

//   if (set_info[idx].number_of_candies == 0)
//     return ret = 0;

//   if (crying_kids_num + set_info[idx].number_of_kids >= k)
//     return ret = dp(idx + 1, crying_kids_num);

//   return ret = max(
//     dp(idx + 1, crying_kids_num),
//     set_info[idx].number_of_candies +
//     dp(idx + 1, crying_kids_num + set_info[idx].number_of_kids));
// }


// void print_solution() {
//   // cout << "\n";

//   // for (int i = 1; i <= n && set_info[i].number_of_candies != 0; i++) {
//   //   cout << set_info[i].number_of_candies << " " << set_info[i].number_of_kids << "\n";
//   // }

//   // cout << "\n";

//   memset(cache, -1, sizeof(cache));

//   int sol = dp(1, 0);
//   // for (int i = 1; i <= 10; i++) {
//   //   for (int j = 0; j <= 10; j++)
//   //   {
//   //     cout << cache[i][j] << " ";
//   //   }
//   //   cout << "\n";
//   // }
//   cout << sol;
// }

// int main() {
//   ios_base::sync_with_stdio(false);
//   cin.tie(NULL);
//   cout.tie(NULL);

//   input();
//   execute_bfs();
//   print_solution();
// }