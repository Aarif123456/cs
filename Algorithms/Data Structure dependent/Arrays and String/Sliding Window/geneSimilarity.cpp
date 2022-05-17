typedef long long ll; 
class Solution {
public:
    /**
     * @param Gene1: a string
     * @param Gene2: a string
     * @return: return the similarity of two gene fragments
     */
    int getNumber(string &gene, int & index){
        string number = "0";
        while(index < gene.length() && isdigit(gene[index])) {
            number += gene[index];
            index++;
        }
        return stoi(number);
    }
    string GeneSimilarity(string &Gene1, string &Gene2) {
        char cur1='A', cur2='A';
        int num1=0, num2=0;
        int index1=0, index2=0;
        ll sim=0, dif=0;
        while(index1 < Gene1.length() || index2 < Gene2.length()){
            if(num1 == 0 && index1 < Gene1.length()){
                num1 = getNumber(Gene1, index1);
                /* The function points to the first index after we get the number */
                cur1 = Gene1[index1++];
            }
            if(num2 == 0 && index2 < Gene2.length()){
                num2 = getNumber(Gene2, index2);
                cur2 = Gene2[index2++];
            }
            auto minVal = min(num1, num2);
            if(cur1 == cur2) sim += minVal;
            else dif += minVal;
            num1 -= minVal;
            num2 -= minVal;
        }
        return to_string(sim) + "/" + to_string(dif+sim);
    }
};