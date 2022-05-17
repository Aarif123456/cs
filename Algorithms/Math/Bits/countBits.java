class Solution {
    public int[] countBits(int n) {
        if (n<=0) return new int[]{0};
        int[] arr = new int[n+1];
        arr[1] = 1;
        for(int range=2; range<=n; range*=2){
            int prevRange = range/2;
            for(int i=prevRange; i< range; i++){
                /* Copy previous range as is */
                 if(i+prevRange <= n) arr[i+prevRange] =  arr[i];
                /* add one more one two previous range*/
                if(i+range <= n) arr[i+range] =  arr[i]+1;
                // System.out.println("i:"+i+"\nval:"+arr[i]+"\n_____________________");
            }
        }

        // for(int x: arr){
        //     System.out.print(x+",");
        // }
        // System.out.println();
        return arr;
    }
}