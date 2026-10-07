class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        set<string> st;
        int n=0,m=s.length();
        for(auto ch:s)
        {
            if(ch=='('||ch==')') n++;
        }
        int max_length=0;
        for(int mask=0;mask<(1<<n);mask++)
        {
            int mask_index=n-1,string_index=0;
            int open=0;
            bool is_valid=true;
            string temp="";
            while(string_index<m)
            {
                bool add=true;
                if(open<0) break;
                if(s[string_index]=='('||s[string_index]==')')
                {
                    if(!(mask&(1<<mask_index)))
                    {
                        add=false;
                    }
                    else
                    {
                        if(s[string_index]=='(')
                        {
                            open++;
                        }
                        else
                        {
                            open--;
                        }
                    }
                    mask_index--;
                }
                if(add)
                {
                    temp+=s[string_index];
                }
                string_index++;
            }
            if(open==0)
            {
                max_length=max(max_length,(int)temp.length());
                st.insert(temp);
            }
        }
        vector<string> ans;
        for(auto it:st)
        {
            if(it.length()==max_length)ans.push_back(it);
        }
        return ans;
    }
};