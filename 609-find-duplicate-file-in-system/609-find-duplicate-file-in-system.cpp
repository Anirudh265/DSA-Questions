class Solution {
public:
    vector<vector<string>> findDuplicate(vector<string>& paths) {
        unordered_map<string, vector<string>> hashmap;
        vector<vector<string>> result;
        for(auto &path: paths) {
            bool getPath = false, isContent = false;
            string filePath = "", fileName = "", content = "";
            int fileStart = 0;
            for(int i = 0; i < path.length(); i++) {
                if(!getPath and path[i] == ' ') {
                    filePath = path.substr(0, i);
                    getPath = true;
                }
                if(path[i] == ' ') {
                    fileStart = i + 1;
                }
                if(path[i] == ')') {
                    isContent = false;
                    hashmap[content].push_back(filePath + "/" + fileName);
                    fileName = "", content = "";
                }
                if(isContent) {
                    content += path[i];
                }
                if(path[i] == '(') {
                    isContent = true;
                    fileName = path.substr(fileStart, i - fileStart);
                }
            }
        }
        for(auto &content: hashmap) {
            if(content.second.size() > 1) {
                vector<string> group;
                for(auto &path: content.second)
                    group.push_back(path);
                result.push_back(group);
            }
        }
        return result;
    }
        
    
};