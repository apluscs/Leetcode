class Solution {  //TLE, will fix
    public int openLock(String[] deadends, String target) {
        HashSet<String> vis=new HashSet<>();
        int round=0;
        for(String d:deadends) vis.add(d);
        Queue<String> que=new LinkedList<>();
        que.add("0000");
        while(!que.isEmpty()){
            int size=que.size();
            for(int j=0;j!=size;j++){
                String str=que.poll();
                System.out.println(str);
                StringBuilder curr=new StringBuilder(str);
                if(str.equals(target)) return round;
                vis.add(str);
                for(int i=0;i!=4;i++){
                    char c=curr.charAt(i);
                    if(c=='0'){
                        curr.setCharAt(i,'9');
                        if(!vis.contains(curr.toString())) que.add(curr.toString());
                        curr.setCharAt(i,'1');  
                        if(!vis.contains(curr.toString())) que.add(curr.toString());
                        continue;
                    }else if(c=='9'){
                        curr.setCharAt(i,'8');
                        if(!vis.contains(curr.toString())) que.add(curr.toString());
                        curr.setCharAt(i,'0');  
                        if(!vis.contains(curr.toString())) que.add(curr.toString());
                        continue;
                    }
                    curr.setCharAt(i,(char)(c-1)); 
                    if(!vis.contains(curr.toString())) que.add(curr.toString());
                    curr.setCharAt(i,(char)(c+1));  
                    if(!vis.contains(curr.toString())) que.add(curr.toString());
                }
            }
            round++;
        }
        return -1;
    }
}
