typedef vector<int> vi;
typedef vector<vi> vvi;
class Solution {
public:
    auto findNumSmaller(vvi& matrix, int num){
        int m = matrix.size(), n = matrix[0].size();
        int count = 0, maxNum = matrix[0][0], j = n-1;
        for(int i = 0; i < m && j >= 0; i++){
            while(j >= 0 && matrix[i][j] > num) j--;
            count += (j+1);
            if(j >= 0) maxNum = std::max(maxNum, matrix[i][j]);

        }

        return make_pair(count, maxNum);
    }

    int kthSmallest(vector<vector<int>>& matrix, int k) {
        if(k == 1) return matrix[0][0];
        int m = matrix.size(), n = matrix[0].size();
        if(k == m*n) return matrix[m-1][n-1];

        /* Make end exclusive */
        double lo = matrix[0][0], hi = matrix[n-1][m-1];
        /* Normally binary search
         * Key insight is count can never be bigger than k 
         * if the current value doesn't exist - otherwise
         * when we shrink it would no longer meet the threshold
         */
        while(lo <= hi){
            int m = (lo + hi)/2;
            auto p = findNumSmaller(matrix, m);
            // cout << "lo:" << lo << ", hi:" << hi << ", p:" << p.first<< endl;
            if(p.first < k) lo = m+1;
            else if(p.first > k) hi = m-1;
            else return p.second;
        }

        return lo;
    }
};