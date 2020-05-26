class Solution {
  public:

    static bool compar(const vector < int > & a,
      const vector < int > & b) {
      return a[0] != b[0] ? a[0] < b[0] : a[1] > b[1]; // ascending by start, descending by end
    }
  int removeCoveredIntervals(vector < vector < int >> & intervals) {
    int res = 0, end = -1, N = intervals.size();
    sort(intervals.begin(), intervals.end(), compar);
    for (int i = 0; i != N; ++i) {
      if (intervals[i][1] > end) { // found a new leader who ends later
        end = intervals[i][1];
        res++;
      } // else interval i is guaranteed to start >= the leader's start, and we know if ends <= end, so it is covered by leader
    }
    return res;
  }
};
