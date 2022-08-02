class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>>graph(numCourses);
        vector<int>indegree(numCourses,0);
        //make directed graph
        for(int i=0;i<prerequisites.size();i++){
            graph[prerequisites[i][1]].push_back(prerequisites[i][0]);//1<-0
            indegree[prerequisites[i][0]]++;
        }
        queue<int>que;
        for(int i=0;i<indegree.size();i++){
            if(indegree[i]==0)que.push(i);
        }
        int count=0;
        while(!que.empty()){
                int temp=que.front();//0
                que.pop();
                count++;
            
            for(int neighbour:graph[temp]){
                indegree[neighbour]--;
                
                if(indegree[neighbour]==0){
                    que.push(neighbour);
                }
            }
                // for(int i=0;i<graph[temp].size();i++){
                //     indegree[graph[temp][i]]--;
                //     if(indegree[graph[temp][i]]==0)
                //         que.push(graph[temp][i]);
                // }
        }
        return count==numCourses;
    }
};

// [[1,0],[2,0],[3,1]]

// 0->1,2
// 1->3