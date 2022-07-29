class Solution {
public:
    bool bfs(vector<vector<int>>& graph, int src,vector<int>& vis){
        list<int>que;
        que.push_back(src);        
        int color=0;
        while(!que.empty()){
            int size=que.size();
            while(size--){
                int rvtx=que.front();
                que.pop_front();
                if(vis[rvtx]!=-1){
                    if(color!=vis[rvtx])
                        return false; //conflict
                    continue;
                }
                vis[rvtx]=color;
                for(int v:graph[rvtx]){
                    if(vis[v]==-1)
                        que.push_back(v);
                }
            }
            color=(color+1)%2;
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int>vis(n,-1);
        for(int i=0;i<n;i++){
            if(vis[i]==-1 && !bfs(graph,i,vis))
                return false;
        }
        return true;
    }
};