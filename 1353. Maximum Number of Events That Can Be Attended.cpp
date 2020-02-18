class Solution {
  public:
    static bool compar(vector < int > a, vector < int > b) {
      return a[0] < b[0];
    }
  int maxEvents(vector < vector < int >> & intervals) {
    sort(intervals.begin(), intervals.end(), compar); // sort by ending time
    priority_queue < int, vector < int > , greater < int >> pq; // lowest floats to the top
    int i = 0, res = 0, N = intervals.size(), time = -1;
    while (i != N || !pq.empty()) {
      while (!pq.empty() && pq.top() < time) // remove all expired events
        pq.pop();
      if (i != N && pq.empty()) // fast forward to next event
        time = intervals[i][0];
      while (i != N && intervals[i][0] == time)
        pq.push(intervals[i++][1]); // push all events that have started
      if (!pq.empty()) { // choose the event that expires first
        pq.pop();
        res++;
      }
      time++; // new day
    }
    return res;
  }
};
