class Solution {
public:
    bool checkIfPangram(string sentence) {
        vector<int> word(26,0);
        for(int i=0;i<sentence.size();++i)
        {
            word[sentence[i]-'a']++;
        }
        for(int i=0;i<26;++i)
        {
            if(word[i]==0)return false;
        }
        return true;
        
    }
};