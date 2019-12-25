#include<queue>
using namespace std;
int kthLargest(vector<int> arr, int n, int k){
//create min-heap
priority_queue<int, vector<int>, greater<int> > pq;
//Insert first k elements into the heap
for(int i = 0; i < k; i++){
pq.push(arr[i]);
}
//check for the remaining elements if they greater than the root of heap
for(int i = k; i < n; i++){
if(arr[i] > pq.top()){
pq.pop();
pq.push(arr[i]);
}
}
return pq.top();
}
