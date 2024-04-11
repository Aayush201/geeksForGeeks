/*
Problem Link : https://www.geeksforgeeks.org/problems/kth-ancestor-in-a-tree/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=bottom_sticky_on_article#
*/

int solve(Node *root, int &k, int node, int &ans)
{
    if (!root)
        return 0;
    if (root->data == node)
    {
        return 1;
    }
    int left = solve(root->left, k, node, ans);
    int right = solve(root->right, k, node, ans);
    if (left)
    {
        k--;
        if (k == 0)
            ans = root->data;
        return 1;
    }
    else if (right)
    {
        k--;
        if (k == 0)
            ans = root->data;
        return 1;
    }
    return 0;
}
int kthAncestor(Node *root, int k, int node)
{
    // Code here
    int ans = -1;
    solve(root, k, node, ans);
    return ans;
}