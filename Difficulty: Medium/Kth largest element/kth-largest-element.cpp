class Solution {
  public:
    // Function to return kth largest element from an array.
    int KthLargest(vector<int> &arr, int k) {
        // Your code here
        priority_queue<int,vector<int>,greater<>> pq;
        for(int i:arr){
            pq.push(i);
            
            if(pq.size()>k) pq.pop();
        }
        return pq.top();
    }
    
};