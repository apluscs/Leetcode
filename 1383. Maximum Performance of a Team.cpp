class Solution {
public:
    
    struct Engin{
        int s, e;
        Engin(int s, int e) : s(s), e(e) {}
        void print() const {
            cout << s << ", " << e << endl;
        }
        
        bool operator <(const Engin & other) const{
            return e > other.e;
        }
    };
	
    struct compar{
        bool operator ()(const Engin & player1, const Engin & player2){
            return player1.s > player2.s;
        }
    };
    
    int maxPerformance(int N, vector<int>& speed, vector<int>& efficiency, int K) {
        vector<Engin> engins(N, Engin(0,0));
        for(int i = 0; i != N; ++i)
            engins.push_back(Engin(speed[i], efficiency[i]));
        sort(engins.begin(), engins.end()); // descending efficiency
        long res = 0, sum = 0;
        priority_queue<Engin, vector<Engin>, compar> pq;    // ascending on speed, top = slowest
        for(int i = 0; i != N; ++i){    // each time, threshold for efficiency lowers
            pq.push(engins[i]);
            sum += engins[i].s;
            if(pq.size() > K){ 
                sum -= pq.top().s;  	// could be engins[i], but this person leaving will not affect future loops
                pq.pop();
            }
            res = max(res, sum * engins[i].e);  // result with engineer i in 
        }
        return res % long(1e9 + 7);
    }
};
