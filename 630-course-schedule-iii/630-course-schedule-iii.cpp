class Solution {
    public:
    static bool cmp(vector<int>& a, vector<int>& b){
        return a[1]<b[1];
    }
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        sort(courses.begin(),courses.end(),cmp);
        // for(auto e: c){
        //     cout<<e[0]<<" "<<e[1]<<endl;
        // }
        priority_queue<int> pq;  //build a max heap
        int sum=0;
        int n=courses.size();
        for(int i=0;i<n;i++){
            pq.push(courses[i][0]);  
            //push duration of course in max heap and add it to the sum
            sum+=courses[i][0];

            if(sum>courses[i][1]){  //if at any instance, sum becomes greater than last day for a particula course, then pop and subtract it's duration from the sum
                sum=sum-pq.top();
                pq.pop();
            }
        }
        return pq.size();  //return pq.size
    }
};
// 200,100
// 1250,1000
// 1300,200
// 3200,2000
    
// 0
// 0+100
// 100 +1000
// 1100+200
