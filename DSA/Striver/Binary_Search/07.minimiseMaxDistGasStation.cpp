#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

int gasStationsPlaced(vector<int> &arr, int dist) {
  int count = 0;
  for (int i = 0; i < arr.size() - 2; i++) {
    long double adjDist = arr[i + 1] - arr[i];
    int stn = adjDist / dist;
    if (stn * dist == adjDist)
      count += (stn - 1);
    else
      count += stn;
  }
  return count;
}
double optimal(vector<int> &arr, int k) {
  // ans will be btw 0 & maxAdjDist
  // dist can max be minimised to 0, but for that infinited k will be needed
  long double low = 0;
  // maximum can be this bcz we have to reduce this dist by placing stations
  long double high = 0;
  for (int i = 0; i <= arr.size() - 2; i++) // finding maxAdjDist
    high = max(high, (long double)(arr[i + 1] - arr[i]));

  // bcz problem states that Answers within 10^-6 of the actual answer will be
  // accepted Mans ans will be checked upto 6th decimal place, so need to find
  // ans until that
  long double diff = 1e-6;
  while (high - low > diff) {
    long double mid = low + (high - low) / 2.0;
    int gasStn = gasStationsPlaced(arr, mid);
    if (gasStn > k)
      low = mid;
    else
      high = mid;
  }
  // at this point low & high will be almost same, bcz diff
  // btw them would have been less that 10^-6 for the while loop to end
  return low;
}

double better(vector<int> &arr, int k) {
  int n = arr.size();
  vector<int> howMany(n - 1, 0);
  priority_queue<pair<long double, int>> adjDist;
  for (int i = 0; i <= n - 2; i++)
    adjDist.push({(long double)(arr[i + 1] - arr[i]), i});

  for (int i = 1; i <= k; i++) {
    auto it = adjDist.top();
    adjDist.pop(); // removed top element
    int index = it.second;
    howMany[index]++;
    long double dist = (long double)(arr[index + 1] - arr[index]) /
                       (long double)(howMany[index + 1]);
    adjDist.push({dist, index});
  }
  return adjDist.top().first;
}

double bruteForce(vector<int> &arr, int k) {
  int n = arr.size();
  vector<int> howMany(n - 1, 0);
  for (int gasStn = 1; gasStn <= k; gasStn++) {
    long double maxAdjDist = -1;
    int maxAdjDistIndex = -1;
    for (int i = 0; i <= n - 2; i++) {
      long double adjDist = arr[i + 1] - arr[i];
      adjDist /= (long double)(howMany[i] + 1);
      // doing this, bcz we may have placed a gas station, btw them
      if (adjDist > maxAdjDist) {
        maxAdjDist = adjDist;
        maxAdjDistIndex = i;
      }
    }
    howMany[maxAdjDistIndex]++;
  }
  long double maxAdjDist = -1;
  for (int i = 0; i <= n - 2; i++) {
    long double adjDist = arr[i + 1] - arr[i];
    adjDist /= (long double)(howMany[i] + 1);
    maxAdjDist = max(maxAdjDist, adjDist);
  }
  return maxAdjDist;
}
