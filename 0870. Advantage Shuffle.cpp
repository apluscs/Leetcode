class Solution {
    public:
        static bool compar(vector < int > & v, vector < int > & u) {
            return v[0] < u[0];
        }
    vector < int > advantageCount(vector < int > & A, vector < int > & B) {
        int N = A.size(), ind = 0;
        unordered_set < int > unplaced;
        vector < int > res(N);
        vector < vector < int >> Barr(N, vector < int > (2));
        for (int i = 0; i != N; i++) {
            Barr[i][0] = B[i];
            Barr[i][1] = i; //track original index of this value at B
            unplaced.insert(i);
        }
        sort(Barr.begin(), Barr.end(), compar); //sort but keep track of indexes
        sort(A.begin(), A.end());
        // for(vector<int> b:Barr) cout<<b[0]<<", "<<b[1]<<'\t';
        // cout<<endl;

        for (int i = 0; i != N; i++) {
            // cout<<ind<<endl;
            while (ind != N && A[ind] <= Barr[i][0]) {
                ind++;
            } //find smallest val in A greater than Barr[i]
            if (ind == N) break;
            res[Barr[i][1]] = A[ind]; //place at original index 
            unplaced.erase(ind);
            ind++; //we already used this current index
        }

        // for(int r:res)cout<<r<<", ";
        // cout<<endl;
        ind = 0;
        for (unordered_set < int > ::iterator it = unplaced.begin(); it != unplaced.end(); it++) {
            while (ind != N && res[ind] != 0) ind++; //find next spot in res w/o a value
            int num = A[ * it]; //put first unplaced val here
            res[ind] = num;
        }
        return res;
    }


};
