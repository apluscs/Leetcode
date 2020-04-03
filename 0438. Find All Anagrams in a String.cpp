class Solution {
public:
    vector<int> findAnagrams(string s2, string s1) {
        int total_diff = 0, N = s2.length(), M = s1.length();
        vector<int> frq(26);    // total_diff tracks the sum of all absolute values of frq's elems
        vector<int> res;
        if(N < M) return res;
        for(char c: s1){
            frq[c - 'a']++;
            total_diff++;   
        }
        
        for(int i = 0; i != M; ++i){
            int c = s2[i] - 'a';
            if(frq[c] <= 0)
                total_diff++;   // getting more negative   
            else // positive getting closer to 0
                total_diff--;
            frq[c]--;
        }
        
        if(total_diff == 0) 
            res.push_back(0);   // first M chars of s2 are s1

        for(int i = M; i != N; ++i){
            int c = s2[i - M] - 'a';    // kick out the oldest in the window
            if(frq[c] < 0)
                total_diff--;   // negative getting closer to 0
            else // getting more positive
                total_diff++;
            frq[c]++;
            
            c = s2[i] - 'a';    // add in a new char to the window
            if(frq[c] <= 0)
                total_diff++;   // getting more negative   
            else // positive getting closer to 0
                total_diff--;
            frq[c]--;
            
            if(total_diff == 0)
                res.push_back(i - M + 1);   // starting index of last M chars
        }
        return res; // check the last one
    }
};
