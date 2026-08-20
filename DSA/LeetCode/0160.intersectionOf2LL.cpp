#include <bits/stdc++.h>
#include <set>
using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
  ListNode *brute2(ListNode *headA, ListNode *headB) {
    ListNode *pA = headA;
    ListNode *pB = headB;
    while (pA) {
      while (pB) {
        if (pA == pB)
          return pA;
        pB = pB->next;
      }
      pA = pA->next;
      pB = headB;
    }
    return nullptr;
  }
  ListNode *bruteForce(ListNode *headA, ListNode *headB) {
    ListNode *pA = headA;
    ListNode *pB = headB;
    set<ListNode *> store;
    while (pA) {
      store.insert(pA);
      pA = pA->next;
    }
    while (pB) {
      if (store.find(pB) != store.end())
        return pB;
      store.insert(pB);
      pB = pB->next;
    }
    return nullptr;
  }
};