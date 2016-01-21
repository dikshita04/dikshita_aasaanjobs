# include <stdio.h>
# include <math.h>
# include <limits.h>
 
void sort(int *, int, int);
 
void minsum(int arr[], int n)
{
  int sum, min_sum = INT_MAX;
 
  int l = 0, r = n-1;
 
  int min_l = l, min_r = n-1;
 
  if(n < 2)
  {
    printf("Invalid Input");
    return;
  }
 
  sort(arr, l, r);
 
  while(l < r)
  {
    sum = arr[l] + arr[r];
 
    if(abs(sum) < abs(min_sum))
    {
      min_sum = sum;
      min_l = l;
      min_r = r;
    }
    if(sum < 0)
      l++;
    else
      r--;
  }
 
  printf(" The two elements are %d and %d",
          arr[min_l], arr[min_r]);
}
 
int main()
{
  int arr[] = {1,10,20,-15,-11,5};
  int n = sizeof(arr)/sizeof(arr[0]);
  minsum(arr, n);
  getchar();
  return 0;
}
 
void exchange(int *a, int *b)
{
  int temp;
  temp = *a;
  *a   = *b;
  *b   = temp;
}
 
int partition(int arr[], int si, int ei)
{
  int x = arr[ei];
  int i = (si - 1);
  int j;
 
  for (j = si; j <= ei - 1; j++)
  {
    if(arr[j] <= x)
    {
      i++;
      exchange(&arr[i], &arr[j]);
    }
  }
 
  exchange (&arr[i + 1], &arr[ei]);
  return (i + 1);
}
 

void sort(int arr[], int si, int ei)
{
  int pi;    
  if(si < ei)
  {
    pi = partition(arr, si, ei);
    sort(arr, si, pi - 1);
    sort(arr, pi + 1, ei);
  }
}
