#include <vector>
class ProirityQueue
{
  vector<int> pq;
  public:
  ParityQueue()
  {
    
  }
  bool isEmpty()
  {
     return pq.size()==0;
  }
  int getSize()
  {
    return pq.size();
  }
  int getMin()
  {
      if(isEmpty())
      {
         return 0;  // Priority Queue is empty.
      } 
      return pq[0];
  }
  int removeMIn()
  {
     
      // Complete this function
        if(isEmpty())
        return 0; // PQ is empty
     int ans = pq[0]; 
     pq[0] = pq[pq.size()-1];
     pq.pop_back();
     // doem - heapipy
      int pI=0; //parent Index
      int cI1 = 2*pI + 1;
      int cI2 = 2*pI + 2;
      int minI = 0;
     while( cI1 < pq.size() )
     {
        
        if( pq[minI] > pq[cI1])
           minI = cI1;
        if(cI2 < pq.size() && pq[minI] > pq[cI2])
           minI = cI2;   
        if(minI==pI)
            break;
        int temp = pq[minI];
        pq[minI] = pq[pI];
        pq[pI] = temp;
        pI=minI; //parent Index
        cI1 = 2*pI + 1;
        cI2 = 2*pI + 2;
     }
     return ans;
  }
  void insert(int element)
  {
     pq.push_back();
     int childIndex = pq.size() - 1;
     while(childIndex > 0)
     {
        int parentIndex = (childIndex - 1) / 2;
        if(pq[childIndex] < pq[parentIndex])
        {
            int temp = pq[childIndex];
            pq[childIndex] = pq[parentIndex];
            pq[parentIndex] = temp;
        }
        else
          break;
        childIndex = parentIndex;
     }
  }
}; 
