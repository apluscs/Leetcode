class Solution {
public:
    string res; int total;
    string getPermutation(int n, int k) {
        string curr = "";
        res = ""; 
        total = 1;  int temp = 1;
        while(temp <= n){
            total *= temp;  // total is n!
            curr += ('0' + temp);   // all chars from '1' to 'n'
            temp++;
        }
        k--;    // 0 -index K
        while(n != 0){
            int a = (total / n), b = k / a, c = k % a; // a is "chunk" size, b is what chunk, c is k after this chunk
            res +=  curr[b];
            curr[b] = curr.back();  // 'move' curr[b] to the end
            curr.pop_back();    // remove curr[b]
            sort(curr.begin(), curr.end()); // maintain sorted order
            total /= n;
            n--;    // one less character
            k = c;
        }
        return res;
    }
};
