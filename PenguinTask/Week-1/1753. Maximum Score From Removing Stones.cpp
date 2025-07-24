class Solution {
public:
    int maximumScore(int a, int b, int c) {
        
        priority_queue<int> hp;
        hp.push(a);
        hp.push(b);
        hp.push(c);

        int score = 0;

        while (true) {
            int x = hp.top(); hp.pop();
            int y = hp.top(); hp.pop(); 

            if (y == 0) break; 

            score++;
            x--;
            y--;

            hp.push(x);
            hp.push(y);
        }

        return score;
    }
};
