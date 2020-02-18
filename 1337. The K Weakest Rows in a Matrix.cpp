class Solution {
  public:

    class CompareDist {
      public:
        bool operator()(const pair < int, int > & n1,
          const pair < int, int > & n2) { // strongest at top
          return n1.second != n2.second ? n1.second < n2.second : n1.first < n2.first;
        }
    };

  vector < int > kWeakestRows(vector < vector < int >> & mat, int k) {
    priority_queue < pair < int, int > , vector < pair < int, int >> , CompareDist > pq;
    vector < int > res(k);
    for (int i = 0; i != mat.size(); ++i) {
      vector < int > & row = mat[i];
      int val = count_soldiers(row);
      if (pq.size() < k || val < pq.top().second)
        pq.push(make_pair(i, val));
      if (pq.size() > k) pq.pop(); // pop strongest row so far to maintain k weakest so far
    }
    for (int i = 0; i != k; ++i) {
      auto curr = pq.top();
      res[k - i - 1] = curr.first; // strongest go at back of res
      pq.pop();
    }
    return res;
  }

    int count_soldiers(vector<int>& row){
        int low = 0, high = row.size() - 1;
        while(low <= high){
            int mid = (low + high) / 2;
            if(row[mid] == 1) low = mid + 1;
            else high = mid - 1;
        }
        return low; // first "0"
    }
};
