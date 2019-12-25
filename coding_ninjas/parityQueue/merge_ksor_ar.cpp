#include <queue>
vector<int> mergeKSortedArrays(vector<vector<int>*> input){
    /* Don't write main().
     * Don't read input, it is passed as function argument.
     * Return the output.
     * Taking input and printing output is handled automatically.
     */
     int k = input.size();
    priority_queue<int,vector<int>,greater<int>> pq;
           
    for(int i=0;i<k;i++)
    {
       std::vector<int> temp = *input[i];   
       for(int j=0;j<temp.size();j++)
       {
           pq.push(temp[j]);
           
       }
    }
    std::vector<int> vv;
    int yy = pq.size();
    for(int i=0;i<yy;i++)
    {
        vv.push_back(pq.top());
        pq.pop();
    }
    return vv;
}
