class Solution {  // faster
  public:

    vector < int > topKFrequent(vector < int > & nums, int k) {
      vector < int > res;
      map < int, int > frq;
      for (int num: nums)
        frq[num]++;
      int N = frq.size();
      priority_queue < pair < int, int >> pq;
      for (pair p: frq) {
        pq.push(make_pair(p.second, p.first));
        if (pq.size() > N - k) { // more than bottom N-k elems
          pair top = pq.top();
          pq.pop(); // this one isn't in the bottom part, so it must be in the top k
          res.push_back(top.second); // actual value
        }
      }
      return res;
    }
};

class Solution2 {
  public:
    static bool compar(pair < int, int > a, pair < int, int > b) {
      return get < 0 > (a) > get < 0 > (b); // reverse order in terms of first item
    }

  vector < int > topKFrequent(vector < int > & nums, int k) {
    vector < int > res;
    map < int, int > frq;
    for (int num: nums)
      frq[num]++;
    vector < pair < int, int >> frqs;
    for (auto p: frq)
      frqs.push_back(make_pair(p.second, p.first)); // frequency, value
    sort(frqs.begin(), frqs.end(), compar);
    for (int i = 0; i != k; ++i)
      res.push_back(get < 1 > (frqs[i])); // [0] is frequency
    return res;
  }
};
