class Solution {
public:
    bool isPalindrome(string s) {
        int N = s.length();
        transform(s.begin(), s.end(), s.begin(), ::tolower); 
        int i = 0, j = N - 1;
        while(i < j){
            while(i < j && !islower(s[i]) && !isdigit(s[i]))
                i++;    // advance to nearest valid char
            while(j > i && !islower(s[j]) && !isdigit(s[j]))
                j--;    // same here
            if(s[i] != s[j])
                return false;
            i++;
            j--;
            
        }
        return true;
    }
};
