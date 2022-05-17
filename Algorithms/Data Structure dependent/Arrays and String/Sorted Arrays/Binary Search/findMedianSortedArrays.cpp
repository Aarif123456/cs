class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        /* Search in smaller array because it is more efficient and logic is simpler */
        if(nums1.size() > nums2.size()) return findMedianSortedArrays(nums2, nums1);
        if(nums1.empty()){
            int n = nums2.size();
            if(nums2.size() % 2 == 1) return nums2[n/2];
            return static_cast<double>(nums2[n-1] + nums2[n-2]) / 2.0;
        }
        int end = nums1.size(), end2 = nums2.size();
        int l1 = 0, r1 = end, m1 = 0, m2 = 0;
        int combSize = nums1.size() + nums2.size();
        int desiredLeftSize = (combSize)/2;
        while(r1>l1){
            /* Get mid point for array1 */
            m1 = (l1 + r1)/2;
            /* Second array is split so we have the desired number of elements */
            m2 = desiredLeftSize-m1;

            assert(m2 > 0);
            /* Case 1: m1-1 won't go behind m2 - so we overshot*/
            if(m1 && nums1[m1-1] > nums2[m2]) r1 = m1-1;
            /* Case 2: m1 won't go after m2-1 - so our value must be higher */
            else if(m1 < end && nums1[m1] < nums2[m2-1]) l1 = m1+1;
            else break;
        }
        /* Median can be 4 elements: A[m1-1], A[m1], B[m2-1], B[m2]*/
        /* The two are safe because boundaries */
        double dr1 = nums1[m1], dl2 = nums2[m2-1];
        /* If we don't have elements than use the counterpart from other array to discard */
        double dl1 = m1 ? nums1[m1-1] : dl2;
        double dr2 = m2 < end2 ? nums2[m2] : nums1[m1];
        cout << "dl1:"<<dl1<<", " << "dr1:"<<dr1<<" --- " << "dl2:"<<dl2<<", " << "dr2:"<<dr2<<", " <<endl; 
        /* Get the two middle elements we actually care about */
        double medianLeft = std::max(dl1, dl2), medianRight = std::min(dr1, dr2);
        cout << "medianLeft:" << medianLeft << " medianRight:" << medianRight <<endl; 
        /* Definition of median */
        if(combSize % 2 == 0) return (medianLeft+ medianRight) / 2.0;
        /* Right size is always one bigger */
        return medianRight;
    }
};