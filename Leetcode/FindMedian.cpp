class MedianFinder {
public:

    priority_queue<int> maxHeap;
    priority_queue<int,std::vector<int>,std::greater<int> > minHeap; 
    
    void addNum(int num) {
        if(maxHeap.empty() || (maxHeap.top() > num ) ) maxHeap.push(num);
        else minHeap.push(num);

        if(maxHeap.size() > minHeap.size() + 1){
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        } 
        else if(maxHeap.size() + 1 < minHeap.size()){
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
    }
    
    double findMedian() {
        if(maxHeap.size() == minHeap.size()){
            if(maxHeap.empty())
                return 0;
            else{
                return (double)(maxHeap.top() + minHeap.top()) / 2;
            }
        }
        else{
            if(maxHeap.size() > minHeap.size()) return maxHeap.top();
            else return minHeap.top();
        }
     
        }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */