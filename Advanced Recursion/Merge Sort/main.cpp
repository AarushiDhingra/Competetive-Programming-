#include <iostream>
using namespace std;
/*
Merge Sort Code
Send Feedback
Sort an array A using Merge Sort.
Change in the input array itself. So no need to return or print anything.
Input format :
Line 1 : Integer n i.e. Array size
Line 2 : Array elements (separated by space)
Output format :
Array elements in increasing order (separated by space)
Constraints :
1 <= n <= 1000
Sample Input:
6 
2 6 8 5 4 3
Sample Output:
2 3 4 5 6 8
*/
void merge(int a[],int start,int mid,int end)
{
    int n1 = mid-start+1;
    int n2 = end-mid;
    int L[n1];
    int R[n2];
    int k = start;
    
    for(int i=0;i<n1;i++)
    {
      L[i] = a[k];
      k++;
    }
    for(int j=0;j<n2;j++)
    {
        R[j] = a[k];
        k++;
    }
    int i=0;
    int j=0;
	k= start;
    while(i<n1 && j<n2)
    {   
        if(L[i]<R[j])
        {
        a[k] = L[i];
        i++;
        k++;
        }
        else{
        a[k] = R[j];
        j++;
        k++;
        }
    }
    while(i<n1)
    {
    a[k] = L[i];
        i++;
        k++;
    }
    while(j<n2)
    {
     a[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort2(int a[],int s, int e)
{
    int mid = (s+e)/2;
    if(s >= e)
    {
        return;
    }
    
    mergeSort2(a,s,mid);
    mergeSort2(a,mid+1,e);
    merge(a,s,mid,e);
}

void mergeSort(int input[], int size)
{
    mergeSort2(input,0,size-1);
}

int main() {
  int length;
  cin >> length;
  int* input = new int[length];
  for(int i=0; i < length; i++)
    cin >> input[i];
  mergeSort(input, length);
  for(int i = 0; i < length; i++) {
    cout << input[i] << " ";
  }
}