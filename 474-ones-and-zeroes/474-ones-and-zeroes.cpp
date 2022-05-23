class Solution {
public:
    // 3 D dp vector, as we dicused, We will give it maximum size,
    //see Constraints, 1 <= strs.length <= 600 and 1 <= m, n <= 100
    int dp[601][101][101]; 
    
    // Count one and Zero function take string as parameter and count the number of ones and zeroes present in the string and return the counts.
    pair<int, int> countOneAndZero(string s)
    {
        int one = 0, zero = 0;
        
        for(int i = 0; i < s.length(); i++) // travel in the string
        {
            if(s[i] == '1') // if == '1', then add to one
                one++;
            else            // otherwise add to zero
                zero++;
        }
        
        return {one, zero};
    }
    
    int solve(int i, int one, int zero, int& maxZero, int& maxOne, 
             vector<string>& arr)
    {
        if(i >= arr.size()) // if ith index crosses the length then return 0
            return 0;
        
        // if any of the count, crosses the criteria of having maximum one
        // or zero, then return 0
        if(one > maxOne || zero > maxZero)
            return 0;
        
        // if it is already computed, then no need to do computation again,
		//return from here itself
        if(dp[i][one][zero] != -1)
        {
            return dp[i][one][zero];
        }
        pair<int, int> p = countOneAndZero(arr[i]);
        
        int ans1 = 0, ans2 = 0, ansWithout = 0;
        
        // adding count of current index, not to cross our limit then-
        if(one + p.first <= maxOne && zero + p.second <= maxZero)
        {
            // ans1, including it in our answer
            ans1 = 1 + solve(i + 1, one + p.first, zero + p.second, 
                           maxZero, maxOne, arr);
            
            // not including in our answer.
            ans2 = solve(i + 1, one, zero, maxZero, maxOne, arr);
        }
        else // if crossing limit, obviously not to take
        {
            ansWithout = solve(i + 1, one, zero, maxZero, maxOne, arr);
        }
        
        // and at last return the maximum of them
        return dp[i][one][zero] = max({ans1, ans2, ansWithout});
        
        
    }
    int findMaxForm(vector<string>& arr, int m, int n) {
        int maxZero = m; 
        int maxOne = n;
        
        memset(dp, -1, sizeof(dp)); // intially, putting -1 in dp
        return solve(0, 0, 0, maxZero, maxOne, arr);
    }
};