class Solution {
public:
    int percentageLetter(string s, char letter) {
        double c=0;
        double ans;
        for(auto e:s){
            if(e==letter)
                c++;
        }
        ans=(c/s.length())*100;
        return ans;
    }
};