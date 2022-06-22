class Solution {
public:
    int myAtoi(string s) {
        int i=0;
        if(s.length()==0)
            return 0;
        while(i<s.length() && s[i]==' '){
            i++;
        }
        long ans=0;
        int a=0;
        if(s[i]=='-'){
            i++;
            a=1;
        }
        else if(s[i]=='+'){
            i++;
        }
        while(i<s.length()){
            if(s[i]==' ' || !isdigit(s[i]))
                break;
            ans=ans*10 + s[i]-'0';
            if(a==1 && (-1)*ans<INT_MIN)
                return INT_MIN;
            if(a==0 && ans>INT_MAX)
                return INT_MAX;
            i++;
        }
        if(a==1)
            ans*=(-1);
        return (int)ans;
    }
};