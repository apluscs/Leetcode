class Solution {
    public List < List < Integer >> largeGroupPositions(String S) {
        List < List < Integer >> res = new LinkedList < > ();
        int N = S.length(), i = 0;
        while (i != N) { //i is start of group
            int j = i + 1;
            while (j != N && S.charAt(j) == S.charAt(i)) j++;
            if (j - i >= 3) {
                List < Integer > group = new ArrayList < > ();
                group.add(i);
                group.add(j - 1); //j-1 is last index of large group
                res.add(group);
            }
            i = j; //this group is finished, i is start of immediately next group
        }
        return res;
    }
}
