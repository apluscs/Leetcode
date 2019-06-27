class Solution {
    public int numMatchingSubseq(String key, String[] words) {
        int K = key.length(), N = words.length, res = 0;
        Queue < String > [] next = new Queue[26]; //type declared on left
        for (int i = 0; i != 26; i++) next[i] = new LinkedList < String > ();
        for (int i = 0; i != N; i++) next[words[i].charAt(0) - 'a'].add(words[i]);
        for (int i = 0; i != K; i++) {
            int c = key.charAt(i) - 'a';
            for (int j = next[c].size(); j != 0; j--) { //cannot do while(llist not empty) because repeated chars "bb" may give a false pos
                String curr = next[c].poll();
                if (curr.length() == 1) { //entire word found
                    // System.out.println(curr);
                    res++;
                    continue;
                }
                curr = curr.substring(1); //focus is on next char not found
                next[curr.charAt(0) - 'a'].add(curr); //faster in that it only hits on the chars that are found
            }
        }
        return res;
    }
}
