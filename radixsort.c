#include <stdio.h> 

int Max(int arr[], int n) 

{ 

int max = arr[0]; 

for (int i = 1; i < n; i++) 

if (arr[i] > max) 

max = arr[i]; 

return max; 

} 

 

void countSort(int a[], int n, int pos) 

{ 

 

int b[n]; 

int i, count[10] = { 0 }; 

 

for (i = 0; i < n; i++) 

count[(a[i]/pos) % 10]++; 

for (i = 1; i < 10; i++) 

count[i]+=count[i - 1]; 

for (i = n - 1;i >= 0; i--) { 

b[count[(a[i]/pos) % 10] - 1] = a[i]; 

count[(a[i]/pos) % 10]--; 

} 

for (i = 0; i < n; i++) 

a[i]= b[i]; 

} 

 

void radixsort(int arr[], int n) 

{ 

int m = Max(arr, n); 

 

for (int pos = 1; m /pos > 0; pos *= 10) 

countSort(arr, n,pos); 

} 

void print(int arr[], int n) 

{ 

for (int i = 0; i < n; i++) 

printf("%d ", arr[i]); 

} 

 

int main() 

{ 

int arr[] = { 136,487,358,469,570,247,598,639,205,609 }; 

int n = sizeof(arr) / sizeof(arr[0]); 

radixsort(arr, n); 

print(arr, n); 

return 0; 

} 