class Solution {
public:

    struct compar{
        bool operator()(const pair<int,char>& a, const pair<int,char>& b){
            return a.first > b.first;
        }  
    };
    
    string longestDiverseString(int a, int b, int c) {
        string res = "";
        vector<pair<int,char>> ops = {make_pair(a, 'a'), make_pair(b, 'b'), make_pair(c, 'c')};
        sort(ops.begin(), ops.end(), compar());   // most frequent char at the front
        while(true){
            bool found = false;
            for(int i = 0; i != 3; ++i){
                if(try_add(res, ops[i], i)){   // will modify ops[i]
                    found = true;   // able to add to res
                    break;
                }
            }
            sort(ops.begin(), ops.end(), compar()); // resort
            if(!found) break;   // unable to add to res, we done
        }
        return res;
    }
    
    bool try_add(string& res, pair<int,char>& p, int i){
        int N = res.length();
        char c = p.second;
        if(p.first < 1 || (N >= 2 && res.back() == c && res[N - 2] == c)) return false; // cannot add c
        p.first = p.first - 1;
        res += c; // don't add 2 in a row of any char that's not the most frequent
        if(i != 0 || p.first < 1 || (N >= 2 && res[N - 1] == c && res[N - 2] == c)) return true;    
        p.first = p.first - 1;
        res += c;
        return true;
    }
};

