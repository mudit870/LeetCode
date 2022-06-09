class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int>ans;
        unordered_map<int,int>a;
        for(int i=0;i<numbers.size();i++){
            a[numbers[i]]=i+1;
        }
        for(int i=0;i<numbers.size();i++){
            int diff=target-numbers[i];
            if(a.find(diff)!=a.end()){
                ans.push_back(i+1);
                ans.push_back(a[diff]);
                break;
            }
        }
        return ans;
    }
};