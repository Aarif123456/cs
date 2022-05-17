typedef vector<int> vi;
typedef vector<vi> vvi;

class Solution {
public:
    void printDp(vi& dp){
        for(auto &x : dp){
            cout << x <<",";
        }
        cout << endl;
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        if(days.empty()) return 0;
        vi dp(366, 0);
        int p = 0;
        for(int i = 1; i <= 365 && p < days.size(); i++){
            if(i != days[p]) dp[i] = dp[i-1];
            else{
                dp[i] = std::min({dp[max(0, i-30)]+costs[2], dp[max(0,i-7)]+costs[1], dp[i-1]+costs[0]});
                p++;
            }
        }

        
        return dp[days.back()];
    }
};