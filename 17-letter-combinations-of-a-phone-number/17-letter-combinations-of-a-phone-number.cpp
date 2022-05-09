class Solution {
public:
    vector<string> fans;
    void phonePad(vector<string> &arr,string digits,string ans,int i){
        if(i==digits.length()){
            fans.push_back(ans);
            return;
        }
        char ch=digits[i];
        for(int j=0;j<arr[ch-'0'].length();j++){
            ans.push_back(arr[ch-'0'][j]);
            phonePad(arr,digits,ans,i+1);// we didn't use this ans+arr[ch-'0'][i] why??
            ans.pop_back();
        }
    }
public:
    vector<string> letterCombinations(string digits) {
        if(digits.length()==0) return {};
        vector<string>arr={" "," ","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        phonePad(arr,digits,"",0);
        return fans;
    }
};