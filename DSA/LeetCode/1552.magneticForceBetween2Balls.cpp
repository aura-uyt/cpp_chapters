#include <algorithm>
#include <bits/stdc++.h>
#include <vector>
using namespace std;

class Solution {
public:
  bool canWePlace(vector<int> &position, int cows, int dist) {
    int cowsCounter = 1;
    int lastPosition = position[0];
    for (int i = 1; i < position.size(); i++) {
      if (position[i] - lastPosition >= dist) {
        cowsCounter++;
        lastPosition = position[i];
      }
    }
    if (cowsCounter >= cows)
      return true;
    else
      return false;
  }
  int maxDistance(vector<int> &position, int cows) {
    sort(position.begin(), position.end());
    int low = 1, high = position[position.size() - 1] - position[0];
    while (low <= high) {
      int mid = low + (high - low) / 2;
      if (canWePlace(position, cows, mid))
        low = mid + 1;
      else
        high = mid - 1;
    }
    return high;
  }
};
