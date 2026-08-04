#include <bits/stdc++.h>
using namespace std;

// struct & class works same also follow same syntax, only difference is class
// brings OOPs features
class Node {
public:
  int data;
  int age;
  Node *next;

  Node(int data) {
    this->data = data;
    this->next = nullptr;
  }
  Node(int data, Node *next) {
    this->data = data;
    this->next = next;
  }
};

int main() {
  vector<int> arr = {2, 5, 8, 9};
  Node *x = new Node(arr[0], nullptr);
  Node *y = new Node(arr[1]);
  cout << x->data << y->data << "\n";
  cout << sizeof(Node);

  return 0;
}
