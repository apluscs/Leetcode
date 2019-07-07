class Solution {
    public List < String > subdomainVisits(String[] cpdomains) {
        HashMap < String, Integer > map = new HashMap < > ();
        for (String cd: cpdomains) {
            int sp = cd.indexOf(" "); //space index
            int ct = Integer.parseInt(cd.substring(0, sp)); //count of visits
            cd = cd.substring(sp + 1);
            while (true) {
                // System.out.println(cd);
                map.put(cd, map.getOrDefault(cd, 0) + ct); //adds ct to existing count for this subdomain
                int dt = cd.indexOf('.'); //dot index
                if (dt == -1) break; //processed highest power subdomain (last one)
                cd = cd.substring(cd.indexOf('.') + 1);
            }
        }
        List < String > res = new ArrayList < > ();
        for (Map.Entry < String, Integer > ent: map.entrySet()) {
            res.add(ent.getValue() + " " + ent.getKey());
        }
        return res;
    }
}
