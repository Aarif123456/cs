
typedef pair<int, int> pii;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
constexpr ll MOD = static_cast<long long>(1e9) + 7;
#define SIZE(v) static_cast<int>(v.size()) 

class Solution {
public:
    vl getNumMinArray(vi& arr, bool equal){
        int n = SIZE(arr);
        vl lens(n);
        std::iota (lens.begin(), lens.end(), 1);
        std::reverse(lens.begin(), lens.end());
        std::stack<int> mono; /* Monotonic stack */
        for (int i = 0; i < n; i++){
            auto x = arr[i];
            while(!mono.empty() && (arr[mono.top()]>x || (equal && arr[mono.top()]==x) )){
                ll idx = mono.top(); mono.pop();
                lens[idx] = i-idx;
            }
            mono.push(i);
        }

        return lens;
    }

    int sumSubarrayMins(vector<int>& arr) {
        auto right = getNumMinArray(arr, true);
        vi rev(arr.rbegin(), arr.rend());
        auto left = getNumMinArray(rev, false);
        std::reverse(left.begin(), left.end());
        int n = SIZE(arr);

        ll sum = 0;
        for (int i = 0; i < n; i++){
            ll x = arr[i];
            ll l = left[i];
            ll r = right[i];
            sum = (sum + (l*r*x)) % MOD;
            // cout << "x:"<<x<<" l:"<<l<<" r:" << r << " sum:" <<sum << endl;
        }

        return sum;
    }
};