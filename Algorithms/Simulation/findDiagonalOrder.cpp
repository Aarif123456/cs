class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        bool goingUp = true;
        int i = 0, j = 0;
        vector<int> out;
        while(i != m-1 || j != n-1){
            out.push_back(mat[i][j]);
            if(goingUp){
                if(j == n-1){
                    goingUp = false;
                    i++;
                }
                else if(i == 0){
                    goingUp = false;
                    j++;
                }
                else{
                    /* up and right is - up diagonal */
                    i--;
                    j++;
                }
            }
            else{
                if(i == m-1){
                    goingUp = true
                    j++;
                }
                else if(j == 0){
                    goingUp = true;
                    i++;
                }
                else{
                    /* down and left is - down diagonal */
                    i++;
                    j--;
                }
            }
        }
        out.push_back(mat[i][j]);

        return out;
    }
};