bool checkMaxHeap(int v[], int n)
 {
    /* Don't write main().
     * Don't read input, it is passed as function argument.
     * Taking input and printing output is handled automatically.
     */
     
      int cI = n-1;
       
       
       while(cI > 0)
       {
          int pI = (cI-1)/2;   
          if(v[pI] < v[cI])
          {
            return 0;
          }
          
          cI = pI;
       } 
    return true;
}

