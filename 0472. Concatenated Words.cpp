class Solution {
    public:
        vector < string > findAllConcatenatedWordsInADict(vector < string > & words) {
            unordered_set < string > set(words.begin(), words.end());
            vector < string > res;
            for (string w: words) {
                int N = w.size();
                vector < int > dp(N + 1);
                dp[0] = 1; //one way to make the empty string
                for (int i = 0; i != N; i++) {
                    if (dp[i] == 0) continue; //we know we can make everything <= i
                    for (int j = i + 1; j <= N; j++) { //can we tack on anything else?
                        if (j - i < N && set.count(w.substr(i, j - i))) dp[j] = 1;
                    }
                    if (dp[N]) {
                        res.push_back(w);
                        break;
                    }
                }
            }
            return res;
        }
};

class SolutionTLE {
    public:
        vector < string > findAllConcatenatedWordsInADict(vector < string > & words) {
            vector < string > res;
            for (int i = words.size() - 1; i != -1; i--) {
                if (words[i] == "") words.erase(words.begin() + i);
            }
            sort(words.begin(), words.end(), compar);
            for (string w: words) {
                if (w == "") continue;
                if (helper(w, w, words)) res.push_back(w);
            }
            // helper("dogcatsdog", "dogcatsdog",words);
            return res;
        }

    bool helper(string curr, string og, vector < string > & words) {
        int N = curr.length();
        // cout<<curr<<endl;
        for (string w: words) {
            int M = w.length();
            // cout<<"possible? "<<w<<" "<<curr<<endl;
            if (w == curr && curr != og) {
                // cout<<"NICE: "<<curr<<" "<<og<<endl;
                return true;
            }
            if (M > N) break;

            if (w == curr.substr(0, M) && helper(curr.substr(M), og, words))
                return true;
        }
        return false;
    }

    static bool compar(string & w1, string & w2) {
        return w1.length() < w2.length();
    }

};
