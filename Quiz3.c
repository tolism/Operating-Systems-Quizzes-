// Sort Lists using Fork
void sortAllListsFork( int **numbers , int nList , int nElem){
  for(int i=0;i<nList;i++)
      {
          if(fork() == 0)
          {
            char str[] = "binary-";
            qsort(numbers[i] , nElem ,sizeof(int) , cmpfunc);
            char ch = i+'0';
            strncat(str, &ch, 1);
            writeBinary(str , numbers[i] , nElem);
              exit(0);
          }
      }
      for(int i=0;i<nList;i++){ 
      wait(NULL);
    }

  return;
}