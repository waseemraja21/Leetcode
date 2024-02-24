class MedianFinder {
public:
        //initialising two priority  queues one for that contains small elements and other contains large elements
        // for small elements i will create max heap bcz i need largest element from small elements
        priority_queue<int> pqs;                                //max heap
        
        // for large elements creating min heap bcz i nedd smallest element from large pool of elements
        priority_queue<int, vector<int>, greater<int>> pql;     //min heap
    
    MedianFinder() {
   
    }
    
    void addNum(int num) {
        
        pqs.push(num);
        
        // checking if top element in smaller elements is greater than top(i.e; smallest) element in large elements
        if(!pqs.empty() && !pql.empty() && pqs.top() > pql.top()){
            int val = pqs.top();
            pqs.pop();
            
            pql.push(val);
        }
        
        // checking if diff of size is greater than one bcz in case of odd
        
        if(pqs.size() > pql.size()+1){
            pql.push(pqs.top());
            pqs.pop();
        }else if(pql.size() > pqs.size()+1){
            pqs.push(pql.top());
            pql.pop();
        }
    }
    
    double findMedian() {
        double ans = 0;
        if(pqs.size() > pql.size()){
            ans = pqs.top();
        }else if(pql.size() > pqs.size()){
            ans = pql.top();
        }else{
            ans = (pqs.top()+pql.top())/2.0;
        }
        return ans;
        
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */