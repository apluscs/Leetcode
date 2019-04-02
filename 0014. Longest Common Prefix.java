class Solution {
    public String longestCommonPrefix(String[] strs) {
        String res="";  int i=0;
        if(strs.length==0 || strs[0].length() == 0) return res;
        while(true){
            char co=strs[0].length()!=i?strs[0].charAt(i):'0';  //nothing will match with '0' (if first string is too long)
            for(String s:strs) if(s.length()==i || s.charAt(i) != co) return res;
            res+=co;
            i++;
        }
    }
}
