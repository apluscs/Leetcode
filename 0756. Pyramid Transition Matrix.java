class Solution {
    HashMap < String, String > map;
    public boolean pyramidTransition(String bottom, List < String > allowed) {
        map = new HashMap < > ();
        for (String s: allowed) {
            String k = s.substring(0, 2);
            if (!map.containsKey(k)) map.put(k, "");
            map.put(k, map.get(k) + s.charAt(2)); //map tracks all chars that can fall on top of the key (String) as an adjacent pair
        }
        // for (Map.Entry<String, String> entry : map.entrySet()) {
        //     String key = entry.getKey();
        //     Object value = entry.getValue();
        //     System.out.println(key+" "+value);
        // } 
        return helper(bottom);
    }
    public boolean helper(String base) {
        int N = base.length();
        if (N == 1) return true;
        // for(int i=0;i!=N-1;i++)
        if (!map.containsKey(base.substring(i, i + 2))) return false;
        List < String > layer = new ArrayList < > (); //if we had genLayers() return a List<String>, we'd have to somehow track when we've reached the last char of the last pair in base
        genLayers(base, new StringBuilder(), layer, 0);
        for (String s: layer)
            if (helper(s)) return true; //don't just return helper(s); if false, we should try other arrangements
        return false;
    }

    public void genLayers(String base, StringBuilder sb, List < String > res, int ind) {
        if (ind == base.length() - 1) { //no right hand partner
            //System.out.println(sb.toString());  
            res.add(sb.toString());
            return;
        }
        for (char c: map.get(base.substring(ind, ind + 2)).toCharArray()) {
            sb.append(c);
            genLayers(base, sb, res, ind + 1); //ind is starting index of pair we're building on top of
            sb.deleteCharAt(ind);
        }
    }
}
