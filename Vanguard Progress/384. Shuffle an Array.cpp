// Question https://leetcode.com/problems/shuffle-an-array

class Solution {
private:
    vector<int> original;
    int len;
public:
    Solution(vector<int>& nums) {
        original = nums;
        len = nums.size();
    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        return original;
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        int numOfElementsLeft = len;
        vector<int> shuffled(len, -1);
        vector<bool> visitedIndex(len, false);
        int currenRandomIndex = rand() % len;
        int i = 0;
        while (numOfElementsLeft > 0) {
            // Produce a random index
            currenRandomIndex = rand() % len;
            // Check if it is not already produced before                
            if (visitedIndex[currenRandomIndex] == false) {
                shuffled[i] = original[currenRandomIndex];
                visitedIndex[currenRandomIndex] = true;
                numOfElementsLeft--;
                i++;
            }
        }
        return shuffled;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */