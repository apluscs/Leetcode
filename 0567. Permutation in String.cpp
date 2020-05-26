class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int total_diff = 0, N = s2.length(), M = s1.length();
        if(N < M) return false;
        vector<int> frq(26);    // total_diff tracks the sum of all absolute values of frq's elems
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

        for(int i = M; i != N; ++i){
            if(total_diff == 0) return true;
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
        }
        return total_diff == 0; // check the last one
    }
};
