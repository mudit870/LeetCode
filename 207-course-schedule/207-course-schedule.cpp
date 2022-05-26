class Solution {
public:
    bool isCycle(vector<vector<int>>& adjMatrix, vector<int>& visited, int idx){
        if(visited[idx]==2)
            return true;
        
        visited[idx]=2;
        for(int i=0;i<adjMatrix[idx].size();i++){
            if(visited[adjMatrix[idx][i]]!=1){
                if(isCycle(adjMatrix,visited,adjMatrix[idx][i])){
                    return true;
                }
            }
        }
        visited[idx]=1;
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // basically if there is a cycle just return false
        // we will mark 0 initally to all, if we visit the no. we mark it as 1 & 
        // check all of its neighbours, when all of its neighbor visited we will mark it as 2
        vector<vector<int>> adjMatrix(numCourses);
        
        for(int i=0;i<prerequisites.size();i++){
            adjMatrix[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }
        vector<int> visited(numCourses,0);
        for(int i=0;i<numCourses;i++){
            if(visited[i]==0){
                if(isCycle(adjMatrix,visited,i)){
                    return false;
                }
            }
        }
        return true;
    }
};