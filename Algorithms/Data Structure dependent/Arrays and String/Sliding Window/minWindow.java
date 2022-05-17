class Solution {
    public String minWindow(String s, String t) {
        if(t.length()>s.length()) return "";
        /*Create initial valid window */
        Map<Character, Integer> letterCount = new HashMap<>();
        for(char c: s.toCharArray()){
            letterCount.putIfAbsent(c, 0);
        }
        for(char c: t.toCharArray()){
            letterCount.putIfAbsent(c, 0);
        }
        for(char c: t.toCharArray()){
            letterCount.replace(c, letterCount.get(c)+1);
        }

        /*********************************************/
        int count=t.length(), start=0, end=0;
        int minLength = Integer.MAX_VALUE;
        int bestStart = -1;

        while(end<s.length()){
            /*Go till we find a valid substring */
            if(count>0){
                char c = s.charAt(end);
                if(letterCount.get(c) > 0) count--;
                letterCount.replace(c, letterCount.get(c)-1);
                end++;
            }
            /* We shrunk window until it is no longer valid by moving up the left pointer */
            for(;start < end && count == 0; start++ ){
                char c  = s.charAt(start); 
                int curLength = end-start;
                if(curLength <= minLength){
                    bestStart = start;
                    minLength = curLength;
                }
                if(letterCount.get(c) == 0) count++;
                letterCount.replace(c, letterCount.get(c)+1);
            } 
        }
        
        if(bestStart == -1) return "";

        return s.substring(bestStart, bestStart+minLength);

    }
}