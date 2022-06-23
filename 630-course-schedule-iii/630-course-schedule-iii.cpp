class Solution {
public:
    static bool comparator(vector<int>& c1,vector<int>& c2){
        return c1[1]<c2[1];
    }
    int scheduleCourse(vector<vector<int>>& courses) {
        sort(courses.begin(),courses.end(),comparator);
        int ans=0;
        priority_queue<int>pq;
        for(int i=0;i<courses.size();i++){
            pq.push(courses[i][0]);
            ans+=courses[i][0];
            if(ans>courses[i][1]){
                ans-=pq.top();
                pq.pop();
            }
        }
        return pq.size();
    }
};