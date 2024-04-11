/*
Problem Link : https://www.geeksforgeeks.org/problems/kth-common-ancestor-in-bst/1
*/

class Solution
{
public:
    /*You are required to complete below function */
    // vector<int>tmp;
    int ans = -1;
    void solve(Node *root, int &k, int x, int y)
    {
        if (!root)
            return;
        // tmp.push_back(root->data);
        if (x < root->data && y < root->data)
        {
            solve(root->left, k, x, y);
        }
        if (x > root->data && y > root->data)
        {
            solve(root->right, k, x, y);
        }
        k--;
        if (k == 0)
            ans = root->data;
    }
    int kthCommonAncestor(Node *root, int k, int x, int y)
    {
        // your code goes here
        solve(root, k, x, y);
        // if(k>tmp.size()) return -1;
        // for(auto x : tmp) cout << x << " ";
        // cout << endl;
        // return tmp[tmp.size()-k];
        return ans;
    }
};
