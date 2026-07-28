/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<double> averageOfLevels(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);

        vector<double> ans;

        long long sum = 0;
        int cnt = 0;

        while (!q.empty()) {
            TreeNode* temp = q.front();
            q.pop();

            if (temp == NULL) {
                ans.push_back((double)sum / cnt);

                if (q.empty()) break;

                sum = 0;
                cnt = 0;
                q.push(NULL);
            } else {
                sum += temp->val;
                cnt++;

                if (temp->left) q.push(temp->left);
                if (temp->right) q.push(temp->right);
            }
        }

        return ans;
    }
};