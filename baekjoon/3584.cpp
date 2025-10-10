#include <iostream>
#include <vector>

#define NODE_MAX 10001

using namespace std;

class Node {
public:
  int num;
  Node* parent = NULL;
  int get_height() {
    if (!this->parent) return 0;
    return 1 + this->parent->get_height();
  }
};

Node* tree[NODE_MAX];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int t; cin >> t;
  while (t--) {
    int n; cin >> n;

    for (int i = 1; i <= n; i++) {
      if (tree[i])
        delete tree[i];

      tree[i] = new Node();
      tree[i]->num = i;
    }

    for (int i = 0; i < n - 1; i++) {
      int a, b;
      cin >> a >> b;

      tree[b]->parent = tree[a];
    }

    int c1, c2;
    cin >> c1 >> c2;

    Node* node1 = tree[c1];
    Node* node2 = tree[c2];

    int diff = node1->get_height() - node2->get_height();
    while (diff != 0) {
      if (diff > 0) {
        node1 = node1->parent;
        diff--;
      }
      else {
        node2 = node2->parent;
        diff++;
      }
    }

    int height = node1->get_height();
    while (node1 != node2) {
      node1 = node1->parent;
      node2 = node2->parent;
    }

    cout << node1->num << "\n";
  }
}