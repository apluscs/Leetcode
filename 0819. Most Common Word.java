class Solution {
    public String mostCommonWord(String para, String[] banned) {
        HashMap<String,Integer> frq=new HashMap<>();
        para+='.';  //in case in doesn't end with punctuation, this ensures last word will be processed
        for(String b:banned) frq.put(b,-1); //mark as banned
        int st=0;
        int max=0;
        String res="";
        for(int i=0;i!=para.length();i++){
            char c=para.charAt(i);
            if(c==' '||c=='!'||c=='?'||c==','||c==';'||c=='.'||c=='\''){    //end of word detected
                String word=para.substring(st,i).toLowerCase();
                st=i+1;
                if(word.length()==0||frq.get(word)!=null&&frq.get(word)==-1) continue;   
                //no word (ex. ", " would give an empty string) or banned word, don't process
                // System.out.println(word);
                frq.put(word,frq.getOrDefault(word,0)+1);   //update freq of this word
                int ct=frq.get(word);
                if(ct>max){ //if most frequent valid ord
                    max=ct;
                    res=word;
                }
            }
        }
        return res;
    }
}
