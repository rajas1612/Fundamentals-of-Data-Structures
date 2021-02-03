#include <stdio.h>
int binarySearch(int array[], int start_index, int end_index, int element){
   while (start_index <= end_index){
      int middle = start_index + (end_index- start_index )/2;
      if (array[middle] == element)
         return middle;
      if (array[middle] < element)
         start_index = middle + 1;
      else
         end_index = middle - 1;
   }
   return -1;
}
int main(){
   int n,element;
   int array[100];
   scanf("%d",&n);
   for(int i=0;i<n;i++){
      scanf("%d",&array[i]);
   }
   scanf("%d",&element);
   for(int i=0;i<n;i++){
      for(int j=i+1;j<n;j++){
         if(array[i]>array[j]){
            temp=array[i];
            array[i]=array[j];
            array[j]=temp;
         }
      }
   }
   int result = binarySearch(array, 0, n-1, element);
   if(result == -1 ) {
      printf("Element not found");
   }
   else {
      printf("Element found at index : %d",result);
   }
   return 0;
}