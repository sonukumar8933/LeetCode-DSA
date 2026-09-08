class Solution {
public:
    string simplifyPath(string path) {
        stack<string>st;
        string temp;
        stringstream ss(path);
        while(getline(ss,temp,'/')){

            if(temp=="."|| temp=="")continue;

            else if(temp==".."){
                if(!st.empty()){
                    st.pop();
                }
            }
            else{
                st.push(temp);
            }

         
        }

        string ans="";
        while(!st.empty()){
            ans="/"+st.top()+ans;
            st.pop();
        }

        if(ans==""){
            return "/";
        }
        return ans;
       
        
    }
};