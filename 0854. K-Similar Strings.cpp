class Solution {
    public:
        int kSimilarity(string A, string B) {
            unordered_map < string, int > dist;
            queue < string > que;
            int res = -1, N = A.length();
            que.push(A);
            dist[A] = 0;
            while (true) {
                int size = que.size();
                res++;
                for (int i = 0; i != size; i++) {
                    string curr = que.front();
                    que.pop();
                    int d = dist[curr];
                    if (!curr.compare(B)) return d; //found something that matches B
                    // cout<<curr<<'\t';
                    for (string nei: neighbors(curr, B))
                        if (dist.count(nei) == 0) { //if not already in array
                            dist[nei] = d + 1;
                            que.push(nei);
                        }
                }
            }
            return -1; //should never happen
        }

    vector < string > neighbors(string curr, string target) { //much better than blindly do all possible swaps (<-- TLE)
        vector < string > res;
        int i = 0, N = curr.length();
        while (i != N)
            if (curr[i] != target[i++]) break; //i = first inconsistency
        i--;
        for (int j = i + 1; j != N; j++)
            if (curr[j] == target[i]) //fix that inconsistency using whatever you can from res
                res.push_back(swap(curr, i, j));
        return res;
    }

    string swap(string str, int j, int k) {
        string temp = str;
        char t = temp[j];
        temp[j] = temp[k];
        temp[k] = t;
        return temp;
    }
};
