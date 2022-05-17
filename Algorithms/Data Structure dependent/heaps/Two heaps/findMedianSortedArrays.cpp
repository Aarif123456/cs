class Solution {
public:
    int getSpot(vector<int>& a, vector<int>& b, int i){
        return ((a.size()+b.size()+1)/2) - i;
    }
    double findMedianSortedArrays(vector<int>& a, vector<int>& b) {
        if(a.size()> b.size())  return findMedianSortedArrays(b, a);
        int n = a.size()+b.size();
        /* Bigger last can't empty*/
        assert(!b.empty());
        /* If smaller list continues into bigger list*/
        if(a.size() == 0 || a.back() < b[0]){
            int l = n/2;
            if(n%2==1) return b[l+1];
            return double(b[l]+b[l+1])/2.0;
        }
        int l=0, r=a.size();
        int i=a.size()/2;
        int j=getSpot(a,b,i);
         cout << "i:"<<i << ",j:"<<j;
        while(l<r && !( (i==0 || a[i-1]<=b[j]) && (i==a.size() ||  a[i]>=b[j-1]) )){
            cout << "i:"<<i << ",j:"<<j;
            cout <<", a[i]:" <<setfill('0') << std::setw(3) <<a[i];
            cout << ", b[j]:" << setfill('0') << std::setw(3) <<b[j];
            cout << endl;
            if(i>0 && a[i-1]>b[j]){
                l=i+1;
            }
            else if (i<a.size() &&  a[i] < b[j-1]){
                r=i-1;
            }
            else{
                break;
            }
            i=(l+r)/2;
            j=getSpot(a,b,i);
        }

        if(n%2==1) return max(a[i],b[j]);
        return double(max(a[i],b[j])+min(a[i+1],b[j+1]))/2.0;
    }
};