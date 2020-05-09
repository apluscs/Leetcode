class Solution {
public:
    int compareVersion(string v1, string v2) {
        int i=0,j=0,n=v1.length(),m=v2.length();
        while(i<n||j<m){
            int s1,e1,s2,e2;
            while(i<n&&v1[i]=='0')i++; // remove leading zeros
            s1=i;
            while(i<n&&v1[i]!='.')i++; // find end of number chain
            e1=i;
            while(j<m&&v2[j]=='0')j++;
            s2=j;
            while(j<m&&v2[j]!='.')j++;
            e2=j;
            // cout<<"e1="<<e1<<", s1="<<s1<<", e2="<<e2<<", s2="<<s2<<endl;
            if(e1-s1>e2-s2)return 1;
            if(e1-s1<e2-s2)return -1;    // otherwise same length
            while(s1<e1){
                if(v1[s1]>v2[s2])return 1;
                if(v1[s1]<v2[s2])return -1;
                s1++;   s2++;
            }
            i++;    j++;    // on a dot, now advance
        }
        return 0;
    }
};
