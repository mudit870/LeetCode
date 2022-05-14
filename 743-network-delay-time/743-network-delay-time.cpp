class Solution {
    struct node{
        int dst;
        int wt;
    };
    struct qnode{
        int vertex;
        int dist;
    };
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        unordered_map<int,vector<node *>> adj;
        for(int i=0;i<times.size();i++){
            node *newnode = new node;
            newnode->dst=times[i][1];
            newnode->wt=times[i][2];
            adj[times[i][0]].push_back(newnode);
        }
        qnode *qn = new qnode;
        qn->vertex = k;
        qn->dist = 0;
        queue<qnode *> q;
        q.push(qn);
        
        vector<int>distance(n+1,INT_MAX);
        distance[k]=0;
        int time = 0;
        
        while(!q.empty()){ //bfs
            qnode *curr = q.front();
            q.pop();
            
            for(auto it:adj[curr->vertex]){
                qnode *tempqn = new qnode;
                tempqn->vertex = it->dst;
                tempqn->dist = it->wt + curr->dist;
                if(distance[tempqn->vertex]>tempqn->dist){
                    q.push(tempqn);
                    distance[tempqn->vertex] = it->wt + curr->dist;
                }
            }
        }
        for(int i=1;i<=n;i++){
            if(distance[i]==INT_MAX){
                return -1;
            }
            time=max(time,distance[i]);
        }
        return time;
    }
};