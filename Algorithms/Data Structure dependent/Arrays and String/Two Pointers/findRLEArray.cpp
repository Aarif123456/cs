typedef vector<int> vi; 
typedef vector<vi> vvi;

class Solution {
public:
    vvi findRLEArray(vvi& encoded1, vvi& encoded2) {
        auto p1 = encoded1.begin(), p2 = encoded2.begin();
        auto e1 = encoded1.end(), e2 = encoded2.end();
        vvi out;
        while(p1 != e1 and p2 != e2){
            auto a1 = *p1, a2 = *p2;
            if(a1[1] == 0) p1++;
            else if(a2[1] == 0) p2++;
            else{
                int cnt = std::min(a1[1], a2[1]);
                int prod = a1[0] * a2[0];
                if(out.empty() || out.back()[0] != prod)out.push_back(vi{prod, cnt});
                else out.back()[1] += cnt;
                (*p1)[1] -= cnt;
                (*p2)[1] -= cnt;
            }

        }

        return out;
    }
};