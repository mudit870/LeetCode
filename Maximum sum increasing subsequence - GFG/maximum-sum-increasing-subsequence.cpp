// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
		

	public:
	int maxSumIS(int arr[], int n)  
	{  
	    int ans=INT_MIN;
	    vector<int> dp(n);
	    for(int i=0;i<n;i++){
	        int res=INT_MIN;
	        for(int j=0;j<i;j++){
	            if(arr[j]<arr[i]){
	                if(res==INT_MIN){
	                    res=dp[j];
	                }else if(dp[j]>res){
	                    res=dp[j];
	                }
	            }
	        }
	        if(res==INT_MIN){
	            dp[i]=arr[i];
	        }else{
	            dp[i]=res+arr[i];
	        }
	        
	        if(ans<dp[i]){
	            ans=dp[i];
	        }
	    }
	    return ans;
	}  
};

// { Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];

        for(int i = 0; i < n; i++)
        	cin >> a[i];

      

	    Solution ob;
	    cout << ob.maxSumIS(a, n) << "\n";
	     
    }
    return 0;
}

  // } Driver Code Ends