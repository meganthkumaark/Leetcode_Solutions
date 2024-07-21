#include <stack>
#include <string>
#include <unordered_map>

class Solution 
{
public:
    bool isValid(string s) 
    {
        stack<char> st;
        unordered_map<char, char> brackets = {{')', '('}, {']', '['}, {'}', '{'}};
        
        for (char ch : s) 
        {
            if (brackets.count(ch)) 
            {
                if (st.empty() || st.top() != brackets[ch]) 
                {
                    return false;
                }
                st.pop();
            } 
            else if (brackets.find(ch) == brackets.end()) 
            {
                st.push(ch);
            } 
            else
            {
                return false;
            }
        }
        
        return st.empty();
    }
};
