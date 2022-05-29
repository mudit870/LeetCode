class Solution {
public:
    int maxProduct(vector<string>& words) {
        int ans = 0, n = words.size();
        for(int i=0; i<n; i++){
            vector<int>v(26);
            for(int k=0; k<words[i].size(); k++)
                v[words[i][k] - 'a']++;
            
            for(int j=0; j<n; j++){
                if(i != j && ans < words[i].size()*words[j].size()){
                    int flag = 1;
                    for(int k=0; k<words[j].size(); k++){
                        if(v[words[j][k] - 'a']){
                            flag = 0;
                            break;
                        }
                    }
                    if(flag)
                        ans = words[i].size()*words[j].size();
                }
            }
        }
        return ans;
    }
};