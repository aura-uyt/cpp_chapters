#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int numOfDays(vector<int> &weights, int capacity) {
    int days = 1;
    int laod = 0;
    for (int i : weights) {
      laod += i;
      if (laod > capacity) {
        laod = i;
        days++;
      }
    }
    return days;
  }
  int shipWithinDays(vector<int> &weights, int days) {
    int low = *max_element(weights.begin(), weights.end());
    int high = accumulate(weights.begin(), weights.end(), 0);

    while (low <= high) {
      int mid = low + (high - low) / 2;
      int loading_days = numOfDays(weights, mid);
      if (loading_days <= days)
        high = mid - 1;
      else
        low = mid + 1;
    }
    return low;
  }
};
