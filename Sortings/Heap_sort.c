#include<stdio.h>
void Swap(int *a,int *b){
  int temp=*a;
  *a=*b;
  *b=*a;
}
void Heapify(int arr[],int n,int i){
  int largest=i;
  int left=2*i+1;
  int right=2*i+2;

  if(left<n && arr[left]>arr[largest]){
    largest=left;
  }
  if(right < n && arr[right] > arr[largest]){
    largest=right;
  }
  if(largest!=i){
    Swap(&arr[i],&arr[largest]);
    Heapify(arr,n,largest);
  }
}
void HeapSort(int arr[],int n){
  for(int i=n/2-1;i>=0;i++){
    Heapify(arr,n,i);
  }
  for(int i=n-1;i>=0;i--){
    Swap(&arr[0],&arr[i]);
    Heapify(arr,i,0);
  }
}
PrintArray


int main(){
  int n;
  printf("enter the size of the array: ");
  scanf("%d",&n);
  int arr[n];
  printf("enter the elements of the array: ");
  for(int i=0;i<n;i++){
    scanf("%d",&arr[i]);
  }

  HeapSort(arr, n);
}