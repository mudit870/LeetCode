class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        vector<int>left(n);
        vector<int>right(n);
        stack<int>s1;
        stack<int>s2;
        
        left[0]=-1;
        s1.push(0);
        for(int i=1;i<n;i++){
            while(s1.size()>0 && heights[i]<=heights[s1.top()]){
                s1.pop();
            }
            if(s1.empty()){
                left[i]=-1;
            }else{
                left[i]=s1.top();
            }
            s1.push(i);
        }
        
        right[n-1]=n;
        s2.push(n-1);
        for(int i=n-2;i>=0;i--){
            while(s2.size()>0 && heights[i]<=heights[s2.top()]){
                s2.pop();
            }
            if(s2.empty()){
                right[i]=n;
            }else{
                right[i]=s2.top();
            }
            s2.push(i);
        }
        int area=0;
        for(int i=0;i<n;i++){
            int width=right[i]-left[i]-1;
            int ans=heights[i]*width;
            area=max(area,ans);
        }
        return area;
    }
};