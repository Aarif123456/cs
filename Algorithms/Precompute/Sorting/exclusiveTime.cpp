struct LogTime{
    int id = -1;
    bool isEnd = false;
    long long timestamp = 0;
};
/* Set up comparison */
inline const bool operator<(const LogTime& a, const LogTime& b){
    return a.timestamp < b.timestamp;
}

class Solution {
public:
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        vector<LogTime> logsParsed;
        for(auto log: logs){
            char* clog = new char[log.length()+1];
            strcpy(clog, log.c_str());
            string s0 = string(std::strtok(clog, ":"));
            string s1 = string(std::strtok(NULL, ":"));
            string s2 = string(std::strtok(NULL, ":"));
            logsParsed.push_back({stoi(s0), s1 == "end", stol(s2)});
        }

        std::sort(logsParsed.begin(), logsParsed.end());
        std::vector<int> out(n, 0);
        std::stack<LogTime> stk;
        for(auto &log : logsParsed){
            if(log.isEnd){
                assert(!stk.empty());
                out[stk.top().id] += log.timestamp - stk.top().timestamp + 1;
                stk.pop();
                if(!stk.empty()) stk.top().timestamp = log.timestamp + 1;
            }
            else{
                if(!stk.empty()) out[stk.top().id] += log.timestamp - stk.top().timestamp;
                stk.push(log);
            }
        }

        return out;
    }
};