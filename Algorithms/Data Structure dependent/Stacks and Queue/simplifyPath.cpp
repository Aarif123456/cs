class Solution {
public:
    string simplifyPath(string path) {
        std::stack<string> files;
        string curFile = "";
        path.push_back('/');
        for(auto &c: path){
            if(c != '/')
                curFile.push_back(c);
            else if(curFile != ""){
                if(curFile == "..") {
                    if(!files.empty()) files.pop();
                }
                else if(curFile != ".") files.push(curFile);
                curFile = "";
            }
        }

        if(files.empty()) return "/";

        string out = "";
        while(!files.empty()){
            out = "/" + files.top() + out;
            files.pop();
        }
        return out;
    }
};