typedef vector<int> vi; 
typedef vector<vi> vvi; 
  
/* For loop excluding end*/
#define FOR(i, b, c) for (int(i) = (b); (i) < (c); (i)++) 
/* For loop going till end*/
#define FORL(i, b, c) for (int(i) = (b); (i) <= (c); (i)++) 
/* For loop backward */
#define FORR(i, b, c) for (int(i) = (b); (i) >= (c); --(i)) 
/* Traverse collection */
#define TRAV(a, b) for (auto&(a) : (b)) 
/* Quick for loop */
#define REP(i, n) FOR(i, 0, n) 
/* general shortcut */
#define ALL(v) v.begin(), v.end() 
#define SIZE(v) static_cast<int>(v.size()) 
#define SORT(v) sort(ALL(v)) 
#define REVERSE(v) reverse(ALL(v)) 

class MedianFinder {
public:
    /* For elements less than our median we want to be able to get the biggest element*/
    priority_queue<int> maxHeap;
    priority_queue<int, vi, greater<>> minHeap;
    /** initialize your data structure here. */
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        auto median = this->findMedian();
        /* If number is bigger than our median then we add it to minHeap*/
        if(num>median){
            minHeap.push(num);
        }
        else{
            maxHeap.push(num);
        }
        /*min heap should be at most one element smaller than max heap*/
        if(SIZE(minHeap)+1 <SIZE(maxHeap)){
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        }
        else if(SIZE(maxHeap)< SIZE(minHeap)){
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
    }
    
    double findMedian() {
        if(maxHeap.empty()) return 100000.0;
        if(SIZE(maxHeap)> SIZE(minHeap)) return maxHeap.top();
        double num1=minHeap.top();
        double num2=maxHeap.top();
        return (num1 + num2)/2.0;

    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */