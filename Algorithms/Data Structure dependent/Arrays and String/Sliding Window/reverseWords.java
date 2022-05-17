public class Solution {
    private void reverseWord(char[] str, int start, int end){
        while(start<end){
            char c = str[start];
            str[start] = str[end];
            str[end] = c;
            start++; end--;
        }
    }

    private int findSpace(char[] str, int i){
        while(i < str.length && str[i] != ' '){
            i++;
        }
        if(i == str.length-1) i++;
        return i;
    }
    /**
     * @param str: a string
     * @return: return a string
     */
    public char[] reverseWords(char[] str) {
        reverseWord(str, 0, str.length-1);
        int start=0;
        while(start<str.length){
            int space = findSpace(str, start);
            reverseWord(str, start, space-1);
            start = space+1;
        }
        return str;
    }
}