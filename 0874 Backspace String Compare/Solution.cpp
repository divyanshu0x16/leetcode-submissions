class Solution {
public:

    bool isSameStack(stack<char> stack1, stack<char> stack2){
        bool flag = true;
 
        if (stack1.size() != stack2.size()) {
            flag = false;
            return flag;
        }
 
        while (stack1.empty() == false) {
            if (stack1.top() == stack2.top()) {
                stack1.pop();
                stack2.pop();
            }
            else {
                flag = false;
                break;
            }
        }
        return flag;
    }


    bool backspaceCompare(string s, string t) {
        stack<char> s_new;
        stack<char> t_new;

        for (auto &&i : s)
        {
            if( i == '#' and  s_new.empty() == false)
                s_new.pop();
            else if ( i != '#') s_new.push(i);
        }
        
        for (auto &&i : t)
        {
            if( i == '#' and  t_new.empty() == false)
                t_new.pop();
            else if ( i != '#') t_new.push(i);
        }

        return isSameStack(t_new, s_new);
    }
};