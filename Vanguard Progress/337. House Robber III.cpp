// Question Link: https://leetcode.com/problems/house-robber-iii/

class Solution {
public:
    int rob(TreeNode* root) {
        vector<int> res = helper(root);
        return max(res[0], res[1]);
    }
    /*
            3 ---------> withMe = (3 + 1 + 1)
          /   \
      (2,3)   (3,1)  
      
      withoutMe = maxof(  (2 + 1),  (2  + 3),  (3 + 3), (2 + 1)  )
      2[0]    3[0]
      3[1]    1[1]
    */
    vector<int> helper(TreeNode* cur) {
        if (cur == nullptr) {
            // We return two informations to our parent
            // 1) Total value if we can rob the current house
            // 2) Maximum of total values if we cannot rob the current house
            return { 0, 0 };
        }
        
        vector<int> l = helper(cur->left);
        vector<int> r = helper(cur->right);
        
        // Find max if we can inlude the current house
        int withMe = cur->val + l[1] + r[1];
        
        // Find max if we cannot inlude current house
        int withoutMeMax = max({ (l[0] + r[1]), (l[0] + r[0]), (l[1] + r[1]), (l[1] + r[0]) });
            
        // Return the max
        return { withMe, withoutMeMax };
    }
};
