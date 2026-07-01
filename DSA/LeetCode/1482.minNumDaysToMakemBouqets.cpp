#include <algorithm>
#include <bits/stdc++.h>
#include <vector>
using namespace std;

class Solution {
public:
  int numOfBouqets(vector<int> &bloomDay, int day, int k) {
    int num = 0;
    int consecutiveBlooms = 0;
    for (int i = 0; i < bloomDay.size(); i++) {
      if (day >= bloomDay[i])
        consecutiveBlooms++;
      else {
        num += consecutiveBlooms / k;
        consecutiveBlooms = 0;
      }
    }
    num += consecutiveBlooms / k;
    return num;
  }
  int minDays(vector<int> &bloomDay, int m, int k) {
    long long numOfFlowersRequired = m * 1LL * k * 1LL;
    if (numOfFlowersRequired > bloomDay.size())
      return -1;
    int low = INT_MAX, high = INT_MIN;
    for (int i : bloomDay) {
      low = min(low, i);
      high = max(high, i);
    }
    while (low <= high) {
      int mid = low + (high - low) / 2;
      int bouqets = numOfBouqets(bloomDay, mid, k);
      if (bouqets >= m)
        high = mid - 1;
      else
        low = mid + 1;
    }
    return low;
  }
};
