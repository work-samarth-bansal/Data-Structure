
//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


class Solution {
public:
    int count = 0;

    int average(TreeNode* root)
    {
        if(!root)
            return -1;

        int x = average(root->left);
        int y = average(root->right);

        if(x == -1 && y == -1)
        {
            count++;
            return root->val;
        }
        else if(x == -1)
        {
            if(root->val == (root->val + y)/2)
                count++;

            return (root->val + y)/2;
        }
        else if(y == -1)
        {
            if(root->val == (root->val + x)/2)
                count++;
            return (root->val + x)/2;
        }
        else
        {
            if(root->val == (root->val + y +y)/3)
                count++;

            return (root->val + y + x)/3;
        }
    }

    int averageOfSubtree(TreeNode* root) {

        average(root);
        
        return count;

    }
};