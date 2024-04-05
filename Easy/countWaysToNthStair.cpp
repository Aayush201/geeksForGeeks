/*
Problem link : https://www.geeksforgeeks.org/problems/count-ways-to-nth-stairorder-does-not-matter1322/1
*/
class Solution
{
public:
    // Function to count number of ways to reach the nth stair
    // when order does not matter.
    long long countWays(int n)
    {
        // your code here
        return 1ll * (n / 2) + 1;
    }
};