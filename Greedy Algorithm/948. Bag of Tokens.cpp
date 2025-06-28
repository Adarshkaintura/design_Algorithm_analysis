class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        int score = 0, maxScore = 0;
        sort(tokens.begin(), tokens.end());
        int cur = 0, las = tokens.size() - 1;

        while (cur <= las) {
            if (tokens[cur] <= power) {
                power -= tokens[cur];
                score++;
                cur++;
                maxScore = max(maxScore, score);  // Update here when gaining score
            } else if (score >= 1) {
                power += tokens[las];
                score--;
                las--;
            } else {
                break;
            }
        }

        return maxScore;
    }
};
