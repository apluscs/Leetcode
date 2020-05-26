class Solution {
public:
    vector<string> nums = {"zero", "wto", "ufor", "xsi", "geiht", "htree", "five", "vseen", "one", "inne"}; // identifying letter put first
    vector<char> digits = {'0', '2', '4', '6', '8', '3', '5', '7', '1', '9'};   // corresponding chars
    string originalDigits(string str) {
        unordered_map<char, int> frq;
        for(char c : str)   // count frqs of each letter
            frq[c]++;
        string res = "";
        vector<int> frqs(10, 0);
        for(int i = 0; i != 10; ++i){
            string num = nums[i];
            char c = digits[i];
            int f = frq[num[0]];    // frq of identifying letter
            frqs[c - '0'] = f;
            if(f == 0)  
                continue;
            helper(frq, num, f);     // remove all string num's from str
        }
        for(int i = 0; i != 10; ++i)    // coutning sort, put back correct amounts of each char
            add_nums(res, (char)(i + '0'), frqs[i]);
        return res;
    }
    
    void helper(unordered_map<char, int>& frq, string str, int f){
        for(char c : str)
            frq[c] -= f;
    }
    
    void add_nums(string& res, char c, int f){
        for(int i = 0; i != f; ++i)
            res += c;
    }
};


