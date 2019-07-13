class Node { //trienode
    Node[] kids = new Node[26];
}
class Solution {
    int res; //goal is to group all words with same suffix into one group, only count the length of the longest member in that group
    public int minimumLengthEncoding(String[] words) {
        Node root = new Node();
        res = 0;
        for (String s: words) {
            Node curr = root;
            for (int i = s.length() - 1; i != -1; i--) { //backwards, end of trie chain is beginning of a word
                int c = s.charAt(i) - 'a';
                if (curr.kids[c] == null) curr.kids[c] = new Node();
                curr = curr.kids[c];
            }
        }
        dfs(root, 1); //starts at 1 to account for #
        return res;
    }
    void dfs(Node curr, int len) {
        boolean found = false; //initialization necessary?
        for (int i = 0; i != 26; i++)
            if (curr.kids[i] != null) {
                // System.out.println((char)(i+'a')+" "+len);
                dfs(curr.kids[i], len + 1);
                found = true;
            }
        if (!found) res += len; //reached beginning of larget word ending with the common prefix
    }
}
