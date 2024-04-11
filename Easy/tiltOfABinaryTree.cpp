/*
Problem Link : https://www.geeksforgeeks.org/problems/tilt-of-binary-tree/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=bottom_sticky_on_article
*/

class Solution
{
public:
    // Your are required to complete this function
    // function should return the tilt of the tree
    int solve(Node *root, int &ans)
    {
        if (!root)
            return 0;
        if (!root->left && !root->right)
            return root->data;
        int left = solve(root->left, ans);
        int right = solve(root->right, ans);
        ans += abs(left - right);
        return root->data + left + right;
    }
    int tiltTree(Node *root)
    {
        // code here
        int ans = 0;
        solve(root, ans);
        return ans;
    }
};