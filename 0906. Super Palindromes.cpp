class Solution {  // big takeaway: strings are costly (TLE), use math
public:
    int superpalindromesInRange(string L, string R) {
        long long l=stoll(L);
		long long r=stoll(R);
		int count=0;
		for(int i=0;i<1e5;i++){
			for(int type=0;type<2;type++){
				long long pal=constru(i,type);
				if(pal>1e9) continue;
				long long temp=pal*pal;
				if(temp>=l && temp<=r && isPalindrome(temp)) count++;
			}
		}

		return count;
    }
    long constru(int num, int type){
		long long x=num;
		long long y=num;
		if(type==1) x/=10;
		while(y>0){
			x=x*10+y%10;
			y/=10;
		}
		return x;
	}
    bool isPalindrome(long l) {
        string s = to_string(l);
        int i = 0, j = s.length() - 1;
        while (i < j) {
            if (s[i++] != s[j--]) {
                return false;
            }
        }
        return true;
    }
};
