class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        sort(products.begin(),products.end());
        vector<vector<string>>ans;
        int n=products.size();
        int low,high=0;
        string prefix;
        for(char &c: searchWord){
            prefix+=c;
            low=lower_bound(products.begin()+high,products.end(),prefix)-products.begin();
            ans.push_back({});
            for(int i=low;i<min(low+3,n)&& !products[i].compare(0,prefix.length(),prefix);i++){
                ans.back().push_back(products[i]);
            }
            high=low;
        }
        return ans;
    }
};