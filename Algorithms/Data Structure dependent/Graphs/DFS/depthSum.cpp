/**
 * class NestedInteger {
 *   public:
 *     NestedInteger();
 *     NestedInteger(int value);
 *     bool isInteger() const;
 *     int getInteger() const;
 *     void setInteger(int value);
 *     void add(const NestedInteger &ni);
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class Solution {
public:
    int depthSum(vector<NestedInteger>& nestedList, int depth){
        int sum = 0;
        for(auto &nestedInt : nestedList ){
            if(nestedInt.isInteger()) sum += nestedInt.getInteger() * depth;
            else sum += depthSum(nestedInt.getList(), depth+1);
        }
        return sum;
    }
    int depthSum(vector<NestedInteger>& nestedList) {
        return depthSum(nestedList, 1);
    }
};