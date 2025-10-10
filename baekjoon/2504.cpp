// #include <iostream>
// #include <string>
// #include <queue>
// #include <stack>
// #define PARENTHESES_OPEN '('
// #define PARENTHESES_CLOSE ')'
// #define BRACKETS_OPEN '['
// #define BRACKETS_CLOSE ']'

// using namespace std;

// bool is_opener(char x) {
//   return x == PARENTHESES_OPEN || x == BRACKETS_OPEN;
// }
// bool is_closer(char x) {
//   return x == PARENTHESES_CLOSE || x == BRACKETS_CLOSE;
// }
// bool is_matching(char x, char y) {
//   return (x == PARENTHESES_OPEN && y == PARENTHESES_CLOSE)
//     || (x == BRACKETS_OPEN || y == BRACKETS_CLOSE);
// }

// int main() {
//   ios_base::sync_with_stdio(false);
//   cin.tie(NULL);
//   cout.tie(NULL);

//   string input; cin >> input;
//   stack<char> s;
//   queue<char> q;

//   int res = 0;
//   int now = 0;
//   char recently_popped = 0;
//   bool is_valid = true;
//   for (int i = 0; i < input.length(); i++) {
//     // 닫는 괄호
//     if (is_closer(input[i])) {
//       if (!s.empty() && is_matching(s.top(), input[i])) {
//         int t = s.top();
//         s.pop();

//         if (i == 0 || is_closer(recently_popped))
//           if (input[i] == PARENTHESES_CLOSE)
//             now += 2;
//           else
//             now += 3;
//         else
//           if (input[i] == PARENTHESES_CLOSE)
//             now *= 2;
//           else
//             now *= 3;

//         if (s.empty()) {
//           res += now;
//           now = 0;
//         }

//         recently_popped = t;
//       }
//       else {
//         is_valid = false;
//         break;
//       }
//     }
//     // 여는 괄호
//     else
//       s.push(input[i]);
//   }

//   if (!s.empty())
//     is_valid = false;

//   if (!is_valid)
//     cout << 0;
//   else
//     cout << res;
// }