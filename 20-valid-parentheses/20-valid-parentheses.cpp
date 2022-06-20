class Solution {
public:
    bool isValid(string st) {
        stack<char>s;
        for(auto e:st){
            if(s.empty() || e=='[' || e=='{' || e=='(')
                s.push(e);
            else if(e==')' && s.top()=='(')
                s.pop();
            else if(e==']' && s.top()=='[')
                s.pop();
            else if(e=='}' && s.top()=='{')
                s.pop();
            else
                return false;
        }
        if(!s.empty())
            return false;
        return true;
    }
};