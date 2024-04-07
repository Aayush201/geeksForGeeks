/*
Problem  Link : https://www.geeksforgeeks.org/problems/subarrays-with-k-different-integers/1?page=1&category=two-pointer-algorithm,sliding-window&difficulty=Medium&status=unsolved&sortBy=submissions
*/

class Solution
{
public:
    long long solve(vector<int> &arr, int n, int k)
    {
        long long i = 0, j = 0, ans = 0;
        unordered_map<int, int> mp;
        while (j < n)
        {
            mp[arr[j]]++;
            while (mp.size() > k)
            {
                mp[arr[i]]--;
                if (!mp[arr[i]])
                    mp.erase(arr[i]);
                i++;
            }
            ans += j - i + 1;
            j++;
        }
        return ans;
    }
    int subarrayCount(vector<int> &arr, int N, int K)
    {
        // code here
        return 1ll * solve(arr, N, K) - 1ll * solve(arr, N, K - 1);
    }
};
