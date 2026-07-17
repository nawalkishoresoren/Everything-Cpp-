class Solution {
public:
    bool checkValidString(string s) 
    {
        stack<int>openst;
        stack<int>astriskst;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='(')
                openst.push(i);
            else if(s[i] == '*')
                astriskst.push(i);
            else{
                if(!openst.empty())
                {
                    openst.pop();
                }
                else if(!astriskst.empty())
                {
                    astriskst.pop();
                }
                else
                {
                    return false;
                }
            }
        }
        while(!openst.empty() and !astriskst.empty())
        {
            if(openst.top() > astriskst.top())
                return false;
            
            openst.pop();
            astriskst.pop();
        }
        return openst.empty();
    }
};