/**
 * // This is the BinaryMatrix's API interface.
 * // You should not implement it, or speculate about its implementation
 * class BinaryMatrix {
 *   public:
 *     int get(int row, int col);
 *     vector<int> dimensions();
 * };
 */

class Solution {
public:

    int leftMostColumnWithOne(BinaryMatrix &binaryMatrix) {
        auto dimensions = binaryMatrix.dimensions();
        int n = dimensions[0], m = dimensions[1];

        int x = 0, y = m-1, ans = -1;
        while(x < n && y >= 0){
            if(binaryMatrix.get(x,y)) {
                ans = y;
                y--;
            }
            else x++;
        }

        return ans;
    }
};