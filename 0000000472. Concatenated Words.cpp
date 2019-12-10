

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
