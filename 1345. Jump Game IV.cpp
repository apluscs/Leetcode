class Solution {
  public:
    int minJumps(vector < int > & arr) {
      unordered_map < int, vector < int >> same;
      int res = 0, N = arr.size();
      queue < int > que;
      vector < bool > vis(N);
      que.push(0);

      for (int i = 0; i != N; ++i)
        same[arr[i]].push_back(i); // key = value, value = all indices that have that value

      while (!que.empty()) {
        int size = que.size();
        for (int i = 0; i != size; ++i) {
          int curr = que.front();
          que.pop();
          if (curr == N - 1) return res;
          vis[curr] = true;
          if (curr != 0 && !vis[curr - 1])
            que.push(curr - 1);
          if (!vis[curr + 1]) // no need to check if curr == N-1
            que.push(curr + 1);
          for (int nei: same[arr[curr]]) // indices of same-value items
            if (!vis[nei])
              que.push(nei);
          same[arr[curr]].clear(); // no need to ever add these again, since they've been put into the queue once
        }
        res++;
      }
      return res;
    }
};
