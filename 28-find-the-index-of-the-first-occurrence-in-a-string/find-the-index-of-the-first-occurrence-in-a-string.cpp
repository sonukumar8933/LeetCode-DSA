class Solution {
public:
    int strStr(string haystack, string needle) {
        int n1=haystack.size();
        int n2=needle.size();

        for(int i=0;i<=n1-n2;i++){
            if(haystack.substr(i,n2)==needle)return i;

        }
        return -1;
        

    }
};