class Solution {
  public:

    static bool compar(vector < int > a, vector < int > b) {
      return a[1] != b[1] ? a[1] < b[1] : a[0] < b[0];
    }
  int eraseOverlapIntervals(vector < vector < int >> & intervals) {
    sort(intervals.begin(), intervals.end(), compar); // sort by ending time
    int N = intervals.size(), end = INT_MIN, res = 0;
    if (N == 0) return 0;
    for (int i = 0; i != N; ++i) {
      if (intervals[i][0] >= end) { // we discard all intervals that are incompatible with end
        end = intervals[i][1]; // end is always earliest finishing interval compatible with others, 
        // makes sense since as soon as we finish this one we can explore others
        res++; // one more compatible interval
      }
    }
    return N - res;
  }
};
