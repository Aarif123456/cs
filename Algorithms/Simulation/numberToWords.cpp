class Solution {
public:
        const string ONES[20] = {"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
        const string TENS[11] = {"", "Ten", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety", "Hundred"};
    string helper(int num){

        if(num >= 1000000000000) return helper(num/1000000000000)+ "Trillion " + helper(num%1000000000000);
        if(num >= 1000000000) return helper(num/1000000000)+ "Billion " + helper(num%1000000000);
        if(num >= 1000000) return helper(num/1000000)+ "Million " + helper(num%1000000);
        if(num >= 1000) return helper(num/1000)+ "Thousand " + helper(num%1000);
        if(num >= 100) return helper(num/100) +  "Hundred " + helper(num%100);
        if(num >= 20) return TENS[num/10] + " " + helper(num%10);
        if(num >= 1) return ONES[num] + " ";
        return "";
    }
    string numberToWords(int num) {
        if(!num) return "Zero";
        auto s = helper(num);
        return s.substr(0, s.length()-1);
    }
};