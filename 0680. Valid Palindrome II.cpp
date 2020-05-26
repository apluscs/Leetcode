class Solution {
public:
    bool validPalindrome(string s) {
        int N = s.length(), i = 0, j = N - 1;
        while(i < j){
            if(s[i] != s[j]){
                // need to check both possibilites(ex."babcba")
                return isValidPal(s, i, j - 1) || isValidPal(s, i + 1, j);
            } 
            i++;
            j--;            
        }
        return true;
    }
    
    bool isValidPal(string& s, int i, int j){
        while(i < j){
            if(s[i] != s[j]) return false;
            i++;
            j--;
        }
        return true;
    }
};
