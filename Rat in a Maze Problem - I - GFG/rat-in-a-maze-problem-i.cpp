// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function template for C++

class Solution{
    public:
    vector<string> ans;
    
    
    void solve(vector<vector<int>> m,int n,int i, int j,string s){
        if(i==n-1&&j==n-1){
            ans.push_back(s);
            return;
        }
        
        if(i+1<n && m[i+1][j]==1){
            m[i][j]=0;
            solve(m,n,i+1,j,s+"D");
            m[i][j]=0;
        }
        if(j-1>=0 && m[i][j-1]==1){
            m[i][j]=0;
            solve(m,n,i,j-1,s+"L");
            m[i][j]=0;
        }
        if(j+1<n && m[i][j+1]==1){
            m[i][j]=0;
            solve(m,n,i,j+1,s+"R");
            m[i][j]=0;
        }
        if(i-1>=0 && m[i-1][j]==1){
            m[i][j]=0;
            solve(m,n,i-1,j,s+"U");
            m[i][j]=0;
        }
    }
    
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
        if(m[0][0]==0){
            return {};
        }
        solve(m,n,0,0,"");
        
        return ans;
        
    }
    // void solve(int r,int c, vector<vector<int>>& m,vector<string>& ans,vector<vector<int>>& vis, string s, int n){
    //     if(r==n-1 && c==n-1){
    //         ans.push_back(s);
    //         return;
    //     }
    //     if(r+1<n && vis[r+1][c]==0 && m[r+1][c]==1){
    //         vis[r][c]=1;
    //         solve(r+1,c,m,ans,vis,s+"D",n);
    //         vis[r][c]=0;
    //     }
    //     if(r-1>=0 && vis[r-1][c]==0 && m[r-1][c]==1){
    //         vis[r][c]=1;
    //         solve(r-1,c,m,ans,vis,s+"U",n);
    //         vis[r][c]=0;
    //     }
    //     if(c+1<n && vis[r][c+1]==0 && m[r][c+1]==1){
    //         vis[r][c]=1;
    //         solve(r,c+1,m,ans,vis,s+"R",n);
    //         vis[r][c]=0;
    //     }
    //     if(c-1>=0 && vis[r][c-1]==0 && m[r][c-1]==1){
    //         vis[r][c]=1;
    //         solve(r,c-1,m,ans,vis,s+"L",n);
    //         vis[r][c]=0;
    //     }
    // }
    // vector<string> findPath(vector<vector<int>> &m, int n) {
    //     // Your code goes here
    //     vector<vector<int>>vis(n,vector<int>(n,0));
    //     vector<string>ans;
    //     if(m[0][0]==1){
    //         solve(0,0,m,ans,vis,"",n);
    //     }
    //     return ans;
    // }
};

    


// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends