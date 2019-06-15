class Solution {
    public boolean canTransform(String start, String end) {
        if (!start.replace("X", "").equals(end.replace("X", ""))) return false; //order and freq must be the same
        char[] sar = start.toCharArray(), ear = end.toCharArray();
        int ps = 0, pe = 0, N = start.length();
        while (true) {
            while (ps != N && sar[ps] == 'X') ps++;
            while (pe != N && ear[pe] == 'X') pe++;
            // System.out.println(ps+" "+pe);
            if (ps == N || pe == N) return true; //visited all instances of 'R' and 'L'
            if (ear[pe] == 'R' && pe < ps) return false; //'R' needs to move left
            if (ear[pe] == 'L' && pe > ps) return false; //'L' needs to move right, can never happen
            ps++;
            pe++;
        }
        // return false; //should never happen
    }
} //can be improved by doing charAt() instead iterating over .toCharArray() 
//  first check for order and freq can be done in while loop
