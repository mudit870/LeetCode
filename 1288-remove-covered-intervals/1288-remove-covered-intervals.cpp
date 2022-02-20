class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size(); // extracting the size of the array
        
        sort(intervals.begin(), intervals.end()); // sort the array
        
        int maximum_left = -1, maximum_right = -1; // declaring variables
        
        int ans = 0; // conatains our answer
        
        for(int i = 0; i < n; i++) // start traversing the array
        {
            // check condition
            if(intervals[i][0] > maximum_left && intervals[i][1] > maximum_right)
            {
                ans++; // increment answer
                maximum_left = intervals[i][0];  // update maximum left
            }
            maximum_right = max(maximum_right, intervals[i][1]); // update maximum right
        }
        
        return ans; // lastly return answer
    }
};