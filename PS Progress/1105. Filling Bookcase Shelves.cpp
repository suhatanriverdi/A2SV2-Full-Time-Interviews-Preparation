// Question Link: https://leetcode.com/problems/filling-bookcase-shelves/

class Solution {
public:
    int minHeightShelves(vector<vector<int>>& books, int shelf_width) {
        int memo[1001][1001];
        memset(memo, -1, sizeof(memo));
        return helper(0, 0, books[0][1], books, shelf_width, memo);
    }
    
    int helper(int cur, int curShelfWidth, int curShelfMaxHeight, vector<vector<int>> &books, int &shelf_width, int memo[][1001]) {
        if (memo[cur][curShelfWidth] != -1) {
            return memo[cur][curShelfWidth];
        }
        
        // When there is no book left 
        if (cur == books.size()) {
            return curShelfMaxHeight;
        }
        
        int curBookWidth = books[cur][0];
        int curBookHeight = books[cur][1];
        int nextShelf, nextBook = INT_MAX;
        
        // Put the current book onto current shelf, and go to next book
        int newShelfWidth = curBookWidth + curShelfWidth;
        if (newShelfWidth <= shelf_width) {
            nextBook = helper(cur + 1, newShelfWidth, max(curShelfMaxHeight, curBookHeight), books, shelf_width, memo);
        }
        
        // Put the current book onto next shelf
        nextShelf = helper(cur + 1, curBookWidth, curBookHeight, books, shelf_width, memo) + curShelfMaxHeight;
        
        // Memoization
        memo[cur][curShelfWidth] = min(nextShelf, nextBook);
        return memo[cur][curShelfWidth];
    }
};