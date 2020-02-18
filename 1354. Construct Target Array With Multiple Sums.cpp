// creds to https://www.acwing.com/file_system/file/content/whole/index/content/346168/
class Solution {
  public: #define LL long long
  bool isPossible(vector < int > & target) {
    priority_queue < LL > q(target.begin(), target.end());
    LL sum = 0;
    for (int t: target) sum += t;
    while (!q.empty()) {
      LL x = q.top();
      q.pop();

      if (x == 1) // everything below this is 1 as well
        return true;

      if (x <= sum - x || sum - x <= 0) // x should be the sum of everything, so should at least be > sum(all else)
        return false;
      // cout << x << ", sum : " << sum << endl;
      LL y = x % (sum - x); // in case all_else was added to x multiple times, this gives us the "starting" state of x
      // ex. 5, 13 --> original state is 5, 3
      sum = sum - x + y;
      q.push((int) y);
    }

    return true;
  }
};


// TLE on [1,1000000000]
class SolutionSLOW {
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

