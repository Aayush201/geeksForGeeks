/*
Problem Link : https://geeksforgeeks.org/problems/valid-expression1025/1
*/

bool valid(string s)
{
    stack<char> st;
    for (auto x : s)
    {
        if (!st.empty() && x == ')' && st.top() == '(')
            st.pop();
        else if (!st.empty() && x == ']' && st.top() == '[')
            st.pop();
        else if (!st.empty() && x == '}' && st.top() == '{')
            st.pop();
        else
            st.push(x);
    }

    return st.empty();
}