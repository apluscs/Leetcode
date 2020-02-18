// TLE on [1,1000000000]
class Solution {
  public:
    bool isPossible(vector < int > & target) {
      priority_queue < int > pq(target.begin(), target.end());
      int sum = accumulate(target.begin(), target.end(), 0);
      while (!pq.empty()) {
        int curr = pq.top();
        pq.pop();
        int other = curr - (sum - curr); // sum of all other elems in target
        cout << "curr: " << curr << ", other: " << other << endl;
        cout << "sum: " << sum << endl;
        sum = sum - curr + other;
        if (other == 1) continue; // reached starting state
        if (other <= 0) return false;
        pq.push(other);
      }
      return true;
    }
};

