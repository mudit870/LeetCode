class Solution {
public:
    int slidingPuzzle(vector<vector<int>>& board) {
        string target="123450";
        string initial="";
        for(int i=0;i<2;i++){
            for(int j=0;j<3;j++){
                initial+=to_string(board[i][j]);
            }
        }
        //converted the grid into string and noe we put the vector at ith index through which it can swap, i.e. if 0 is at index 1 then it can swap with index 0 or 2 or 4, same for other index
        vector<vector<int>>swapIdx={{1,3},{0,2,4},{1,5},{0,4},{1,3,5},{2,4}};
        queue<string>que;
        que.push(initial);
        int ans=0;
        set<string>checkVisited;//if already present in set then it is visited
        while(!que.empty()){
            int size=que.size();
            while(size--){
                string temp=que.front();
                que.pop();
                if(temp==target)return ans;
                int idx=0;
                for(int i=0;i<temp.length();i++){
                    if(temp[i]=='0'){
                        idx=i; //we get index of 0, now traverse in 2d given array
                        break;
                    }
                }
                vector<int>swapVector=swapIdx[idx];
                for(int i=0;i<swapVector.size();i++){
                    //swap characters of string
                    string s=temp;
                    swap(s[idx],s[swapVector[i]]);
                    if(checkVisited.find(s)!=checkVisited.end())
                        continue;
                    que.push(s);
                    checkVisited.insert(s);
                }
            }
            ans++;
        }
        return -1;
    }
};