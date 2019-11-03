 bool isValid(string s) {
       stack<char> st;
        for(int i=0;i<s.size();i++)
        {
            if(st.empty()&&(s[i]==')'||s[i]=='}'||s[i]==']'))
               return false;    //栈空，遇到右边的括号，直接返回false
            if(s[i]==')'||s[i]=='}'||s[i]==']')  //遇到右边的括号，判断栈顶是否
               {                                 //是对应的左边的括号。
                   if(s[i]-st.top()==1||s[i]-st.top()==2)
                       st.pop();   //对应的话，栈顶元素退栈。
                   else
                       return false;  //不对应的话，直接返回false。
               }
            else
               st.push(s[i]);   //遇到左边的括号，进栈。
        }
        return st.empty();  //栈空，说明括号都匹配了。
    }
