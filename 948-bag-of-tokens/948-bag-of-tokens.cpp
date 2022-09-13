class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        sort(tokens.begin(),tokens.end());
        int score=0;
        int i=0,j=tokens.size()-1;
        while(i<=j and i<tokens.size() and j>=0)
        {
            if(i==j)
            {
                if(power>=tokens[i]) return score+1;
                else if(power<=tokens[i]) return score;
            }
            if(power<tokens[i] and score>0)
            {
                power+=tokens[j];
                j--;
                score--;
            }
            else if(power>=tokens[i])
            {
                power-=tokens[i];
                i++;
                score++;
            }
            else break;
        }
        return score;
    }
};