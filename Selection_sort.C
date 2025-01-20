// 5th sem ADA program
//selection sort
#include<stdio.h>

int mi(int a[],int k,int n)
{
 int j,loc,min;
 min=a[k];
 loc=k;
 for(j=k+1;j<n;j++)
 {
  if(min>a[j])
  {
   min=a[j];
   loc=j;
  }
 }

return loc;
}

void main()
{
 int i,k,temp,loc,arr[100],n;
 clrscr();

 printf("Enter number of elements :");
 scanf("%d",&n);
 printf("Enter %d number of elements : ",n);
 for(i=0;i<n;i++)
  scanf("%d",&arr[i]);

 for(k=0;k<n;k++)
 {
   loc=mi(arr,k,n);
   temp=arr[k];
   arr[k]=arr[loc];
   arr[loc]=temp;


 }

 printf("Sorted array : ");
 for(i=0;i<n;i++)
  printf("%d ",arr[i]);

getch();
}