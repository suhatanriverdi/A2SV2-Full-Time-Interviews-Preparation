// Question Link: https://leetcode.com/problems/rabbits-in-forest/

class Solution {
public:
    int numRabbits(vector<int>& answers) {
        int count[1000];
        memset(count, 0, sizeof count);
        // Count each unique answer
        for (int &answer : answers) {
            count[answer]++;
        }
        int minRabbitsCount = 0;
        for (int i = 0; i < 1000; i++) {
            if (count[i] > 0) {
                int div = (count[i] / (i + 1));
                int rem = (count[i] % (i + 1));
                if (div == 0) {
                    div = 1;
                }
                minRabbitsCount += div * (i + 1);
                if (count[i] > (i + 1) && rem > 0) {
                    minRabbitsCount += (i + 1);
                }
            }
        }
        return minRabbitsCount;
    }
};