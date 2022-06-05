class Solution {
public:
    vector<int> arrayChange(vector<int>& nums, vector<vector<int>>& operations) {
        unordered_map<int,int>umap;
        for(int i=0;i<nums.size();i++){
            umap[nums[i]]=i;
        }
        
        for(int i=0;i<operations.size();i++){
            if(umap.find(operations[i][0])!=umap.end()){
                nums[umap[operations[i][0]]]=operations[i][1];
                int n=umap[operations[i][0]];
                umap.erase(operations[i][0]);
                umap[operations[i][1]]=n;
            }
        }
        return nums;
    }
};