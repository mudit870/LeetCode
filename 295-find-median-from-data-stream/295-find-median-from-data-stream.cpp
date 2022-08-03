class MedianFinder {
public:
    priority_queue<int>maxi;
    priority_queue<int,vector<int>,greater<int>>mini;
    void addNum(int num) {
        mini.push(num);
        maxi.push(mini.top());
        mini.pop();
        if(maxi.size() > mini.size()){
            mini.push(maxi.top());
            maxi.pop();
        }
    }
    
    double findMedian() {
        bool flag=(mini.size()==maxi.size());
        if(flag){
            double temp1 = mini.top();
            double temp2 = maxi.top();
            return (temp1+temp2)/2;
        }else{
            return mini.top();
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */