class Solution {
    public int openLock(String[] deadends, String target) {
        HashSet < String > vis = new HashSet < > ();
        int round = 0;
        for (String d: deadends) vis.add(d);
        Queue < String > que = new LinkedList < > ();
        que.add("0000");
        while (!que.isEmpty()) {
            int size = que.size();
            for (int j = 0; j != size; j++) {
                String str = que.poll();
                // System.out.println(str);
                StringBuilder curr = new StringBuilder(str); //worth the time cost (95ms --> 132ms with substring())
                if (str.equals(target)) return round;
                if (vis.contains(str)) continue;
                vis.add(str);
                for (int i = 0; i != 4; i++) {
                    char c = curr.charAt(i);
                    if (c == '0') {
                        curr.setCharAt(i, '9');
                        que.add(curr.toString());
                        curr.setCharAt(i, '1');
                        que.add(curr.toString());
                        curr.setCharAt(i, '0'); //for future chars in the string
                    } else if (c == '9') {
                        curr.setCharAt(i, '8');
                        que.add(curr.toString());
                        curr.setCharAt(i, '0');
                        que.add(curr.toString());
                        curr.setCharAt(i, '9');
                    } else {
                        curr.setCharAt(i, (char)(c - 1));
                        que.add(curr.toString());
                        curr.setCharAt(i, (char)(c + 1));
                        que.add(curr.toString());
                        curr.setCharAt(i, c);
                    }
                }
            }
            round++;
        }
        return -1;
    }
}
