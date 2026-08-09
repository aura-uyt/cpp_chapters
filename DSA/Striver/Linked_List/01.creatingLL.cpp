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

class LinkedList {
private:
  Node *head;

public:
  LinkedList() { head->next = nullptr; }

  void convertArrayToLL(vector<int> &arr) {
    if (arr.size() == 0)
      return;
    head = new Node(arr[0]);
    Node *ptr = head;
    for (int i = 1; i < arr.size(); i++) {
      ptr->next = new Node(arr[i]);
      ptr = ptr->next;
    }
  }
  void display() {
    Node *ptr = head;
    while (ptr != nullptr) {
      cout << ptr->data << " ";
      ptr = ptr->next;
    }
    cout << "\n";
  }
};

int main() {
  vector<int> arr = {2, 5, 8, 9};
  Node *x = new Node(arr[0], nullptr);
  Node *y = new Node(arr[1]);
  cout << x->data << " -> " << y->data << "\n";
  LinkedList ll1;
  ll1.convertArrayToLL(arr);
  ll1.display();

  return 0;
}
